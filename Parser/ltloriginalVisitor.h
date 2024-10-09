
// Generated from ltloriginal.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ltloriginalParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ltloriginalParser.
 */
class  ltloriginalVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ltloriginalParser.
   */
    virtual std::any visitStart(ltloriginalParser::StartContext *context) = 0;

    virtual std::any visitLtl_formula(ltloriginalParser::Ltl_formulaContext *context) = 0;

    virtual std::any visitLtl_term(ltloriginalParser::Ltl_termContext *context) = 0;

    virtual std::any visitLtl_factor(ltloriginalParser::Ltl_factorContext *context) = 0;


};

