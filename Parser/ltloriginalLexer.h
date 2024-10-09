
// Generated from ltloriginal.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  ltloriginalLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, NOT = 3, AND = 4, OR = 5, ALWAYS = 6, NEXT = 7, 
    SOMETIME = 8, UNTIL = 9, IMPLIES = 10, IFF = 11, WS = 12, IDENTIFIER = 13
  };

  explicit ltloriginalLexer(antlr4::CharStream *input);

  ~ltloriginalLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

