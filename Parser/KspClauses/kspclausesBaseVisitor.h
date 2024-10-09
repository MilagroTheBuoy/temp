
// Generated from kspclauses.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "kspclausesVisitor.h"


/**
 * This class provides an empty implementation of kspclausesVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  kspclausesBaseVisitor : public kspclausesVisitor {
public:

  virtual std::any visitFile(kspclausesParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection(kspclausesParser::SectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_header(kspclausesParser::Section_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClause(kspclausesParser::ClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClause_body(kspclausesParser::Clause_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiamond_clause(kspclausesParser::Diamond_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBox_clause(kspclausesParser::Box_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassical_clause(kspclausesParser::Classical_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(kspclausesParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }


};

