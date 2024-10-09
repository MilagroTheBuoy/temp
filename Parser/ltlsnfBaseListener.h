
// Generated from ltlsnf.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ltlsnfListener.h"


/**
 * This class provides an empty implementation of ltlsnfListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ltlsnfBaseListener : public ltlsnfListener {
public:

  virtual void enterFormula(ltlsnfParser::FormulaContext * /*ctx*/) override { }
  virtual void exitFormula(ltlsnfParser::FormulaContext * /*ctx*/) override { }

  virtual void enterListOfSnfClauses(ltlsnfParser::ListOfSnfClausesContext * /*ctx*/) override { }
  virtual void exitListOfSnfClauses(ltlsnfParser::ListOfSnfClausesContext * /*ctx*/) override { }

  virtual void enterSnfClauseList(ltlsnfParser::SnfClauseListContext * /*ctx*/) override { }
  virtual void exitSnfClauseList(ltlsnfParser::SnfClauseListContext * /*ctx*/) override { }

  virtual void enterSnfClause(ltlsnfParser::SnfClauseContext * /*ctx*/) override { }
  virtual void exitSnfClause(ltlsnfParser::SnfClauseContext * /*ctx*/) override { }

  virtual void enterAlwaysClause(ltlsnfParser::AlwaysClauseContext * /*ctx*/) override { }
  virtual void exitAlwaysClause(ltlsnfParser::AlwaysClauseContext * /*ctx*/) override { }

  virtual void enterTemporalClause(ltlsnfParser::TemporalClauseContext * /*ctx*/) override { }
  virtual void exitTemporalClause(ltlsnfParser::TemporalClauseContext * /*ctx*/) override { }

  virtual void enterPropositionalClause(ltlsnfParser::PropositionalClauseContext * /*ctx*/) override { }
  virtual void exitPropositionalClause(ltlsnfParser::PropositionalClauseContext * /*ctx*/) override { }

  virtual void enterStepClause(ltlsnfParser::StepClauseContext * /*ctx*/) override { }
  virtual void exitStepClause(ltlsnfParser::StepClauseContext * /*ctx*/) override { }

  virtual void enterSometimeClause(ltlsnfParser::SometimeClauseContext * /*ctx*/) override { }
  virtual void exitSometimeClause(ltlsnfParser::SometimeClauseContext * /*ctx*/) override { }

  virtual void enterLiteralList(ltlsnfParser::LiteralListContext * /*ctx*/) override { }
  virtual void exitLiteralList(ltlsnfParser::LiteralListContext * /*ctx*/) override { }

  virtual void enterNextLiteralList(ltlsnfParser::NextLiteralListContext * /*ctx*/) override { }
  virtual void exitNextLiteralList(ltlsnfParser::NextLiteralListContext * /*ctx*/) override { }

  virtual void enterLiteral(ltlsnfParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(ltlsnfParser::LiteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

