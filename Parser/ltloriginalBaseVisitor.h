
// Generated from ltloriginal.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ltloriginalVisitor.h"


/**
 * This class provides an empty implementation of ltloriginalVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ltloriginalBaseVisitor : public ltloriginalVisitor {
public:

  virtual std::any visitStart(ltloriginalParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLtl_formula(ltloriginalParser::Ltl_formulaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLtl_term(ltloriginalParser::Ltl_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLtl_factor(ltloriginalParser::Ltl_factorContext *ctx) override {
    return visitChildren(ctx);
  }


};

