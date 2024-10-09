#ifndef LTLFPROVER_H
#define LTLFPROVER_H
#include "LineProver.h"
#include "MonotProver.h"

class LtlfProver : public LineProver {
    public:
        LtlfProver (LtlFormulaTriple formulaTriple, literal_set initialLiterals);
        void preprocess();
    protected:
        shared_ptr<Prover> getSolver(int distance);
};
#endif
