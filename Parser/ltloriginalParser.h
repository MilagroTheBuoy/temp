
// Generated from ltloriginal.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  ltloriginalParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, NOT = 3, AND = 4, OR = 5, ALWAYS = 6, NEXT = 7, 
    SOMETIME = 8, UNTIL = 9, IMPLIES = 10, IFF = 11, WS = 12, IDENTIFIER = 13
  };

  enum {
    RuleStart = 0, RuleLtl_formula = 1, RuleLtl_term = 2, RuleLtl_factor = 3
  };

  explicit ltloriginalParser(antlr4::TokenStream *input);

  ltloriginalParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ltloriginalParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class Ltl_formulaContext;
  class Ltl_termContext;
  class Ltl_factorContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ltl_formulaContext *ltl_formula();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  Ltl_formulaContext : public antlr4::ParserRuleContext {
  public:
    Ltl_formulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ltl_termContext *ltl_term();
    Ltl_formulaContext *ltl_formula();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *IMPLIES();
    antlr4::tree::TerminalNode *IFF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ltl_formulaContext* ltl_formula();
  Ltl_formulaContext* ltl_formula(int precedence);
  class  Ltl_termContext : public antlr4::ParserRuleContext {
  public:
    Ltl_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ltl_factorContext *ltl_factor();
    Ltl_termContext *ltl_term();
    antlr4::tree::TerminalNode *UNTIL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ltl_termContext* ltl_term();
  Ltl_termContext* ltl_term(int precedence);
  class  Ltl_factorContext : public antlr4::ParserRuleContext {
  public:
    Ltl_factorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    Ltl_factorContext *ltl_factor();
    antlr4::tree::TerminalNode *NEXT();
    antlr4::tree::TerminalNode *ALWAYS();
    antlr4::tree::TerminalNode *SOMETIME();
    Ltl_formulaContext *ltl_formula();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ltl_factorContext* ltl_factor();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool ltl_formulaSempred(Ltl_formulaContext *_localctx, size_t predicateIndex);
  bool ltl_termSempred(Ltl_termContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

