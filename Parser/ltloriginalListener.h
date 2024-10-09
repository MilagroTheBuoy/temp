
// Generated from ltloriginal.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ltloriginalParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ltloriginalParser.
 */
class  ltloriginalListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(ltloriginalParser::StartContext *ctx) = 0;
  virtual void exitStart(ltloriginalParser::StartContext *ctx) = 0;

  virtual void enterLtl_formula(ltloriginalParser::Ltl_formulaContext *ctx) = 0;
  virtual void exitLtl_formula(ltloriginalParser::Ltl_formulaContext *ctx) = 0;

  virtual void enterLtl_term(ltloriginalParser::Ltl_termContext *ctx) = 0;
  virtual void exitLtl_term(ltloriginalParser::Ltl_termContext *ctx) = 0;

  virtual void enterLtl_factor(ltloriginalParser::Ltl_factorContext *ctx) = 0;
  virtual void exitLtl_factor(ltloriginalParser::Ltl_factorContext *ctx) = 0;


};

