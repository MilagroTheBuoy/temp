#include "LineProver.h"

LineProver::LineProver(LtlFormulaTriple formulaTriple,
                       literal_set initialLiterals)
    : formulaTriple(formulaTriple), initialLiterals(initialLiterals) {}

LineProver::~LineProver() {}

bool LineProver::isSat() {
    // cout << formulaTriple.toString() << endl;
    // cout << "SIMPLIFY NOW" << endl;
    preprocess();
    //cout << formulaTriple.toString() << endl;
    while (pq.size()) pq.pop();

    for (int k = 0;; ++k) {
        conflictStore.clear();
        cout << "LEVEL: " << k << endl;
        // cout << "REE: " << initialLiterals.size() << endl;
        pq.push({{initialLiterals, {}}, {}, k});
        while (!pq.empty()) {
            auto state = pq.top();
            pq.pop();
            //cout << "SIZE: " << pq.size() << endl;
            //cout << "OBLIGATION: " << state.toString() << endl;

            // get the last state
            // auto state = states.back();
            // states.pop_back();
            // cout << endl;
            // cout << endl;
            StateResult result = solveState(state, k);

            // cout << endl;
            if (result.success) {
                if (state.distance == 0) {
                    /*
                    cout << "FOUND: " << endl;
                    cout << "LENGTH: " << state.parentModel.size() + 1 << endl;
                    for (auto x : state.parentModel) {
                        cout << litsetString(x) << endl;
                    }
                    cout << litsetString(result.model) << endl;
                    */
                    return true;
                } else {
                    pq.push(
                        {state.assumptions, state.parentModel, state.distance});

                    vector<literal_set> hist = state.parentModel;
                    hist.push_back(result.model);
                    pq.push({result.successor, {}, state.distance - 1});
                }
            } else {
                if (result.conflict.size() == 0) {
                    cout << "UNSAT BY EMPTY CLAUSE" << endl;
                    return false;
                }
                addReason(result.conflict, state.distance, state.parentModel[0]);
                /*
                for (int l = 0; l <= state.distance; ++l) {
                    Solution sol = getSolver(l)->solve(result.conflict);
                    if (!sol.satisfiable) {
                        addReason(result.conflict, state.distance,
                                  state.parentModel[0]);
                    }
                }
                */
                // obligation rescheduling
                if (state.distance < k)
                    pq.push({state.assumptions, state.parentModel,
                state.distance + 1});
            }
        }

        // states that cannot reach goal in <= i steps;
        if (existsRepetition(k)) return false;
    }
    return false;
}

bool LineProver::existsRepetition(int k) {
    // clause push
    //cout << "BEGIN REP" << endl;
    //cout << "END CLAUSE PUSH" << endl;
    //cout << "BEGIN CHECK" << endl;
    // Check if reasons[i] <= reasons[j] for some i < j <= k
    vector<set<vector<int>>> allReasons (k+1);
    for (int i = 0; i <= k; ++i) {
        allReasons[i] = reasons[i].get_all();
        /*
        cout << "C[" << i << "] = " << allReasons[i].size() << endl;
        for (vector<int> reason : allReasons[i]) {
            literal_set conflict = indicesToLiteralSet(reason);
            cout << litsetString(conflict) << endl;
        }
        */
    }

    //cout << "BEGIN" << endl;
    //cout << "BEGIN PUSH" << endl;
    for (int i = 0; i <= k; ++i) {
        for (int j = i + 1; j <= k; ++j) {

            set<vector<int>> difference;
            set_difference(allReasons[i].begin(),
                           allReasons[i].end(),
                           allReasons[j].begin(),
                           allReasons[j].end(),
                           inserter(difference, difference.begin()));

            bool allPushed = true;
            for (vector<int> reason : difference) {
                literal_set conflict = indicesToLiteralSet(reason);
                Solution sol = getSolver(j)->solve(conflict);
                if (!sol.satisfiable) {
                    addReason(sol.conflict, j, {});
                    allReasons[j].insert(literalSetToIndices(sol.conflict));
                    //cout << "clause pushed: " << litsetString(conflict) << endl;
                    /*
                    if (j == k) {
                        addGlobalReason(conflict);
                        reasons[i].contains_remove(reason);
                    } else {
                    }
                    */

                } else {
                    allPushed = false;
                }
            }
            

            // Check if currentReasons is subset of rollingSuperset
            if (allPushed) {
                cout << "UNSAT BY INVARIANT: " << i << " = " << j << endl;
                return true;
            }
        }
    }
    //cout << "END PUSH" << endl;
    //cout << "END CHECK" << endl;
    //cout << "END REP" << endl;
    return false;
}

bool LineProver::existsSubsetRepetition(int k) {
    /*
    cout << "BEGIN CLAUSE PUSH" << endl;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < i; ++j) {
            set<vector<int>> newReasons = reasons[i].get_all();
            for (vector<int> reason : allReasons) {
                if (newReasons.find(reason) != newReasons.end()) continue;

                // Reason cannot reach goal in <= i-1 steps
                // Test if it can reach goal in i steps
                literal_set conflict = indicesToLiteralSet(reason);
                Solution sol = getSolver(i+1)->solve(conflict);
                if (!sol.satisfiable) {
                    if (i == k) {
                        addGlobalReason(conflict);
                    } else {
                        //cout << "clause pushed: " << litsetString(conflict) << endl;
                        addReason(conflict, i+1, {});
                    }
                }
            }
            allReasons.insert(newReasons.begin(), newReasons.end());
        }
    }
    */
    /*
    for (int i = 0; i <= k; ++i) {
        set<vector<int>> ci = reasons[i].get_all();
        cout << "C[" << i << "] = " << ci.size() << endl;
        for (auto x : ci) {
            cout << litsetString(indicesToLiteralSet(x)) << endl;
        }
    }
    */
    set<vector<int>> rollingSuperset = reasons[0].get_all();
    for (int i = 1; i < k; ++i) {
        set<vector<int>> currentReasons = reasons[i].get_all();
        
        set<vector<int>> difference;
        set_difference(currentReasons.begin(), currentReasons.end(),
                       rollingSuperset.begin(), rollingSuperset.end(),
                       inserter(difference, difference.begin()));
        // try clause pushing the difference
        bool allPushed = true;
        for (vector<int> reason : difference) {
            literal_set conflict = indicesToLiteralSet(reason);
            bool beenPushed = false;
            for (int j = 0; j < i; ++j) {
                Solution sol = getSolver(j)->solve(conflict);
                if (!sol.satisfiable) {
                    cout << "clause pushed: " << litsetString(conflict) << endl;
                    beenPushed = true;
                    addReason(conflict, j, {});
                }
            }
            if (!beenPushed) allPushed = false;
        }
        

        // Check if currentReasons is subset of rollingSuperset
        if (!allPushed) {
            cout << "UNSAT BY INVARIANT: " << i - 1 << " = " << i << endl;
            return true;
        }

        rollingSuperset.insert(currentReasons.begin(), currentReasons.end());
    }
    return false;
}
bool LineProver::existsVardiRepetition(int k) {
    set<vector<int>> rollingIntersection = reasons[0].get_all();
    for (int i = 2; i <= k; ++i) {
        // First clause propagate from i-1 to i
        set<vector<int>> currentReasons = reasons[i].get_all();

        set<vector<int>> difference;
        set_difference(rollingIntersection.begin(), rollingIntersection.end(),
                       currentReasons.begin(), currentReasons.end(),
                       inserter(difference, difference.begin()));

        bool previousIsSubset = difference.size() == 0;
        cout << "DIFFERENCE: " << i << endl;
        for (auto x : difference) {
            cout << litsetString(indicesToLiteralSet(x)) << endl;
        }
        /*
        for (vector<int> reason : difference) {
            // Reason cannot reach goal in <= i-1 steps
            // Test if it can reach goal in i steps
            literal_set conflict = indicesToLiteralSet(reason);
            Solution sol = getSolver(i)->solve(conflict);
            if (!sol.satisfiable) {
                if (i == k+1) {
                    //cout << "GLOBAL REASON" << endl;
                    addGlobalReason(conflict);
                } else {
                    //cout << "clause pushed: " << litsetString(conflict) <<
        endl; reasons[i].insert(reason);
                }
            } else {
                previousIsSubset = false;
            }
        }
        */
        if (previousIsSubset) {
            cout << "UNSAT BY INVARIANT: " << i - 1 << " = " << i << endl;
            return true;
        }

        currentReasons = reasons[i].get_all();
        // rollingIntersection is intersection with currentReasons
        set<vector<int>> intersection;
        set_intersection(currentReasons.begin(), currentReasons.end(),
                         rollingIntersection.begin(), rollingIntersection.end(),
                         inserter(intersection, intersection.begin()));
        rollingIntersection = intersection;
    }

    cout << endl;
    cout << "PRINT ROLLING" << endl;
    rollingIntersection = reasons[0].get_all();
    cout << "C[0]:" << endl;
    for (auto x : rollingIntersection) {
        cout << litsetString(indicesToLiteralSet(x)) << endl;
    }

    for (int i = 1; i <= k; ++i) {
        cout << "C[i]: " << i << endl;

        set<vector<int>> currentReasons = reasons[i].get_all();
        for (auto x : currentReasons) {
            cout << litsetString(indicesToLiteralSet(x)) << endl;
        }

        set<vector<int>> intersection;
        set_intersection(currentReasons.begin(), currentReasons.end(),
                         rollingIntersection.begin(), rollingIntersection.end(),
                         inserter(intersection, intersection.begin()));
        rollingIntersection = intersection;

        vector<string> allReasons;
        for (auto x : rollingIntersection) {
            allReasons.push_back(litsetString(indicesToLiteralSet(x)));
        }
        sort(allReasons.begin(), allReasons.end());
        cout << "INTERSECTION: " << i << endl;
        for (auto x : allReasons) {
            cout << x << endl;
        }
    }
    return false;
}

void LineProver::addGlobalReason(const literal_set& reason) {
    for (literal_set c : solvers[0]->createLtlReasons(reason)) {
        formulaTriple.addClause(c);
        for (int i = 1; i < solvers.size(); ++i) {
            solvers[i]->addClause(c);
        }
    }
}

void LineProver::removeObligationsMatchingConflict(const literal_set& conflict,
                                                   int distance) {
    priority_queue<Obligation, vector<Obligation>, ObligationComparator>
        updatedPq;

    while (!pq.empty()) {
        Obligation obligation = pq.top();
        pq.pop();

        literal_set combined = obligation.assumptions.assumptions;
        combined.insert(obligation.assumptions.eventualities.begin(),
                        obligation.assumptions.eventualities.end());

        bool isSuperset = true;
        for (auto literal : conflict) {
            if (combined.find(literal) == combined.end()) {
                isSuperset = false;
                break;
            }
        }

        if (!isSuperset || (obligation.distance > distance)) {
            updatedPq.push(obligation);
        } else {
            cout << "REMOVED" << endl;
        }
    }

    pq = updatedPq;  // Update pq with the filtered obligations
}
/*
void LineProver::removeObligationsMatchingConflict(const literal_set& conflict)
{ std::vector<Obligation>::iterator it = states.begin(); while (it !=
states.end()) { literal_set combined = it->assumptions.assumptions;
       combined.insert(it->assumptions.eventualities.begin(),
it->assumptions.eventualities.end());

       bool isSuperset = true;
       for (auto literal : conflict) {
           if (combined.find(literal) == combined.end()) {
               isSuperset = false;
               break;
           }
       }

       if (isSuperset) {
           it = states.erase(it);
       } else {
           ++it;
       }
   }
}
*/

literal_set LineProver::indicesToLiteralSet(const vector<int>& indices) {
    literal_set result;
    for (auto index : indices) {
        result.insert(indexToLiteral.at(index));
    }
    return result;
}
vector<int> LineProver::literalSetToIndices(const literal_set& literals) {
    vector<int> result;
    for (auto literal : literals) {
        if (literalNameToIndex.find(literal.getName()) ==
            literalNameToIndex.end()) {
            literalNameToIndex[literal.getName()] =
                literalNameToIndex.size() + 1;
            indexToLiteral.emplace(literalNameToIndex.size(),
                                   Literal(literal.getName(), true));
            indexToLiteral.emplace(-literalNameToIndex.size(),
                                   Literal(literal.getName(), false));
        }
        int idx = literalNameToIndex[literal.getName()];
        result.push_back(literal.getPolarity() ? idx : -idx);
    }
    // sort by absolute value
    sort(result.begin(), result.end(),
         [](int a, int b) { return abs(a) < abs(b); });
    return result;
}

void LineProver::addReason(const literal_set& conflict, int distance,
                           const literal_set& parentModel) {
    // Otherwise add the clause normally
    reasons[distance].insert(literalSetToIndices(conflict));
    // cout << endl;
    //cout << "CONFLICT: " << distance << " " << litsetString(conflict) << endl; 
    //removeObligationsMatchingConflict(conflict, distance);

    for (literal_set learntClause : solvers[0]->createLtlReasons(conflict)) {
         //cout << "LEARN REASON: " << distance+1 << " = " <<  litsetString(learntClause) << endl;
        getSolver(distance + 1)->addClause(learntClause);
        // reasons[distance+1].insert(literalSetToIndices(learntClause));
    }
}

StateResult LineProver::solveState(Obligation& obligation, int k) {
    shared_ptr<Prover> solver = getSolver(obligation.distance);

    literal_set assumptions = obligation.assumptions.assumptions;
    assumptions.insert(obligation.assumptions.eventualities.begin(),
                       obligation.assumptions.eventualities.end());

    // if (k == 0) assumptions.insert(Literal("$goal", true));

    // cout << "SOLVING WITH ASS: " << k << " -> " << litsetString(assumptions)
    // << endl;

    // cout << "BEGIN SOLVE" << endl;
    Solution solution = solver->solve(assumptions);
    // cout << "END SOLVE" << endl;
    if (!solution.satisfiable) {
        if (solution.conflict.empty()) {
            // cast solver to minisatProver
            // MinisatProver prover =
            // dynamic_cast<MinisatProver*>(solver.get());
            // prover.calcSolver->toDimacs("dimacs.out");
        }
        solver->reduce_conflict(solution.conflict);

        // Clause pushing

        /*
        int newDistance = obligation.distance;
        while (newDistance == k) {
            solver = getSolver(newDistance + 1);
            Solution newSolution = solver->solve(solution.conflict);
            if (newSolution.satisfiable) {
                break;
            }
            newDistance++;
            // obligation.distance;
        }
        if (true) {
            // This is a global conflict, bit hacky
            obligation.distance = newDistance;
        }
        */
        // return {false, {}, assumptions, {}};
        return {false, {}, solution.conflict, {}};
    } else {
        // Create successor state
        auto model = solver->getModel();
         //cout << "INHERE MODEL: "  << litsetString(model) << endl;        //
        // cout << "MODEL: " << litsetString(solver->getModel()) << endl;
        auto successorAssumps = solver->getLtlSuccessorAssumps(
            obligation.assumptions.eventualities);
        // cout << "SUCCESSOR ASSUMPS: " << litsetString(successorAssumps.first)
        // << litsetString(successorAssumps.second) << endl;
        return {
            true, {successorAssumps.first, successorAssumps.second}, {}, model};
    }
}

void LineProver::addReason(int distance, literal_set reason) {
    assert(1 == 0);
    shared_ptr<Prover> solver = getSolver(distance);
    // solver->addClause(reason);
}

