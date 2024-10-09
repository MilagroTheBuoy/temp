
// Generated from ltlsnf.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ltlsnfParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ltlsnfParser.
 */
class  ltlsnfListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFormula(ltlsnfParser::FormulaContext *ctx) = 0;
  virtual void exitFormula(ltlsnfParser::FormulaContext *ctx) = 0;

  virtual void enterListOfSnfClauses(ltlsnfParser::ListOfSnfClausesContext *ctx) = 0;
  virtual void exitListOfSnfClauses(ltlsnfParser::ListOfSnfClausesContext *ctx) = 0;

  virtual void enterSnfClauseList(ltlsnfParser::SnfClauseListContext *ctx) = 0;
  virtual void exitSnfClauseList(ltlsnfParser::SnfClauseListContext *ctx) = 0;

  virtual void enterSnfClause(ltlsnfParser::SnfClauseContext *ctx) = 0;
  virtual void exitSnfClause(ltlsnfParser::SnfClauseContext *ctx) = 0;

  virtual void enterAlwaysClause(ltlsnfParser::AlwaysClauseContext *ctx) = 0;
  virtual void exitAlwaysClause(ltlsnfParser::AlwaysClauseContext *ctx) = 0;

  virtual void enterTemporalClause(ltlsnfParser::TemporalClauseContext *ctx) = 0;
  virtual void exitTemporalClause(ltlsnfParser::TemporalClauseContext *ctx) = 0;

  virtual void enterPropositionalClause(ltlsnfParser::PropositionalClauseContext *ctx) = 0;
  virtual void exitPropositionalClause(ltlsnfParser::PropositionalClauseContext *ctx) = 0;

  virtual void enterStepClause(ltlsnfParser::StepClauseContext *ctx) = 0;
  virtual void exitStepClause(ltlsnfParser::StepClauseContext *ctx) = 0;

  virtual void enterSometimeClause(ltlsnfParser::SometimeClauseContext *ctx) = 0;
  virtual void exitSometimeClause(ltlsnfParser::SometimeClauseContext *ctx) = 0;

  virtual void enterLiteralList(ltlsnfParser::LiteralListContext *ctx) = 0;
  virtual void exitLiteralList(ltlsnfParser::LiteralListContext *ctx) = 0;

  virtual void enterNextLiteralList(ltlsnfParser::NextLiteralListContext *ctx) = 0;
  virtual void exitNextLiteralList(ltlsnfParser::NextLiteralListContext *ctx) = 0;

  virtual void enterLiteral(ltlsnfParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(ltlsnfParser::LiteralContext *ctx) = 0;


};

