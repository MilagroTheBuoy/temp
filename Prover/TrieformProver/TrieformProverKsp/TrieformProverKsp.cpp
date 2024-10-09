#include "TrieformProverKsp.h"

shared_ptr<Trieform> TrieformFactory::makeTrieKsp(
    const shared_ptr<Formula> &formula, shared_ptr<Trieform> trieParent) {
    shared_ptr<Trieform> trie = shared_ptr<Trieform>(new TrieformProverKsp());
    trie->initialise(formula, trieParent);
    return trie;
}
shared_ptr<Trieform> TrieformFactory::makeTrieKsp(
    const shared_ptr<Formula> &formula, const vector<int> &newModality,
    shared_ptr<Trieform> trieParent) {
    shared_ptr<Trieform> trie = shared_ptr<Trieform>(new TrieformProverKsp());
    trie->initialise(formula, newModality, trieParent);
    return trie;
}
shared_ptr<Trieform> TrieformFactory::makeTrieKsp(
    const vector<int> &newModality, shared_ptr<Trieform> trieParent) {
    shared_ptr<Trieform> trie = shared_ptr<Trieform>(new TrieformProverKsp());
    trie->initialise(newModality, trieParent);
    return trie;
}

TrieformProverKsp::TrieformProverKsp() {}
TrieformProverKsp::~TrieformProverKsp() {}

shared_ptr<Trieform> TrieformProverKsp::create(
    const shared_ptr<Formula> &formula) {
    return TrieformFactory::makeTrieKsp(formula, shared_from_this());
}
shared_ptr<Trieform> TrieformProverKsp::create(const shared_ptr<Formula> &formula,
                                             const vector<int> &newModality) {
    return TrieformFactory::makeTrieKsp(formula, newModality, shared_from_this());
}
shared_ptr<Trieform> TrieformProverKsp::create(const vector<int> &newModality) {
    shared_ptr<Trieform> test = shared_from_this();
    return TrieformFactory::makeTrieKsp(newModality, shared_from_this());
}


Solution TrieformProverKsp::prove(literal_set assumptions) {
    cout << "USING KSP SAT" << endl;
    cout << "HI: " << endl;
    cout << toKspString() << endl;
    return prove(0, assumptions);
}

Solution TrieformProverKsp::prove(int depth, literal_set assumptions) {
    // Check solution memo
    shared_ptr<Bitset> assumptionsBitset;
    shared_ptr<Bitset> fullAssumptionsBitset;
    LocalSolutionMemoResult memoResult;
    Solution solution;
    literal_set currentModel;
    modal_literal_map triggeredDiamonds;
    modal_literal_map triggeredBoxes;

    assumptionsBitset = isExact ? nullptr : convertAssumptionsToBitset(assumptions);

    memoResult =
        isExact ? exactMemo.getFromMemo(assumptions) : localMemo.getFromMemo(assumptionsBitset);

    if (memoResult.inSatMemo) {
        return memoResult.result;
    }
    
    restart:

    // Solve locally
    solution = prover->solve(assumptions);

    if (!solution.satisfiable) {
        // prover->reduce_conflict(solution.conflict);
        updateSolutionMemo(assumptions, assumptionsBitset, solution);
        return solution;
    }
    
    currentModel = prover->getModel();
    

    prover->calculateTriggeredDiamondsClauses();
    triggeredDiamonds = prover->getTriggeredDiamondClauses();
    prover->calculateTriggeredBoxClauses();
    triggeredBoxes = prover->getTriggeredBoxClauses();

    for (auto modalitySubtrie : subtrieMap) {
        // Handle each modality
        if (triggeredDiamonds[modalitySubtrie.first].size() == 0) {
            // If there are no triggered diamonds of a certain modality we can
            // skip it
            continue;
        }

        Solution childSolution;
        TrieformProverKsp *childNode =
            dynamic_cast<TrieformProverKsp *>(modalitySubtrie.second.get());

        // The fired diamonds are not a subset of the fired boxes, we need to
        // create one world for each diamond clause
        bool diamondFailed = false;

        diamond_queue diamondPriority = prover->getPrioritisedTriggeredDiamonds(
            modalitySubtrie.first, triggeredBoxes[modalitySubtrie.first],
            triggeredDiamonds[modalitySubtrie.first]);

        while (!diamondPriority.empty()) {
            // Create a world for each diamond
            Literal diamond = diamondPriority.top().literal;
            diamondPriority.pop();

            literal_set childAssumptions =
                literal_set(triggeredBoxes[modalitySubtrie.first]);
            childAssumptions.insert(diamond);

            // Run the solver for the next level
            childSolution = childNode->prove(depth + 1, childAssumptions);

            // Clause propagation
            bool shouldRestart = false;
            /*
            for (literal_set learnClause :
            prover->getClauses(modalitySubtrie.first,
            prover->negatedClauses(prover->filterPropagatedConflicts(childNode->allConflicts)))) { 
                allConflicts.push_back(learnClause);
                prover->addClause(learnClause);
            }
            */
            childNode->allConflicts.clear();

            if (shouldRestart) {
                return prove(assumptions);
            }

            // If it is satisfiable create the next world
            if (childSolution.satisfiable) {
                // Don't check any more if we only required one
                if (isSubsetOf(triggeredDiamonds[modalitySubtrie.first],
                               triggeredBoxes[modalitySubtrie.first]))
                    break;
                else
                    continue;
            }
            //prover->updateLastFail(diamond);
            diamondFailed = true;
            break;
        }

        if (!diamondFailed) continue;

        for (literal_set learnClause : prover->getClauses(
                 modalitySubtrie.first, childSolution.conflict)) {
            allConflicts.push_back(learnClause);
            //cout << "Learn: ";
            //for (auto x : learnClause) cout << x.toString() << " ";
            //cout << endl;
            prover->addClause(learnClause);
        }
        goto restart;
        //return prove(depth, assumptions);
    }
    
    // If we reached here the solution is satisfiable under all modalities
    if (!isExact) fullAssumptionsBitset = fleshedOutAssumptionBitset(currentModel);
    updateSolutionMemo(assumptions, fullAssumptionsBitset, solution);

    //cout << "Solve: " << depth << " = " << litsetString(assumptions) << endl;

    return solution;
}
