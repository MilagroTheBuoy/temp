
// Generated from ltloriginal.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ltloriginalListener.h"


/**
 * This class provides an empty implementation of ltloriginalListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ltloriginalBaseListener : public ltloriginalListener {
public:

  virtual void enterStart(ltloriginalParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(ltloriginalParser::StartContext * /*ctx*/) override { }

  virtual void enterLtl_formula(ltloriginalParser::Ltl_formulaContext * /*ctx*/) override { }
  virtual void exitLtl_formula(ltloriginalParser::Ltl_formulaContext * /*ctx*/) override { }

  virtual void enterLtl_term(ltloriginalParser::Ltl_termContext * /*ctx*/) override { }
  virtual void exitLtl_term(ltloriginalParser::Ltl_termContext * /*ctx*/) override { }

  virtual void enterLtl_factor(ltloriginalParser::Ltl_factorContext * /*ctx*/) override { }
  virtual void exitLtl_factor(ltloriginalParser::Ltl_factorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

