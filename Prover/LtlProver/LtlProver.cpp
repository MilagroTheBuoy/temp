#include "LtlProver.h"

LtlProver::LtlProver(LtlFormulaTriple formulaTriple, literal_set initialLiterals)
    : MonotProver(formulaTriple, initialLiterals) {
    }


void LtlProver::preprocess() {
    //formulaTriple.simplifyNext();
    //formulaTriple.simplifyEventuality();
    //formulaTriple.simplifyNextOrs();

    Literal root("$root", true);
    formulaTriple.addClause({~root, *initialLiterals.begin()});
    initialLiterals.clear();
    initialLiterals.insert(root);

    //formulaTriple.simplify();
    // [] L_start -> L
    // [] L -> X ~L_s
    // [] L -> X L
    Literal L ("$loop", true);
    Literal Ls ("$loop_start", true);

    formulaTriple.addClause({~Ls, L});
    formulaTriple.addStepClause({L}, ~Ls);
    formulaTriple.addStepClause({L}, L);


    // [] L_start & p -> choose(p)
    // [] L_start & ~p -> choose(~p)
    // choose(p) -> X choose(p)
    // choose(~p) -> X choose(~p)
    // do not need to enforce exclusivity as 
    // choose(x) -> x at the end (which handles it for us)
    literal_set universe = formulaTriple.getUniverse();
    universe.insert(root);

    for (auto& poslit : universe) {
        if (poslit == Ls) continue;
        if (poslit == L) continue;
        if (poslit.getName().substr(0, 2) == "$E") continue;
        if (poslit.getName().substr(0, 3) == "ex$") continue;

        Literal choose ("choose(" + poslit.toString() + ")", true);
        formulaTriple.addClause({~Ls, ~poslit, choose});
        formulaTriple.addClause({~Ls, poslit, ~choose});
        formulaTriple.addStepClause({L, choose}, choose);
        formulaTriple.addStepClause({L, ~choose}, ~choose);
        //bool flag = false;
        /*
        for (auto& lit : {poslit, ~poslit}) {
            Literal choose ("choose(" + lit.toString() + ")", true);
            Literal nchoose ("choose(" + (~lit).toString() + ")", true);
            formulaTriple.addClause({~Ls, ~lit, choose});
            formulaTriple.addStepClause({choose}, choose);
        */
            /*
            if (!flag) {
                formulaTriple.addClause({choose, nchoose});
                formulaTriple.addClause({~choose, ~nchoose});
                flag = true;
            }*/
    }
    

    // <> L_s
    Literal seen_Ls ("seen($loop_start)", true);
    formulaTriple.addClause({~root, ~seen_Ls});
    //initialLiterals.insert(~seen_Ls);
    formulaTriple.addStepClause({~seen_Ls, ~Ls}, ~seen_Ls);

    // [] L_start -> ~seen(p)
    // [] L & ~seen(p) & ~p -> X ~seen(p)
    // [] L & p -> X seen(p)
    // [] L & seen(p) -> X seen(p)
    universe.clear();
    for (auto& event : formulaTriple.getEventualityClauses()) {
        universe.insert(event.right);
    }
    for (auto& lit : universe) {
        Literal seen ("seen(" + lit.toString() + ")", true);
        formulaTriple.addClause({~Ls, ~seen});
        formulaTriple.addStepClause({L, ~seen, ~lit}, ~seen);
        formulaTriple.addStepClause({L, lit}, seen);
        formulaTriple.addStepClause({L, seen}, seen);
        formulaTriple.addClause({~root, ~seen});
        //initialLiterals.insert(~seen);
        // formulaTriple.addClause({~w0, ~seen});

    }
    //formulaTriple.simplify();


    //formulaTriple.simplifyNext();
    //formulaTriple.simplifyEventuality();
    //formulaTriple.simplifyNextOrs();
    formulaTriple.simplify();

    /*
     formulaTriple.addStepClause({Literal("tail", true)}, Literal("$false", true));
     */
    // DEFINE THE TAIL
    Literal tail("tail", true);
    //cout << "STAGE 2" << endl;

    formulaTriple.addClause({~tail, L});
    formulaTriple.addClause({~tail, ~Ls}); 
    formulaTriple.addClause({~tail, seen_Ls}); 
    //cout << "STAGE 3" << endl;
    // choose(p) -> p
    //cout << "STAGE 1" << endl;
    universe = formulaTriple.getUniverse();
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
        formulaTriple.addClause({~tail, ~choose, poslit});
        formulaTriple.addClause({~tail, choose, ~poslit});
    }
    //cout << "STAGE 4" << endl;
    //cout << "STAGE 2" << endl;

    for (auto eventuality : formulaTriple.getEventualityClauses()) {
        Literal eRight ("$E" + eventuality.right.toString(), true);
        Literal seen ("seen(" + (eventuality.right).toString() + ")", true);
        formulaTriple.addClause({~tail, ~eRight, seen});
    }
}

shared_ptr<Prover> LtlProver::getSolver(int distance) {
    if (distance >= (uint8_t)solvers.size()) {
        // cout << "SPAWNING NEW: " << distance << endl;
        solvers.push_back(shared_ptr<Prover>(new MinisatProver(false)));
        solvers[distance]->prepareLtlfSat(formulaTriple, Literal("nnv0", true),
                                          succInSat);
        if (distance == 0) {
            // Must have all eventualities fulfilled
            solvers[distance]->makeLtlTail(formulaTriple);
            //cout << "REE: " << endl;
            //cout << formulaTriple.toString() << endl;
        }
    }
    return solvers[distance];
}
