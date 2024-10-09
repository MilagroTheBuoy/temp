#ifndef MONOTPROVER_H
#define MONOTPROVER_H
#include "LineProver.h"

class MonotProver : public LineProver {
    public:
        MonotProver (LtlFormulaTriple formulaTriple, literal_set initialLiterals);
    protected:
        bool existsRepetition(int k) override;


        void addReason(const literal_set& reason, int distance, const literal_set& parentModel={}) override;
};
#endif
