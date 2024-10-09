#include "MonotProver.h"

MonotProver::MonotProver (LtlFormulaTriple formulaTriple, literal_set initialLiterals) : LineProver(formulaTriple, initialLiterals) {
}

bool MonotProver::existsRepetition(int k)  {
    for (int i = 1; i <= k+1; ++i) {
        // Clause push from reasons[i-1] => reason[i]
        for (vector<int> reason : reasons[i - 1].get_all()) {
            literal_set conflict = indicesToLiteralSet(reason);
            Solution sol = getSolver(i)->solve(conflict);
            if (!sol.satisfiable) {
                //cout << conflict.size() << " -> " << sol.conflict.size() << endl;
                //cout << "REASON: " << reason.size() << endl;
                assert (reasons[i-1].contains_remove(reason));
                /*
                if (i == k) {
                    cout << "ADDING GLOBAL REASON: " << litsetString(conflict) << endl;
                    for (literal_set learntClause : solvers[0]->createLtlReasons(conflict))
                    {
                        learntClause.insert(Literal("tail", true));
                        //cout << "PUSH: " << litsetString(learntClause) << endl;
                        addGlobalReason(learntClause);
                    }
                    //addGlobalReason(conflict);
                } else {
                */
                //cout << "CLAUSE PUSHED: " << litsetString(conflict) << endl;
                
                if (conflict.size() == sol.conflict.size()) {
                    reasons[i].insert(reason);
                    reasons[i-1].contains_remove(reason);

                    for (literal_set learntClause : solvers[0]->createLtlReasons(conflict)) {
                        learntClause.insert(Literal("tail", true));
                        //cout << "PUSH: " << litsetString(learntClause) << endl;
                        getSolver(i+1)->addClause(learntClause);
                    }
                } else {
                    vector<int> smallReason = literalSetToIndices(sol.conflict);
                    reasons[i].insert(smallReason);
                    reasons[i-1].contains_remove(reason);
                    for (literal_set learntClause : solvers[0]->createLtlReasons(sol.conflict)) {
                        learntClause.insert(Literal("tail", true));
                        for (int j = 0; j <= i+1; ++j) {
                        //cout << "PUSH: " << litsetString(learntClause) << endl;
                        getSolver(i+1)->addClause(learntClause);
                        }
                    }
                }
            } else {
            }
            //solvers[i]->addClause(indicesToLiteralSet(reason));
        }
        // Check if two layers are equal
        // check if reason is the same as previous
        // reasons[i-1] is empty => reasons[i] = reasons[i-1]
        // reasons[0] isn't initialised, so start with i=2
        if (reasons[i - 1].size() == 0) {
            cout << "UNSAT BY INVARIANT" << endl;
            return true;
        }
    }
    return false;
}

void MonotProver::addReason(const literal_set& reason, int distance, const literal_set& parentModel) {
    literal_set r = reason;

    //cout << "CONFLICT: " << distance << " " << litsetString(reason) << endl; 
    
    vector<int> reasonRepresentation = literalSetToIndices(r);
    // Check if adding a stronger reason
    // Needed to preserve monotonicity
    for (int i = 0; i <= distance; ++i) {
        if (reasons[i].contains_remove(reasonRepresentation)) break;
    }

    // Otherwise add the clause normally
    reasons[distance].insert(literalSetToIndices(r));
        //removeObligationsMatchingConflict(reason, distance);
    //cout << "BEGIN:";
    for (literal_set learntClause : solvers[0]->createLtlReasons(r)) {
        learntClause.insert(Literal("tail", true));

         //cout << "LEARN REASON: " << distance+1 << " = " <<  litsetString(learntClause) << endl;
        //cout << "ADDING REASON: " << litsetString(learntClause) << endl;
        for (int i = 1; i <= distance + 1; ++i) {
            getSolver(i)->addClause(learntClause);
        }

        /*
        Solution sol = getSolver(distance+1)->solve(reason);
        if (sol.satisfiable) {
            cout << "NO INV" << endl;
        } else {
            cout << "INV" << endl;
        }
        */
        //removeObligationsMatchingConflict(learntClause, distance+1);
    }
    /*
    vector<int> reasonRepresentation = literalSetToIndices(reason);
    // Check if adding a stronger reason
    // Needed to preserve monotonicity
    for (int i = 0; i <= distance; ++i) {
        if (reasons[i].contains_remove(reasonRepresentation)) break;
    }

    // Otherwise add the clause normally
    //Literal tail = Literal("$tail", true);
    reasons[distance].insert(literalSetToIndices(reason));
    for (literal_set learntClause : solvers[0]->createLtlReasons(reason)) {
        //if (learntClause.find(~tail) == learntClause.end()) learntClause.insert(tail); 
        literal_set neg; 
        for (auto x : learntClause) neg.insert(~x);
        Solution sol = solvers[0]->solve(neg);

        auto it = parentModel.begin();
        while (sol.satisfiable && (it != parentModel.end())) {
            //cout << "ADDING: " << it->toString() << endl;
            neg.insert(*it);
            learntClause.insert(~(*it));
            sol = solvers[0]->solve(neg);
            it++;
        }
        //cout << "LEARN REASON: " << litsetString(learntClause) << endl;
        conflictToReasons[reason].push_back(learntClause);
        for (int i = 1; i <= distance + 1; ++i) {
            getSolver(i)->addClause(learntClause);
        }
    }
    */
}
