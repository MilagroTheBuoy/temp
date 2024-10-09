#include <iostream>
#include <fstream>
#include "Clausifier/LtlFormulaTriple/LtlFormulaTriple.h"

#include "Prover/LtlProver/LineProver.h"
#include "Prover/LtlProver/LtlfProver.h"
#include "Prover/LtlProver/LtlProver.h"
#include "Parser/ltlsnfLexer.h"
#include "Parser/ltloriginalLexer.h"
#include "Parser/ltloriginalBaseVisitor.h"
#include "Parser/ltlsnfParser.h"
#include "Parser/ltlsnfBaseListener.h"
#include "Prover/Literal/Literal.h"
#include "Formula/Next/Next.h"
#include "Formula/Always/Always.h"
#include "Formula/Until/Until.h"
#include "Formula/Atom/Atom.h"
#include "Formula/And/And.h"
#include "Formula/Sometime/Sometime.h"
#include <antlr4-runtime/antlr4-runtime.h>

using namespace std;
/*
class LTLFormulaVisitor : public ltloriginalBaseVisitor {
public:
    std::any visitStart(ltloriginalParser::StartContext *ctx) override {
    return visitLtlFormula(ctx->ltl_formula());
}

    shared_ptr<Formula> visitLtlFormula(ltloriginalParser::Ltl_formulaContext *ctx) {
        if (ctx->IDENTIFIER() != nullptr) {
            return Atom::create(ctx->IDENTIFIER()->getText());
        }
        
        if (ctx->AND() != nullptr) {
            return And::create({visitLtlFormula(ctx->ltl_formula(0)), visitLtlFormula(ctx->ltl_formula(1))});
        }
        else if (ctx->OR() != nullptr) {
            return Or::create({visitLtlFormula(ctx->ltl_formula(0)), visitLtlFormula(ctx->ltl_formula(1))});
        }
        else if (ctx->NOT() != nullptr) {
            return Not::create(visitLtlFormula(ctx->ltl_formula(0)));
        }
        else if (ctx->NEXT() != nullptr) {
            return Next::create(visitLtlFormula(ctx->ltl_formula(0)));
        }
        else if (ctx->ALWAYS() != nullptr) {
            return Always::create(visitLtlFormula(ctx->ltl_formula(0)));
        }
        else if (ctx->SOMETIME() != nullptr) {
            return Sometime::create(visitLtlFormula(ctx->ltl_formula(0)));
        }
        else if (ctx->UNTIL() != nullptr) {
            return Until::create(visitLtlFormula(ctx->ltl_formula(0)), visitLtlFormula(ctx->ltl_formula(1)));
        }
        // By default, we assume the formula is surrounded by parentheses.
        return visitLtlFormula(ctx->ltl_formula(0));
    }
};
*/

class LTLFormulaVisitor : public ltloriginalBaseVisitor {
public:
    std::any visitStart(ltloriginalParser::StartContext *ctx) override {
        return visitLtlFormula(ctx->ltl_formula());
    }

    shared_ptr<Formula> visitLtlFormula(ltloriginalParser::Ltl_formulaContext *ctx) {
        if (ctx->ltl_formula() != nullptr) {
            // Don't use create method as that does simplifications
            if (ctx->AND() != nullptr) {
                return shared_ptr<Formula>(new And({visitLtlFormula(ctx->ltl_formula()), visitLtlTerm(ctx->ltl_term())}));
            } else if (ctx->OR() != nullptr) {
                return shared_ptr<Formula>(new Or({visitLtlFormula(ctx->ltl_formula()), visitLtlTerm(ctx->ltl_term())}));
            } else if (ctx->IMPLIES() != nullptr) {
                return shared_ptr<Formula>(new Or({visitLtlFormula(ctx->ltl_formula())->negate(), visitLtlTerm(ctx->ltl_term())}));
                //return shared_ptr<Formula>(new Implies(visitLtlFormula(ctx->ltl_formula()), visitLtlTerm(ctx->ltl_term())));
            } else if (ctx->IFF() != nullptr) {
                assert (1 == 0);
                //return shared_ptr<Formula>(new Equiv(visitLtlFormula(ctx->ltl_formula()), visitLtlTerm(ctx->ltl_term())));
            }
        }
        return visitLtlTerm(ctx->ltl_term());
    }

    shared_ptr<Formula> visitLtlTerm(ltloriginalParser::Ltl_termContext *ctx) {
        if (ctx->ltl_term() != nullptr && ctx->UNTIL() != nullptr) {
            return Until::create(visitLtlTerm(ctx->ltl_term()), visitLtlFactor(ctx->ltl_factor()));
        }
        return visitLtlFactor(ctx->ltl_factor());
    }

    shared_ptr<Formula> visitLtlFactor(ltloriginalParser::Ltl_factorContext *ctx) {
        if (ctx->IDENTIFIER() != nullptr) {
            // string text = ctx->IDENTIFIER()->getText();
            // Don't want to create TRUE or FALSE atoms as they print differently
            return Atom::create(ctx->IDENTIFIER()->getText());
        } else if (ctx->NOT() != nullptr) {
            return Not::create(visitLtlFactor(ctx->ltl_factor()));
        } else if (ctx->NEXT() != nullptr) {
            return Next::create(visitLtlFactor(ctx->ltl_factor()));
        } else if (ctx->ALWAYS() != nullptr) {
            return Always::create(visitLtlFactor(ctx->ltl_factor()));
        } else if (ctx->SOMETIME() != nullptr) {
            return Sometime::create(visitLtlFactor(ctx->ltl_factor()));
        } else if (ctx->ltl_formula() != nullptr) {
            return visitLtlFormula(ctx->ltl_formula());
        }
        // By default, we assume the formula is surrounded by parentheses.
        return visitLtlFactor(ctx->ltl_factor());
    }
};



class LtlListener : public ltlsnfBaseListener {
private:
  shared_ptr<Literal> initialLiteral;
  LtlFormulaTriple formulaTriple;
  bool insideTemporalClause;
  int counter = 0;

public:
  shared_ptr<Literal> getInitialLiteral() {
    return initialLiteral;
  }

  Literal createLiteral(ltlsnfParser::LiteralContext *ctx) {
    std::string identifier = ctx->IDENTIFIER()->getText();
    bool negated = ctx->NOT() != nullptr;
    return Literal(identifier, !negated);
  }

  void enterTemporalClause(ltlsnfParser::TemporalClauseContext *ctx) override {
    insideTemporalClause = true;
  }

  void exitTemporalClause(ltlsnfParser::TemporalClauseContext *ctx) override {
    insideTemporalClause = false;
  }

  void enterPropositionalClause(ltlsnfParser::PropositionalClauseContext *ctx) override {
    auto clauseList = ctx->literalList()->literal();
    if (!insideTemporalClause) {
        assert (clauseList.size() == 1);
        initialLiteral = make_shared<Literal>(createLiteral(clauseList[0]));
        return;
    }
    
    literal_set literals;
    for (auto clause : clauseList) {
        literals.insert(createLiteral(clause));
    }
    //cout  << "CLASSICAL: " << litsetString(literals) << endl;
    formulaTriple.addClause(literals);
  }

  void enterStepClause(ltlsnfParser::StepClauseContext *ctx) override {
    auto literalList = ctx->literalList()->literal();
    literal_set left;
    for (auto literal : literalList) {
        left.insert(~createLiteral(literal));
    }

    auto nextLiteralList = ctx->nextLiteralList()->literal();
    literal_set right;
    for (auto literal : nextLiteralList) {
        right.insert(createLiteral(literal));
    }
    if (right.size() == 1) {
        formulaTriple.addStepClause(left, *right.begin());
    } else {
        string newX = "$x" + to_string(++counter);
        Literal newRight = Literal(newX, true);
        formulaTriple.addStepClause(left, newRight);
        right.insert(~newRight);
        formulaTriple.addClause(right);

    }
     // cout << "STEP: " << litsetString(right) << endl;
    
  }

  void enterSometimeClause(ltlsnfParser::SometimeClauseContext *ctx) override {
    auto literalList = ctx->literalList()->literal();
    literal_set left;
    for (auto literal : literalList) {
        left.insert(~createLiteral(literal));
    }
    Literal right = createLiteral(ctx->literal());
    formulaTriple.addEventualityClause(left, right);
      //cout << "SOMETIME: " << litsetString({right}) << endl;
  }

  LtlFormulaTriple getFormulaTriple() const {
    return formulaTriple;
  }


};

string initialiseLtlf(string file) {
  std::ifstream inputFile(file);
  antlr4::ANTLRInputStream input(inputFile);
  ltloriginalLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  ltloriginalParser parser(&tokens);

  ltloriginalParser::StartContext* tree = parser.start();
  LTLFormulaVisitor visitor;
  std::any result = visitor.visitStart(tree);
  auto formula = std::any_cast<std::shared_ptr<Formula>>(result);
  //cout << "ORIG: " << formula->toString() << endl;
  formula = formula->negatedNormalForm();
  //cout << "NNF: " << formula->toString() << endl;
  formula = formula->tailNormalForm();
  //cout << "TNF: " << formula->toString() << endl;
  formula = And::create({formula, 
          Sometime::create(Atom::create("tail"))});/*, 
          Or::create({
                  Not::create(Atom::create("tail")), Next::create(Atom::create("true"))})});
                  */

  // Write tail normal form to a temporary file
  std::ofstream tailFormFile ("tail.ltl");
  tailFormFile << formula->toString();
  tailFormFile.close();

  return "tail.ltl";
}

int main(int argc, char **argv) {
  // Validate input arguments
  if (argc < 2) {
    std::cerr << "Please provide a filename." << std::endl;
    return 1;
  }

  std::string toSnf;
  bool finiteMode = false;

  // Check if "-f" flag is given
  if (argc >= 3 && std::string(argv[1]) == "-f") {
    // Finite mode
    toSnf = initialiseLtlf(argv[2]);
    finiteMode = true;
  } else {
    // Infinite mode (default)
    toSnf = argv[1];
  }
  // Get the path to the executable
  std::string programPath = argv[0];
  std::string::size_type lastSlashPos = programPath.find_last_of('/');
  std::string executablePath = programPath.substr(0, lastSlashPos + 1);

  // Construct the full path to ltl2snf executable
  std::string ltl2snfPath = executablePath + "ltl2snf";

  // Run ltl2snf on the temporary file
  std::string flag = finiteMode ? "-reuse_renaming -prenex  -simp" : "-reuse_renaming -prenex -ple -simp";
  std::string command = ltl2snfPath + " -i " + toSnf + " -o simplified.ltl " + flag;
  int exitCode = std::system(command.c_str());           
  if (exitCode != 0) {
    std::cerr << "Failed to execute ltl2snf program." << std::endl;
    return 1;
  }

  // Read the generated simplified formula
  std::ifstream simplifiedInputFile("simplified.ltl");
  if (!simplifiedInputFile.is_open()) {
    std::cerr << "Failed to open input file." << std::endl;
    return 1;
  }

  std::string simplifiedFormula;
  std::string line;
  while (std::getline(simplifiedInputFile, line)) {
    simplifiedFormula += line; // Append the line to the formula string
  }
  simplifiedInputFile.close();

  // Create ANTLR input stream
  antlr4::ANTLRInputStream inputSimplified(simplifiedFormula);

  // Create lexer
  ltlsnfLexer lexerSimplified(&inputSimplified);
  antlr4::CommonTokenStream tokensSimplified(&lexerSimplified);

  // Create parser
  ltlsnfParser parserSimplified(&tokensSimplified);

  // Parse the formula using MyListener
  LtlListener listener;
  antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserSimplified.formula());
  cout << "STARTING PROVER" << endl;

  // Create LineProver with parsed formula triple and initial literal
std::unique_ptr<LineProver> lineProver;

literal_set init = {*listener.getInitialLiteral()};
if (finiteMode) {
    lineProver = std::make_unique<LtlfProver>(listener.getFormulaTriple(), init);
} else {
    lineProver = std::make_unique<LtlProver>(listener.getFormulaTriple(), init);
}

if (lineProver->isSat()) {
    std::cout << "SAT" << std::endl;
} else {
    std::cout << "UNSAT" << std::endl;
}
  return 0;
}
