
// Generated from ltlsnf.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  ltlsnfParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, LPAREN = 2, RPAREN = 3, LBRACK = 4, RBRACK = 5, COMMA = 6, 
    NOT = 7, AND = 8, OR = 9, ALWAYS = 10, NEXT = 11, SOMETIME = 12, WS = 13, 
    IDENTIFIER = 14
  };

  enum {
    RuleFormula = 0, RuleListOfSnfClauses = 1, RuleSnfClauseList = 2, RuleSnfClause = 3, 
    RuleAlwaysClause = 4, RuleTemporalClause = 5, RulePropositionalClause = 6, 
    RuleStepClause = 7, RuleSometimeClause = 8, RuleLiteralList = 9, RuleNextLiteralList = 10, 
    RuleLiteral = 11
  };

  explicit ltlsnfParser(antlr4::TokenStream *input);

  ltlsnfParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ltlsnfParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FormulaContext;
  class ListOfSnfClausesContext;
  class SnfClauseListContext;
  class SnfClauseContext;
  class AlwaysClauseContext;
  class TemporalClauseContext;
  class PropositionalClauseContext;
  class StepClauseContext;
  class SometimeClauseContext;
  class LiteralListContext;
  class NextLiteralListContext;
  class LiteralContext; 

  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *LPAREN();
    ListOfSnfClausesContext *listOfSnfClauses();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FormulaContext* formula();

  class  ListOfSnfClausesContext : public antlr4::ParserRuleContext {
  public:
    ListOfSnfClausesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    SnfClauseListContext *snfClauseList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ListOfSnfClausesContext* listOfSnfClauses();

  class  SnfClauseListContext : public antlr4::ParserRuleContext {
  public:
    SnfClauseListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SnfClauseContext *> snfClause();
    SnfClauseContext* snfClause(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SnfClauseListContext* snfClauseList();

  class  SnfClauseContext : public antlr4::ParserRuleContext {
  public:
    SnfClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AlwaysClauseContext *alwaysClause();
    PropositionalClauseContext *propositionalClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SnfClauseContext* snfClause();

  class  AlwaysClauseContext : public antlr4::ParserRuleContext {
  public:
    AlwaysClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALWAYS();
    antlr4::tree::TerminalNode *LPAREN();
    TemporalClauseContext *temporalClause();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AlwaysClauseContext* alwaysClause();

  class  TemporalClauseContext : public antlr4::ParserRuleContext {
  public:
    TemporalClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropositionalClauseContext *propositionalClause();
    StepClauseContext *stepClause();
    SometimeClauseContext *sometimeClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TemporalClauseContext* temporalClause();

  class  PropositionalClauseContext : public antlr4::ParserRuleContext {
  public:
    PropositionalClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *LBRACK();
    LiteralListContext *literalList();
    antlr4::tree::TerminalNode *RBRACK();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PropositionalClauseContext* propositionalClause();

  class  StepClauseContext : public antlr4::ParserRuleContext {
  public:
    StepClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *LBRACK();
    LiteralListContext *literalList();
    antlr4::tree::TerminalNode *COMMA();
    NextLiteralListContext *nextLiteralList();
    antlr4::tree::TerminalNode *RBRACK();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StepClauseContext* stepClause();

  class  SometimeClauseContext : public antlr4::ParserRuleContext {
  public:
    SometimeClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();
    std::vector<antlr4::tree::TerminalNode *> LPAREN();
    antlr4::tree::TerminalNode* LPAREN(size_t i);
    antlr4::tree::TerminalNode *LBRACK();
    LiteralListContext *literalList();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *SOMETIME();
    LiteralContext *literal();
    std::vector<antlr4::tree::TerminalNode *> RPAREN();
    antlr4::tree::TerminalNode* RPAREN(size_t i);
    antlr4::tree::TerminalNode *RBRACK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SometimeClauseContext* sometimeClause();

  class  LiteralListContext : public antlr4::ParserRuleContext {
  public:
    LiteralListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LiteralContext *> literal();
    LiteralContext* literal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralListContext* literalList();

  class  NextLiteralListContext : public antlr4::ParserRuleContext {
  public:
    NextLiteralListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEXT();
    antlr4::tree::TerminalNode* NEXT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LPAREN();
    antlr4::tree::TerminalNode* LPAREN(size_t i);
    std::vector<LiteralContext *> literal();
    LiteralContext* literal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RPAREN();
    antlr4::tree::TerminalNode* RPAREN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NextLiteralListContext* nextLiteralList();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralContext* literal();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

