#include "Prover.h"

Prover::Prover() {}
Prover::~Prover() {}

unordered_map<Literal, Literal, LiteralHash, LiteralEqual> Prover::eventualityToLit = {};

unordered_map<Literal, Literal, LiteralHash, LiteralEqual> Prover::litToEventuality = {};

void Prover::createModalImplication(int modality, Literal left, Literal right,
        modal_lit_implication &modalLits,
        modal_lit_implication &modalFromRight) {
    modalLits[modality][left].insert(right);
    modalFromRight[modality][right].insert(left);
}

void Prover::createLtlImplication(literal_set left, Literal right, 
        ltl_implications &ltl_imps, bool succInSat) {
    ltl_imps[right].push_back(left);
    if (succInSat) {
        literal_set newClause;
        for (auto literal : left) {
            newClause.insert(~Literal(literal.getName() + "'", literal.getPolarity()));
        }
        newClause.insert(right);
        addClause(newClause);
    }
}

string Prover::getPrimitiveName(shared_ptr<Formula> formula) {
    if (formula->getType() == FAtom) {
        return dynamic_cast<Atom *>(formula.get())->getName();
    } else if (formula->getType() == FNot) {
        return dynamic_cast<Atom *>(
                dynamic_cast<Not *>(formula.get())->getSubformula().get())
            ->getName();
    }
    throw invalid_argument("Expected Atom or Not but got " + formula->toString());
}

Literal Prover::toLiteral(shared_ptr<Formula> formula) {
    if (formula->getType() == FAtom) {
        return Literal(dynamic_cast<Atom *>(formula.get())->getName(), true);
    } else if (formula->getType() == FNot) {
        return Literal(
                dynamic_cast<Atom *>(
                    dynamic_cast<Not *>(formula.get())->getSubformula().get())
                ->getName(),
                false);
    }
    throw invalid_argument("Expected Atom or Not but got " + formula->toString());
}

void Prover::calculateTriggeredModalClauses(modal_lit_implication &modalLits,
        modal_literal_map &triggered) {
    triggered.clear();
    for (auto modalityLitImplication : modalLits) {
        for (auto literalImplication : modalityLitImplication.second) {
            if (modelSatisfiesAssump(literalImplication.first)) {
                triggered[modalityLitImplication.first].insert(
                        literalImplication.second.begin(), literalImplication.second.end());
            }
        }
    }
}

void Prover::calculateTriggeredModalClauses(modal_lit_implication &modalLits,
        modal_literal_map &triggered, literal_set& model) {
    triggered.clear();
    for (auto modalityLitImplication : modalLits) {
        for (auto literalImplication : modalityLitImplication.second) {
            if (model.find(literalImplication.first) != model.end()) {
                triggered[modalityLitImplication.first].insert(
                        literalImplication.second.begin(), literalImplication.second.end());
            }
        }
    }
}

void Prover::calculateTriggeredLtlClauses(ltl_implications &ltlImplications,
        literal_set &triggered) {
    for (auto ltlImplication : ltlImplications) {
        for (auto clause : ltlImplication.second) {
            if (modelSatisfiesAssumps(clause)) {
                triggered.insert(ltlImplication.first);
            }
        }
    }
}

string clauseToString(literal_set clause) {
    string result = "";
    for (auto literal : clause) {
        result += literal.toString() + " ";
    }
    return result;
}


void Prover::makeLtlTail(LtlFormulaTriple& formulaTriple) {
    //cout << "STAGE 1" << endl;
    Literal tail("tail", true);
    addClause({tail});
    //cout << "STAGE 2" << endl;
    /*

    Literal L ("$loop", true);
    Literal Ls ("$loop_start", true);
    Literal seen_Ls("seen($loop_start)", true);
    addClause({~tail, L});
    addClause({~tail, ~Ls}); 
    addClause({~tail, seen_Ls}); 
    //cout << "STAGE 3" << endl;
    // choose(p) -> p
    //cout << "STAGE 1" << endl;
    literal_set universe = formulaTriple.getUniverse();
    for (auto& poslit : universe) {
        if (poslit == Ls) continue;
        if (poslit == L) continue;
        if (poslit.getName().substr(0, 4) == "tail") continue;
        if (poslit.getName().substr(0, 6) == "$false") continue;
        if (poslit.getName().substr(0, 9) == "$combine_") continue;
        if (poslit.getName().substr(0, 5) == "seen(") continue;
        if (poslit.getName().substr(0, 7) == "choose(") continue;
        if (poslit.getName().substr(0, 2) == "$E") continue;
        if (poslit.getName().substr(0, 2) == "$x") continue;
        if (poslit.getName().substr(0, 2) == "$d") continue;
        if (poslit.getName().substr(0, 3) == "ex$") continue;
        Literal choose ("choose(" + poslit.toString() + ")", true);
        //cout << "ADDTAIL: " << litsetString({~choose, lit}) << endl;
        addClause({~tail, ~choose, poslit});
        addClause({~tail, choose, ~poslit});
    }
    //cout << "STAGE 4" << endl;
    //cout << "STAGE 2" << endl;

    for (auto ltlEventualityImplication : ltlEventualityImplications) {
        auto& event = ltlEventualityImplication.first;
        //if (event.getName() == "$E$loop_start") {
            //cout << "ADD SPECIAL: " << litsetString({~event}) << endl;
            //addClause({~event});
            //continue;
        //}
        Literal orig = *ltlEventualityImplication.second[0].begin();
        Literal seen ("seen(" + (~orig).toString() + ")", true);
        literal_set clause =  {~tail, ~event, seen};
        //cout << "ADDTAIL: " << litsetString(clause) << endl;
        addClause(clause);
    }
    */
}

void Prover::makeLtlfTail() {
    Literal tail = Literal("tail", true);

    addClause({tail});

    for (auto eventuality : eventualityToLit) {
        //cout << clauseToString({~eventuality.first, eventuality.second}) << endl;
        addClause({~tail, ~eventuality.first, eventuality.second});
    }
    // All eventualities that will be triggered all also fulfilled
    //cout << "All eventualities that will be triggered are also fulfilled" << endl;
    //cout << "TAIL CLAUSE" << endl;
    for (auto ltlEventualityImplication : ltlEventualityImplications) {
        for (auto clause : negatedClauses(ltlEventualityImplication.second)) {
            //cout << clauseToString(clause) << endl;
            clause.insert(~tail);
            addClause(clause);
        }
    }


    for (auto ltlStepClause : ltlStepImplications) {
        if (ltlStepClause.first == Literal("$false", true)) continue;
        for (auto clause : negatedClauses(ltlStepClause.second)) {
            //if ((clause.size() == 1) && (boxSteps.find(*clause.begin()) != boxSteps.end())) continue;
            //cout << clauseToString(clause) << endl;
            clause.insert(~tail);
            addClause(clause);
        }
    }

}

pair<literal_set, literal_set> Prover::getLtlSuccessorAssumps(
        literal_set eventualities) {
    literal_set currentModel = getModel();
    literal_set stepTriggered;
    calculateTriggeredLtlClauses(ltlStepImplications, stepTriggered);
    calculateTriggeredLtlClauses(ltlEventualityImplications, eventualities);
    // remove fulfilled eventualities
   

    std::vector<Literal> elementsToRemove;
    for (const auto& eventuality : eventualities) {
        if (currentModel.find(eventualityToLit.at(eventuality)) != currentModel.end()) {
            elementsToRemove.push_back(eventuality);
        }
    }
    
    for (const auto& element : elementsToRemove) {
        eventualities.erase(element);
    }

    return make_pair(stepTriggered, eventualities);
}

bool Prover::modelSatisfiesAssumps(literal_set assumptions) {
    for (Literal assump : assumptions) {
        if (!modelSatisfiesAssump(assump)) {
            return false;
        }
    }
    return true;
}
modal_literal_map
Prover::getTriggeredModalClauses(modal_lit_implication &modalLits) {
    modal_literal_map triggered;
    for (auto modalityLitImplication : modalLits) {
        cout << "Checking modality " << modalityLitImplication.first << endl;
        for (auto literalImplication : modalityLitImplication.second) {
            cout << "Checking " << literalImplication.first.toString() << " -> " << (*literalImplication.second.begin()).toString() << endl;
            if (modelSatisfiesAssump(literalImplication.first)) {
                triggered[modalityLitImplication.first].insert(
                        literalImplication.second.begin(), literalImplication.second.end());
            }
        }
    }
    return triggered;
}

void Prover::calculateTriggeredBoxClauses() {
    calculateTriggeredModalClauses(boxLits, triggeredBoxes);
}

void Prover::calculateTriggeredDiamondsClauses() {
    calculateTriggeredModalClauses(diamondLits, triggeredDiamonds);
}


void Prover::calculateTriggeredBoxClauses(literal_set& model) {
    calculateTriggeredModalClauses(boxLits, triggeredBoxes);
}

void Prover::calculateTriggeredDiamondsClauses(literal_set& model) {
    calculateTriggeredModalClauses(diamondLits, triggeredDiamonds);
}

modal_literal_map Prover::getTriggeredBoxClauses() { return triggeredBoxes; }
modal_literal_map Prover::getTriggeredDiamondClauses() {
    return triggeredDiamonds;
}
literal_set Prover::getNotAllDiamondLeft(int modality) {
    literal_set notAllDiamondLeft;
    for (auto literalImplication : diamondLits[modality]) {
        notAllDiamondLeft.insert(~literalImplication.first);
    }
    return notAllDiamondLeft;
}


literal_set Prover::rememberTriggeredImplications() {
    // Required for Tense where we might reuse SAT solvers inbetween calculating the conflict
    literal_set triggeredImplications;
    for (auto x : boxLits) {
        for (auto literalImplication : x.second) {
            if (modelSatisfiesAssump(literalImplication.first)) {
                triggeredImplications.insert(literalImplication.first);
            }
        }
    }
    for (auto x : diamondLits) {
        for (auto literalImplication : x.second) {
            if (modelSatisfiesAssump(literalImplication.first)) {
                triggeredImplications.insert(literalImplication.first);
            }
        }
    }
    return triggeredImplications;
}

vector<literal_set> Prover::getNotProblemBoxClauses(int modality,
        literal_set conflicts, literal_set& triggeredImplications) {
    vector<literal_set> notProblemBoxClauses;
    for (Literal conflict : conflicts) {
        literal_set problemLeft;
        for (auto literalImplication : boxLits[modality]) {
            if ((triggeredImplications.find(literalImplication.first) != triggeredImplications.end()) &&
                    (literalImplication.second.find(conflict) !=
                     literalImplication.second.end())) {
                problemLeft.insert(~literalImplication.first);
            }
        }
        if (problemLeft.size() > 0) {
            notProblemBoxClauses.push_back(problemLeft);
        }
    }
    return notProblemBoxClauses;
};
vector<literal_set> Prover::getNotProblemBoxClauses(int modality,
        literal_set conflicts) {
    vector<literal_set> notProblemBoxClauses;
    for (Literal conflict : conflicts) {
        literal_set problemLeft;
        for (auto literalImplication : boxLits[modality]) {
            if (modelSatisfiesAssump(literalImplication.first) &&
                    literalImplication.second.find(conflict) !=
                    literalImplication.second.end()) {
                problemLeft.insert(~literalImplication.first);
            }
        }
        if (problemLeft.size() > 0) {
            notProblemBoxClauses.push_back(problemLeft);
        }
    }
    return notProblemBoxClauses;
};

literal_set Prover::getNotDiamondLeft(int modality, Literal diamond, literal_set& triggeredImplications) {
    literal_set notDiamondLeft;
    for (auto literalImplication : diamondLits[modality]) {
        if ((triggeredImplications.find(literalImplication.first) != triggeredImplications.end()) &&
                (literalImplication.second.find(diamond) !=
                 literalImplication.second.end())) {
            notDiamondLeft.insert(~literalImplication.first);
        }
    }
    return notDiamondLeft;
}
literal_set Prover::getNotDiamondLeft(int modality, Literal diamond) {
    literal_set notDiamondLeft;
    for (auto literalImplication : diamondLits[modality]) {
        if (modelSatisfiesAssump(literalImplication.first) &&
                literalImplication.second.find(diamond) !=
                literalImplication.second.end()) {
            notDiamondLeft.insert(~literalImplication.first);
        }
    }
    return notDiamondLeft;
}

void Prover::updateLastFail(Literal clause) {lastFail[clause]=++failCount;}
void Prover::addToFail(Literal clause, int delta) {lastFail[clause]+=delta;}// = ++failCount; }

diamond_queue Prover::getPrioritisedTriggeredDiamonds(int modality) {
    // Note MUST avoid box clauses
    diamond_queue prioritisedTriggeredDiamonds;
    literal_set triggeredBoxes = getTriggeredBoxClauses()[modality];
    literal_set triggeredDiamonds = getTriggeredDiamondClauses()[modality];
    for (Literal diamond : triggeredDiamonds) {
        if (triggeredBoxes.find(diamond) == triggeredBoxes.end()) {
            prioritisedTriggeredDiamonds.push({diamond, lastFail[diamond]});
        }
    }

    // If we have no triggered diamonds, we are in D \subset B case
    // We create one world
    if (prioritisedTriggeredDiamonds.size() == 0) {
        Literal diamond = *triggeredDiamonds.begin();
        prioritisedTriggeredDiamonds.push({diamond, lastFail[diamond]});
    }

    return prioritisedTriggeredDiamonds;
}


diamond_queue Prover::getPrioritisedTriggeredDiamonds(int modality, literal_set& triggeredBoxes, literal_set& triggeredDiamonds) {
    // Note MUST avoid box clauses
    diamond_queue prioritisedTriggeredDiamonds;
    for (Literal diamond : triggeredDiamonds) {
        if (triggeredBoxes.find(diamond) == triggeredBoxes.end()) {
            prioritisedTriggeredDiamonds.push({diamond, lastFail[diamond]});
        }
    }
    // If we have no triggered diamonds, we are in D \subset B case
    // We create one world
    if (prioritisedTriggeredDiamonds.size() == 0) {
        Literal diamond = *triggeredDiamonds.begin();
        prioritisedTriggeredDiamonds.push({diamond, lastFail[diamond]});
    }
    return prioritisedTriggeredDiamonds;
}


vector<literal_set> Prover::createConflictGroups(int modality, literal_set nextModalContextConflict) {
    vector<literal_set> conflictGroups;
    for (auto lit : nextModalContextConflict) {
        literal_set currentGroup;
        if (boxFromRight[modality].find(lit) != boxFromRight[modality].end()) {
            currentGroup.insert(boxFromRight[modality][lit].begin(), boxFromRight[modality][lit].end());

        }

        if (diamondFromRight[modality].find(lit) != diamondFromRight[modality].end()) {
            currentGroup.insert(diamondFromRight[modality][lit].begin(), diamondFromRight[modality][lit].end());

        }
        if (currentGroup.size() == 0) {
            return {};
        } else {
            conflictGroups.push_back(currentGroup);
        }
    }
    return conflictGroups;
}

vector<literal_set>
Prover::generateClauses(vector<literal_set> literalCombinations) {
    vector<literal_set> clauses;
    if (literalCombinations.size() == 0) {
        return clauses;
    }
    literal_set levelLiterals = literalCombinations.back();

    if (literalCombinations.size() == 1) {
        for (Literal literal : levelLiterals) {
            literal_set single;
            single.insert(literal);
            clauses.push_back(single);
        }
        return clauses;
    }

    literalCombinations.pop_back();
    vector<literal_set> futureClauses = generateClauses(literalCombinations);
    for (Literal literal : levelLiterals) {
        for (literal_set futureClause : futureClauses) {
            literal_set copy = literal_set(futureClause);
            copy.insert(literal);
            clauses.push_back(copy);
        }
    }
    return clauses;
}

vector<literal_set> Prover::canTriggerLtlLiteral(Literal lit) {
    // Used for learning a reason
    vector<literal_set> ans;
    if (ltlEventualityImplications.find(lit) != ltlEventualityImplications.end()) {
        for (literal_set trigger : ltlEventualityImplications[lit]) {
            ans.push_back(trigger);
        }
    }
    
    // if lit starts with E, then remove E
    //*
    bool flag = false;
    if (lit.getName().substr(0, 2) == "$E") {
        //cout << "BEFORE: " << lit.toString() << endl;
        lit = Literal(lit.getName().substr(2), true);
        // if name starts with $E~ then negate the literal
        if (lit.getName().substr(0, 1) == "~") {
            lit = Literal(lit.getName().substr(1), false);
        }
        flag = true;
        //cout << "AFTER: " << lit.toString() << endl;
    }

    if (ltlStepImplications.find(lit) != ltlStepImplications.end()) {
        for (literal_set trigger : ltlStepImplications[lit]) {
            ans.push_back(trigger);
        }
    }
    if (flag && ans.size() >= 2) {
        return {{Literal("ex$" + lit.toString(), true)}};

    }
    // TODO: FIX THIS!!
    return ans;
}

vector<literal_set> cartesianProduct(const vector<vector<literal_set>>& arr, size_t index = 0) {
    vector<literal_set> result;

    if (index == arr.size() - 1) {
        for (const literal_set& element : arr[index]) {
            result.push_back(element);
        }
        return result;
    }

    // Recursive case: combine the current vector with the next vectors
    vector<literal_set> subResult = cartesianProduct(arr, index + 1);
    for (const literal_set& element : arr[index]) {
        for (const literal_set& subElement : subResult) {
            // Combine the current element with each element from the sub-result
            literal_set combinedSet = element;
            combinedSet.insert(subElement.begin(), subElement.end());
            result.push_back(combinedSet);
        }
    }

    return result;
}

void Prover::createLtlSpecification(LtlFormulaTriple &clauses) {
    makeEventualitiesUnconditional(clauses);
    makeOneEventuality(clauses);
}

void Prover::makeEventualitiesUnconditional(LtlFormulaTriple &clauses) {
    // For every:
    //   [] (P => <> q)
    // Replace with:
    //   [] ((P & ~q) => waitForQ)          (1)
    //   [] (waitForQ => X (q | waitForQ))  (2)
    //   [] <> ~waitForQ                    (3)
    literal_set unconditionalEventualities;
    int counter = 0;
    for (auto clause : clauses.getEventualityClauses()) {
          string waitForName = "$waitFor(" + clause.right.toString() + ")";
          Literal waitFor = Literal(waitForName, true);

          // Clause 1
          literal_set newClause; 
          for (auto x : clause.left) newClause.insert(~x);
          newClause.insert(clause.right);
          clauses.addClause(newClause);

          // Clause 2
          Literal orQ = Literal("$x" + to_string(++counter), true);
          clauses.addStepClause({waitFor}, orQ);
          clauses.addClause({~orQ, clause.right, waitFor});

          // Clause 3
          clauses.addUnconditionalEventuality(~waitFor);
    }
}

void Prover::makeOneEventuality(LtlFormulaTriple &clauses) {
    // convert multiple [] <> Q_i into one eventuality [] <> m 
    // (m is master)
    // By introducing tracking variable
    //   Q_i | (~m & T_i) iff X T_i
    //      z => X T_i          (1)
    //      ~Q_i & y => X ~T_i  (2)
    //      z => Q_i | y        (3)
    //      ( y iff ~m & T_i)
    //      y => ~m             (4)
    //      y => T_i            (5)
    //      ~y | m | ~T_i       (6)
    //   m => T_i               (7)
    //   m => X ~T_i            (8)
    Literal master = Literal("$master", true);
    int counter = 0;
    for (auto eventuality : clauses.getUnconditionalEventualities()) {
        Literal z = Literal("$z" + to_string(++counter), true);
        Literal y = Literal("$y" + to_string(counter), true);
        Literal t = Literal("$track(" + eventuality.toString() + ")", true);
         
        clauses.addStepClause({z}, t); // 1
        clauses.addStepClause({~eventuality, y}, ~t); // 2
        clauses.addClause({~z, eventuality, y}); // 3
        clauses.addClause({~y, ~master}); // 4
        clauses.addClause({~y, t}); // 5
        clauses.addClause({~y, master, ~t}); // 6
        clauses.addClause({~master, t}); // 7
        clauses.addStepClause({master}, ~t); // 8
    }
    clauses.setUnconditionalEventualities({master});
}

vector<literal_set> Prover::createLtlReasons(literal_set conflict) {

    vector<vector<literal_set>> reasonForEachLiteral;
    for (Literal lit : conflict) {
        reasonForEachLiteral.push_back(canTriggerLtlLiteral(lit));
        /*
        cout << "Reason for " << lit.toString() << " is ";
        for (auto x : canTriggerLtlLiteral(lit)) {
            cout << "{";
            for (auto y : x) {
                cout << y.toString() << " ";
            }
            cout << "} ";
        }cout << endl;
        */
    }
    return negatedClauses(cartesianProduct(reasonForEachLiteral));
}

bool contains(literal_set &superset, literal_set &subset) {
    for (auto lit : subset) {
        if (superset.find(lit) == superset.end()) return false;
    }
    return true;
}

vector<literal_set> Prover::checkClauses(int modality, vector<literal_set> clauses, literal_set badClause) {
    // return clauses which only have one diamond
    // or if they have none, duplicate that clause with all diamonds
    vector<literal_set> validClauses;
    for (auto clause : clauses) {
        literal_set boxLiterals;
        literal_set diamondLiterals;
        for (auto literal : clause) {
            for (Literal boxLit : boxLits[modality][literal]) boxLiterals.insert(boxLit);
            for (Literal diamondLit : diamondLits[modality][literal]) diamondLiterals.insert(diamondLit);
        }
        //cout << "Box lits: ";
        //for (auto x: boxLiterals) cout << x.toString() << " "; cout << endl;
        //for (auto x: diamondLiterals) cout << x.toString() << " "; cout << endl;
        for (auto diamondLiteral : diamondLiterals) {
            if (boxLiterals.find(diamondLiteral) == boxLiterals.end()) {
                boxLiterals.insert(diamondLiteral);
                if (contains(boxLiterals, badClause)) {
                    validClauses.push_back(clause);
                    boxLiterals.erase(boxLiterals.find(diamondLiteral));
                    break;
                }
                boxLiterals.erase(boxLiterals.find(diamondLiteral));
            }
        }
        if (contains(boxLiterals, badClause)) {
            vector<literal_set> newCombination;
            for (Literal literal : clause) {
                literal_set single;
                single.insert(literal);
                newCombination.push_back(single);
            }

            //cout << "Creating ALL BAD BOX" << endl;
            literal_set diamonds;
            for (auto diamond : diamondLits[modality]) {
                if (diamond.second.empty()) continue;
                diamonds.insert(diamond.first);
                //cout << diamond.first.toString() << " ";
            }
            //cout << endl;
            newCombination.push_back(diamonds);
            if (!diamonds.empty()) for (auto clause : generateClauses(newCombination)) validClauses.push_back(clause);

        }
    }
    return validClauses;
}

vector<literal_set> Prover::filterPropagatedConflicts(vector<literal_set> clauses) {
    // Only propagate clauses with size 2 (otherwise it can blow up)
    vector<literal_set> result;
    for (literal_set clause : clauses) {
        if (clause.size() > 2) continue;
        result.push_back(clause);
    }
    return result;
}
vector<literal_set> Prover::negatedClauses(vector<literal_set> clauses) {
    vector<literal_set> result;
    for (literal_set clause : clauses) {
        literal_set negatedClause;
        for (Literal lit : clause) {
            negatedClause.insert(~lit);
        }
        result.push_back(negatedClause);
    }
    return result;
}

vector<literal_set> Prover::getClauses(int modality, literal_set conflict) {
    if (conflict.size() != 0) {
        return negatedClauses(checkClauses(modality, generateClauses(createConflictGroups(modality, conflict)), conflict));
    }else {
        vector<literal_set> clauses;
        for (auto x : diamondLits[modality]) {
            if (x.second.empty()) continue;
            literal_set litset;
            litset.insert(~x.first);
            //cout << (~x.first).toString() << " "; 
            clauses.push_back(litset);
        } //                                   cout << endl;
        return clauses;
    }
}

vector<literal_set> Prover::getClauses(int modality, vector<literal_set> conflicts) {
    vector<literal_set> result;
    for (auto conflict : conflicts) {
        auto newConflicts = getClauses(modality, conflict);
        result.insert(result.end(), newConflicts.begin(), newConflicts.end());
    }

    // Remove duplicates
    vector<literal_set> pure;
    std::sort(result.begin(), result.end(), [&](const literal_set & a, const literal_set & b){ return a.size() < b.size(); });

    for (literal_set conflict : result) {
        bool isPure = true;
        for (literal_set done : pure) {
            bool contains = true;
            for (Literal x : done) {
                if (conflict.find(x) == conflict.end()) {
                    contains = false;
                    break;
                }
            }
            if (contains) {
                isPure = false;
                break;
            }
        }

        if (isPure) pure.push_back(conflict);
    }
    return pure;
}
