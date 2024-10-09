
// Generated from kspclauses.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "kspclausesListener.h"


/**
 * This class provides an empty implementation of kspclausesListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  kspclausesBaseListener : public kspclausesListener {
public:

  virtual void enterFile(kspclausesParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(kspclausesParser::FileContext * /*ctx*/) override { }

  virtual void enterSection(kspclausesParser::SectionContext * /*ctx*/) override { }
  virtual void exitSection(kspclausesParser::SectionContext * /*ctx*/) override { }

  virtual void enterSection_header(kspclausesParser::Section_headerContext * /*ctx*/) override { }
  virtual void exitSection_header(kspclausesParser::Section_headerContext * /*ctx*/) override { }

  virtual void enterClause(kspclausesParser::ClauseContext * /*ctx*/) override { }
  virtual void exitClause(kspclausesParser::ClauseContext * /*ctx*/) override { }

  virtual void enterClause_body(kspclausesParser::Clause_bodyContext * /*ctx*/) override { }
  virtual void exitClause_body(kspclausesParser::Clause_bodyContext * /*ctx*/) override { }

  virtual void enterDiamond_clause(kspclausesParser::Diamond_clauseContext * /*ctx*/) override { }
  virtual void exitDiamond_clause(kspclausesParser::Diamond_clauseContext * /*ctx*/) override { }

  virtual void enterBox_clause(kspclausesParser::Box_clauseContext * /*ctx*/) override { }
  virtual void exitBox_clause(kspclausesParser::Box_clauseContext * /*ctx*/) override { }

  virtual void enterClassical_clause(kspclausesParser::Classical_clauseContext * /*ctx*/) override { }
  virtual void exitClassical_clause(kspclausesParser::Classical_clauseContext * /*ctx*/) override { }

  virtual void enterTerm(kspclausesParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(kspclausesParser::TermContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

