
// Generated from kspclauses.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "kspclausesParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by kspclausesParser.
 */
class  kspclausesVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by kspclausesParser.
   */
    virtual std::any visitFile(kspclausesParser::FileContext *context) = 0;

    virtual std::any visitSection(kspclausesParser::SectionContext *context) = 0;

    virtual std::any visitSection_header(kspclausesParser::Section_headerContext *context) = 0;

    virtual std::any visitClause(kspclausesParser::ClauseContext *context) = 0;

    virtual std::any visitClause_body(kspclausesParser::Clause_bodyContext *context) = 0;

    virtual std::any visitDiamond_clause(kspclausesParser::Diamond_clauseContext *context) = 0;

    virtual std::any visitBox_clause(kspclausesParser::Box_clauseContext *context) = 0;

    virtual std::any visitClassical_clause(kspclausesParser::Classical_clauseContext *context) = 0;

    virtual std::any visitTerm(kspclausesParser::TermContext *context) = 0;


};

