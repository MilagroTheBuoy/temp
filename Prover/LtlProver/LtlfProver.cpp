#include "LtlfProver.h"

LtlfProver::LtlfProver(LtlFormulaTriple formulaTriple, literal_set initialLiterals)
    : LineProver(formulaTriple, initialLiterals) {
    }

void LtlfProver::preprocess() {
    formulaTriple.simplify();
     formulaTriple.addStepClause({Literal("tail", true)}, Literal("$false", true));

     /*
    Literal tail = Literal("tail", true);
    for (auto eventuality : formulaTriple.getEventualityClauses()) {
        //cout << clauseToString({~eventuality.first, eventuality.second}) << endl;
        Literal eRight ("$E" + eventuality.right.toString(), true);
        formulaTriple.addClause({~tail, ~eRight, eventuality.right});
        
        literal_set c;
        for (auto x : eventuality.left) c.insert(~x);
        c.insert(~tail);
        c.insert(eRight);
        formulaTriple.addClause(c);
    }

    for (auto ltlStepClause : formulaTriple.getStepClauses()) {
        literal_set c;
        for (auto x : ltlStepClause.left) c.insert(~x);
        c.insert(~tail);
        c.insert(ltlStepClause.right);
        formulaTriple.addClause(c);
    }
    */
}

shared_ptr<Prover> LtlfProver::getSolver(int distance) {
    if (distance >= (uint8_t)solvers.size()) {
        // cout << "SPAWNING NEW: " << distance << endl;
        solvers.push_back(shared_ptr<Prover>(new MinisatProver(false)));
        solvers[distance]->prepareLtlfSat(formulaTriple, Literal("nnv0", true),
                                          succInSat);
        if (distance == 0) {
            // Must have all eventualities fulfilled
            solvers[distance]->makeLtlfTail();
            //cout << "REE: " << endl;
            //cout << formulaTriple.toString() << endl;
        }
    }
    return solvers[distance];
}
