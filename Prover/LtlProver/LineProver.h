#ifndef LINEPROVER_H
#define LINEPROVER_H

#include "../../Prover/Literal/Literal.h"
#include "../../Prover/Prover/Prover.h"
#include "../../Prover/MinisatProver/MinisatProver.h"
#include "../../Clausifier/LtlFormulaTriple/LtlFormulaTriple.h"
#include "../../SetTrie/SetTrie.h"

struct StateAssumps {
    literal_set assumptions;
    literal_set eventualities;

    string toString() {
        string res = "";
        literal_set all = assumptions;
        all.insert(eventualities.begin(), eventualities.end());
        return litsetString(all);
    }
};

struct Obligation {
    StateAssumps assumptions;
    vector<literal_set> parentModel;
    int distance;
    string toString() {
        return to_string(distance) + ": " + assumptions.toString();
    }

};

struct StateResult {
    bool success;
    StateAssumps successor;
    literal_set conflict;
    literal_set model;
};

 struct ObligationComparator {
    bool operator()(const Obligation& a, const Obligation& b) const {
        return a.distance > b.distance; // Sort in ascending order of distance
    }
};

class LineProver {
    public:
        LineProver(LtlFormulaTriple formulaTriple, literal_set initialLiterals);
        ~LineProver();

        bool isSat();
        StateResult solveState(Obligation& obligation, int k);
    protected:
        // Store the successor state in the SAT solver.
        // Doubles number of variables, but ensures learnt reasons are only
        // to deal with reachability.
        bool succInSat = false;
        priority_queue<Obligation, vector<Obligation>, ObligationComparator> pq;
        LtlFormulaTriple formulaTriple;
        literal_set initialLiterals;
        vector<shared_ptr<Prover>> solvers;
        virtual shared_ptr<Prover> getSolver(int distance) = 0;
        virtual void preprocess() = 0;
        void addReason(int distance, literal_set reason);
        virtual void addReason(const literal_set& reason, int distance, const literal_set& parentModel={});
        unordered_map<string, int> literalNameToIndex;
        unordered_map<int, Literal> indexToLiteral;
        vector<int> literalSetToIndices(const literal_set& literals);
        literal_set indicesToLiteralSet(const vector<int>& indices);
        map<int, Set_Trie> reasons;
        void removeObligationsMatchingConflict(const literal_set& conflict, int distance);

        void addGlobalReason(const literal_set& reason);
        map<string, int> conflictStore;
        unordered_map<literal_set, vector<literal_set>, LiteralSetHash, LiteralSetEqual> conflictToReasons;
        virtual bool existsRepetition(int k);
        bool existsSubsetRepetition(int k);
        bool existsVardiRepetition(int k);

};

#endif
