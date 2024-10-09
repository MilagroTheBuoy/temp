#ifndef LTLPROVER_H
#define LTLPROVER_H
#include "LineProver.h"
#include "MonotProver.h"

class LtlProver : public MonotProver {
    public:
        LtlProver (LtlFormulaTriple formulaTriple, literal_set initialLiterals);
        void preprocess();
    private:
        shared_ptr<Prover> getSolver(int distance);
};
#endif
