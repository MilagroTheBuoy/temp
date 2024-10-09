
// Generated from kspclauses.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "kspclausesParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by kspclausesParser.
 */
class  kspclausesListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(kspclausesParser::FileContext *ctx) = 0;
  virtual void exitFile(kspclausesParser::FileContext *ctx) = 0;

  virtual void enterSection(kspclausesParser::SectionContext *ctx) = 0;
  virtual void exitSection(kspclausesParser::SectionContext *ctx) = 0;

  virtual void enterSection_header(kspclausesParser::Section_headerContext *ctx) = 0;
  virtual void exitSection_header(kspclausesParser::Section_headerContext *ctx) = 0;

  virtual void enterClause(kspclausesParser::ClauseContext *ctx) = 0;
  virtual void exitClause(kspclausesParser::ClauseContext *ctx) = 0;

  virtual void enterClause_body(kspclausesParser::Clause_bodyContext *ctx) = 0;
  virtual void exitClause_body(kspclausesParser::Clause_bodyContext *ctx) = 0;

  virtual void enterDiamond_clause(kspclausesParser::Diamond_clauseContext *ctx) = 0;
  virtual void exitDiamond_clause(kspclausesParser::Diamond_clauseContext *ctx) = 0;

  virtual void enterBox_clause(kspclausesParser::Box_clauseContext *ctx) = 0;
  virtual void exitBox_clause(kspclausesParser::Box_clauseContext *ctx) = 0;

  virtual void enterClassical_clause(kspclausesParser::Classical_clauseContext *ctx) = 0;
  virtual void exitClassical_clause(kspclausesParser::Classical_clauseContext *ctx) = 0;

  virtual void enterTerm(kspclausesParser::TermContext *ctx) = 0;
  virtual void exitTerm(kspclausesParser::TermContext *ctx) = 0;


};

