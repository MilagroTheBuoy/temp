#include "LtlFormulaTriple.h"

LtlFormulaTriple::LtlFormulaTriple() {}

LtlFormulaTriple::~LtlFormulaTriple() {}

// const Literal& LtlFormulaTriple::getInitialLiteral() const {
// return initialLiteral;
//}

const clause_list& LtlFormulaTriple::getClauses() const { return clauses; }

const ltl_clause_list& LtlFormulaTriple::getStepClauses() const {
    return stepClauses;
}

const ltl_clause_list& LtlFormulaTriple::getEventualityClauses() const {
    return eventualityClauses;
}

const literal_set& LtlFormulaTriple::getUnconditionalEventualities() const {
    return unconditionalEventualities;
}
// void LtlFormulaTriple::setInitialLiteral(Literal newInitialLiteral) {
// initialLiteral = std::move(newInitialLiteral);
//}

void LtlFormulaTriple::setClauses(clause_list newClauses) {
    clauses = std::move(newClauses);
}

void LtlFormulaTriple::setStepClauses(ltl_clause_list newStepClauses) {
    stepClauses = std::move(newStepClauses);
}

void LtlFormulaTriple::setEventualityClauses(
    ltl_clause_list newEventualityClauses) {
    eventualityClauses = std::move(newEventualityClauses);
}

void LtlFormulaTriple::setUnconditionalEventualities(
    literal_set newEventualities) {
    unconditionalEventualities = std::move(newEventualities);
}

void LtlFormulaTriple::eraseClauses() { clauses.clear(); }

void LtlFormulaTriple::eraseStepClauses() { stepClauses.clear(); }

void LtlFormulaTriple::eraseEventualityClauses() { eventualityClauses.clear(); }

void LtlFormulaTriple::addClause(literal_set clause) {
    clauses.push_back(clause);
}

void LtlFormulaTriple::addUnconditionalEventuality(Literal literal) {
    unconditionalEventualities.insert(literal);
}
void LtlFormulaTriple::addStepClause(literal_set left, Literal right) {
    stepClauses.push_back(LtlClause(left, right));
}

void LtlFormulaTriple::addEventualityClause(literal_set left, Literal right) {
    eventualityClauses.push_back(LtlClause(left, right));
}

void LtlFormulaTriple::addStepClause(LtlClause clause) {
    stepClauses.push_back(clause);
}

void LtlFormulaTriple::addEventualityClause(LtlClause clause) {
    eventualityClauses.push_back(clause);
}

vector<string> LtlFormulaTriple::toStringComponents() const {
    vector<string> c_components;
    for (const auto& clause : clauses) {
        string clauseString = "";
        for (const auto& literal : clause) {
            clauseString += literal.toString() + " v ";
        }
        clauseString = clauseString.substr(0, clauseString.size() - 3);
        c_components.push_back(clauseString);
    }
    vector<string> s_components;
    for (LtlClause stepClause : stepClauses) {
        string stepClauseString = "";
        for (const auto& literal : stepClause.left) {
            stepClauseString += literal.toString() + " & ";
        }
        stepClauseString =
            stepClauseString.substr(0, stepClauseString.size() - 3);
        stepClauseString += " -> X " + stepClause.right.toString();
        s_components.push_back(stepClauseString);
    }

    vector<string> e_components;
    for (LtlClause eventualityClause : eventualityClauses) {
        string eventualityClauseString = "";
        for (const auto& literal : eventualityClause.left) {
            eventualityClauseString += literal.toString() + " & ";
        }
        eventualityClauseString = eventualityClauseString.substr(
            0, eventualityClauseString.size() - 3);
        eventualityClauseString +=
            " -> <> " + eventualityClause.right.toString();
        e_components.push_back(eventualityClauseString);
    }

    sort(c_components.begin(), c_components.end());
    sort(s_components.begin(), s_components.end());
    sort(e_components.begin(), e_components.end());

    vector<string> components;
    components.insert(components.end(), c_components.begin(),
                      c_components.end());
    components.insert(components.end(), s_components.begin(),
                      s_components.end());
    components.insert(components.end(), e_components.begin(),
                      e_components.end());
    return components;
}

string LtlFormulaTriple::toString() const {
    string formulaString = "";
    for (string component : toStringComponents()) {
        formulaString += "[] (" + component + ") \n";
    }
    return formulaString;
}

void LtlFormulaTriple::simplify() {
    // combine step and left clauses that share the same RHS
    simplifyNext();
    simplifyEventuality();
    simplifyNextOrs();
}

void LtlFormulaTriple::simplifyNext() {
    // combine step and left clauses that share the same RHS
    unordered_map<Literal, vector<literal_set>, LiteralHash, LiteralEqual>
        stepClausesByRhs;
    for (LtlClause stepClause : stepClauses) {
        stepClausesByRhs[stepClause.right].push_back(stepClause.left);
    }
    stepClauses.clear();
    for (auto& entry : stepClausesByRhs) {
        Literal rhs = entry.first;
        if (entry.second.size() == 1) {
            stepClauses.push_back(LtlClause(entry.second[0], rhs));
        } else {
            Literal newLit = Literal("$combine_step(" + rhs.toString()+ ")", true);
            for (literal_set clause : entry.second) {
                literal_set newClause{newLit};
                for (auto x : clause) newClause.insert(~x);
                clauses.push_back(newClause);
            }
            stepClauses.push_back(LtlClause({newLit}, rhs));
        }
    }
}

void LtlFormulaTriple::simplifyEventuality() {
    // combine eventuality and left clauses that share the same RHS
    unordered_map<Literal, vector<literal_set>, LiteralHash, LiteralEqual>
        eventualitiesByRhs;
    for (LtlClause eventualities : eventualityClauses) {
        eventualitiesByRhs[eventualities.right].push_back(eventualities.left);
    }
    eventualityClauses.clear();
    for (auto& entry : eventualitiesByRhs) {
        Literal rhs = entry.first;
        if (entry.second.size() == 1) {
            eventualityClauses.push_back(LtlClause(entry.second[0], rhs));
        } else {
            Literal newLit = Literal("$combine_event(" + rhs.toString() + ")", true);
            for (literal_set clause : entry.second) {
                literal_set newClause{newLit};
                for (auto x : clause) newClause.insert(~x);
                //cout << "COMBINE: " << litsetString(newClause) << endl;
                clauses.push_back(newClause);
            }
            eventualityClauses.push_back(LtlClause({newLit}, rhs));
        }
    }
}

void LtlFormulaTriple::simplifyNextOrs() {
    /*
[] (~$x1 v nnv8 v nnv7)
[] (~$x2 v nnv7 v nnv6)
[] (~nnv5 v nnv8 v nnv7)
[] (~nnv5 v nnv7 v nnv6)
[] (nnv8 -> X $x2)
[] (nnv8 -> X $x1)

So use: [] nnv8 -> X nnv5
     */
    // Since we doing semantic equality, avoid literals that appear in the
    // LHS of a step/eventuality clause
    literal_set avoid;
    for (LtlClause clause : stepClauses) {
        for (Literal lit : clause.left) avoid.insert(lit);
    }
    for (LtlClause clause : eventualityClauses) {
        for (Literal lit : clause.left) avoid.insert(lit);
    }
    // Also avoid literals that start with $x
    for (literal_set clause : clauses) {
        for (Literal lit : clause) {
            if (lit.getName().substr(0, 2) == "$x") avoid.insert(~lit);
        }
    }

    unordered_map<Literal, literal_set, LiteralHash, LiteralEqual> nextOrs;
    for (LtlClause clause : stepClauses) {
        if (clause.right.getName().substr(0, 2) == "$x") {
            if (clause.left.size() == 1) {
                // This case bash only works for LHS of size 1
                nextOrs[*clause.left.begin()].insert(clause.right);
            }
        }
    }

    unordered_map<Literal, vector<string>, LiteralHash, LiteralEqual> imps;
    for (literal_set clause : clauses) {
        Literal lhs = Literal("err", true);
        int neg = 0;
        for (Literal lit : clause) {
            if (!lit.getPolarity()) {
                lhs = lit;
                neg++;
            }
        }
        if (neg == 1) {
            literal_set implied;
            for (Literal lit : clause)
                if (lit != lhs) implied.insert(lit);
            imps[lhs].push_back(litsetString(implied));
        } else {
            // We are not including this clause, so avoid literals that appear
            // here
            for (Literal lit : clause) avoid.insert(~lit);
        }
    }

    unordered_map<string, Literal> impliedBy;

    for (auto x : imps) {
        if (avoid.find(~x.first) != avoid.end()) continue;
        sort(x.second.begin(), x.second.end());
        string key = "";
        for (string s : x.second) key += s;
        impliedBy.emplace(key, x.first);
    }

    literal_set events;
    for (LtlClause clause : eventualityClauses) events.insert(clause.right);

    literal_set remove;
    unordered_map<Literal, Literal, LiteralHash, LiteralEqual>
        replaceEventualities;
    for (auto x : nextOrs) {
        vector<string> triggered;
        for (Literal lit : x.second) {
            for (auto y : imps[~lit]) triggered.push_back(y);
        }
        sort(triggered.begin(), triggered.end());
        string key;
        for (string s : triggered) key += s;
        if (impliedBy.find(key) != impliedBy.end()) {
            //cout << "Adding step: " << x.first.toString() << " -> "
            //     << (~impliedBy.at(key)).toString() << endl;
            addStepClause({x.first}, ~impliedBy.at(key));
            if (events.find(~impliedBy.at(key)) != events.end()) {
                replaceEventualities.emplace(~impliedBy.at(key), x.first);
            }
            for (Literal lit : x.second) remove.insert(lit);
        }
    }
    ltl_clause_list newStepClauses;
    for (LtlClause clause : stepClauses) {
        if (remove.find(clause.right) == remove.end())
            newStepClauses.push_back(clause);
    }
    stepClauses = newStepClauses;

    // Fine as there is unique RHS
    unordered_map<Literal, literal_set, LiteralHash, LiteralEqual> stepRhs;
    for (LtlClause clause : stepClauses) stepRhs[clause.right] = clause.left;
    

    for (LtlClause clause : eventualityClauses) {
        // Literal eventRhs =  Literal(clause.right.getName().substr(2),
        // clause.right.getPolarity());
        Literal eventRhs = clause.right;
         //cout << "REE: " << eventRhs.toString() << endl;
        if (stepRhs.find(eventRhs) != stepRhs.end()) {
            Literal fresh = Literal("ex$" + clause.right.toString(), true);
            literal_set newClause = {fresh};
            for (auto lit : stepRhs[eventRhs]) newClause.insert(~lit);
             //cout << "ADDING C1: " << litsetString(newClause) << endl;
            addClause(newClause);

            newClause = {
                Literal("$E" + clause.right.toString(), false),
                Literal(clause.right.getName(), clause.right.getPolarity()),
                fresh};
             //cout << "ADDING C2: " << litsetString(newClause) << endl;
            addClause(newClause);
        }
    }

    /*
    ltl_clause_list newEventualityClauses;
    int count = 1;
    for (LtlClause clause : eventualityClauses) {

        if (replaceEventualities.find(clause.right) !=
    replaceEventualities.end()) { Literal fresh =
    Literal("$d"+to_string(count++), true); addClause({fresh,
    ~replaceEventualities.at(clause.right)}); addClause({fresh,
    ~(*clause.left.begin())});
            newEventualityClauses.push_back(LtlClause({fresh},
    replaceEventualities.at(clause.right))); } else {
            newEventualityClauses.push_back(clause);
        }
    }
    eventualityClauses = newEventualityClauses;
    */
}

literal_set LtlFormulaTriple::getUniverse() {
    literal_set universe = {Literal("nnv0", true)};
    for (auto& clause : getClauses())
        for (auto& lit : clause) {
            if (lit.getPolarity())
                universe.insert(lit);
            else
                universe.insert(~lit);
        }
    for (auto& clause : getStepClauses()) {
        for (auto& lit : clause.left) {
            if (lit.getPolarity())
                universe.insert(lit);
            else
                universe.insert(~lit);
        }
        if (clause.right.getPolarity())
            universe.insert(clause.right);
        else
            universe.insert(~clause.right);
    }
    for (auto& clause : getEventualityClauses()) {
        for (auto& lit : clause.left) {
            if (lit.getPolarity())
                universe.insert(lit);
            else
                universe.insert(~lit);
        }
        if (clause.right.getPolarity())
            universe.insert(clause.right);
        else
            universe.insert(~clause.right);
    }
    return universe;
}
