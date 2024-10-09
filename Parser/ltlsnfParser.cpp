
// Generated from ltlsnf.g4 by ANTLR 4.13.0


#include "ltlsnfListener.h"

#include "ltlsnfParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LtlsnfParserStaticData final {
  LtlsnfParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LtlsnfParserStaticData(const LtlsnfParserStaticData&) = delete;
  LtlsnfParserStaticData(LtlsnfParserStaticData&&) = delete;
  LtlsnfParserStaticData& operator=(const LtlsnfParserStaticData&) = delete;
  LtlsnfParserStaticData& operator=(LtlsnfParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ltlsnfParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LtlsnfParserStaticData *ltlsnfParserStaticData = nullptr;

void ltlsnfParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ltlsnfParserStaticData != nullptr) {
    return;
  }
#else
  assert(ltlsnfParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LtlsnfParserStaticData>(
    std::vector<std::string>{
      "formula", "listOfSnfClauses", "snfClauseList", "snfClause", "alwaysClause", 
      "temporalClause", "propositionalClause", "stepClause", "sometimeClause", 
      "literalList", "nextLiteralList", "literal"
    },
    std::vector<std::string>{
      "", "'.'", "'('", "')'", "'['", "']'", "','", "'not'", "'and'", "'or'", 
      "'always'", "'next'", "'sometime'"
    },
    std::vector<std::string>{
      "", "", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "COMMA", "NOT", "AND", 
      "OR", "ALWAYS", "NEXT", "SOMETIME", "WS", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,14,117,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,3,1,33,8,1,1,1,1,1,1,2,1,2,1,2,5,2,40,8,2,10,2,12,2,43,9,2,1,3,1,
  	3,3,3,47,8,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,3,5,57,8,5,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,5,9,90,8,9,10,9,12,9,93,9,9,1,
  	10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,105,8,10,10,10,12,
  	10,108,9,10,1,11,1,11,1,11,1,11,1,11,3,11,115,8,11,1,11,0,0,12,0,2,4,
  	6,8,10,12,14,16,18,20,22,0,0,112,0,24,1,0,0,0,2,30,1,0,0,0,4,36,1,0,0,
  	0,6,46,1,0,0,0,8,48,1,0,0,0,10,56,1,0,0,0,12,58,1,0,0,0,14,65,1,0,0,0,
  	16,74,1,0,0,0,18,86,1,0,0,0,20,94,1,0,0,0,22,114,1,0,0,0,24,25,5,8,0,
  	0,25,26,5,2,0,0,26,27,3,2,1,0,27,28,5,3,0,0,28,29,5,1,0,0,29,1,1,0,0,
  	0,30,32,5,4,0,0,31,33,3,4,2,0,32,31,1,0,0,0,32,33,1,0,0,0,33,34,1,0,0,
  	0,34,35,5,5,0,0,35,3,1,0,0,0,36,41,3,6,3,0,37,38,5,6,0,0,38,40,3,6,3,
  	0,39,37,1,0,0,0,40,43,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,5,1,0,0,
  	0,43,41,1,0,0,0,44,47,3,8,4,0,45,47,3,12,6,0,46,44,1,0,0,0,46,45,1,0,
  	0,0,47,7,1,0,0,0,48,49,5,10,0,0,49,50,5,2,0,0,50,51,3,10,5,0,51,52,5,
  	3,0,0,52,9,1,0,0,0,53,57,3,12,6,0,54,57,3,14,7,0,55,57,3,16,8,0,56,53,
  	1,0,0,0,56,54,1,0,0,0,56,55,1,0,0,0,57,11,1,0,0,0,58,59,5,9,0,0,59,60,
  	5,2,0,0,60,61,5,4,0,0,61,62,3,18,9,0,62,63,5,5,0,0,63,64,5,3,0,0,64,13,
  	1,0,0,0,65,66,5,9,0,0,66,67,5,2,0,0,67,68,5,4,0,0,68,69,3,18,9,0,69,70,
  	5,6,0,0,70,71,3,20,10,0,71,72,5,5,0,0,72,73,5,3,0,0,73,15,1,0,0,0,74,
  	75,5,9,0,0,75,76,5,2,0,0,76,77,5,4,0,0,77,78,3,18,9,0,78,79,5,6,0,0,79,
  	80,5,12,0,0,80,81,5,2,0,0,81,82,3,22,11,0,82,83,5,3,0,0,83,84,5,5,0,0,
  	84,85,5,3,0,0,85,17,1,0,0,0,86,91,3,22,11,0,87,88,5,6,0,0,88,90,3,22,
  	11,0,89,87,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,19,1,
  	0,0,0,93,91,1,0,0,0,94,95,5,11,0,0,95,96,5,2,0,0,96,97,3,22,11,0,97,106,
  	5,3,0,0,98,99,5,6,0,0,99,100,5,11,0,0,100,101,5,2,0,0,101,102,3,22,11,
  	0,102,103,5,3,0,0,103,105,1,0,0,0,104,98,1,0,0,0,105,108,1,0,0,0,106,
  	104,1,0,0,0,106,107,1,0,0,0,107,21,1,0,0,0,108,106,1,0,0,0,109,110,5,
  	7,0,0,110,111,5,2,0,0,111,112,5,14,0,0,112,115,5,3,0,0,113,115,5,14,0,
  	0,114,109,1,0,0,0,114,113,1,0,0,0,115,23,1,0,0,0,7,32,41,46,56,91,106,
  	114
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ltlsnfParserStaticData = staticData.release();
}

}

ltlsnfParser::ltlsnfParser(TokenStream *input) : ltlsnfParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ltlsnfParser::ltlsnfParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ltlsnfParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ltlsnfParserStaticData->atn, ltlsnfParserStaticData->decisionToDFA, ltlsnfParserStaticData->sharedContextCache, options);
}

ltlsnfParser::~ltlsnfParser() {
  delete _interpreter;
}

const atn::ATN& ltlsnfParser::getATN() const {
  return *ltlsnfParserStaticData->atn;
}

std::string ltlsnfParser::getGrammarFileName() const {
  return "ltlsnf.g4";
}

const std::vector<std::string>& ltlsnfParser::getRuleNames() const {
  return ltlsnfParserStaticData->ruleNames;
}

const dfa::Vocabulary& ltlsnfParser::getVocabulary() const {
  return ltlsnfParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ltlsnfParser::getSerializedATN() const {
  return ltlsnfParserStaticData->serializedATN;
}


//----------------- FormulaContext ------------------------------------------------------------------

ltlsnfParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltlsnfParser::FormulaContext::AND() {
  return getToken(ltlsnfParser::AND, 0);
}

tree::TerminalNode* ltlsnfParser::FormulaContext::LPAREN() {
  return getToken(ltlsnfParser::LPAREN, 0);
}

ltlsnfParser::ListOfSnfClausesContext* ltlsnfParser::FormulaContext::listOfSnfClauses() {
  return getRuleContext<ltlsnfParser::ListOfSnfClausesContext>(0);
}

tree::TerminalNode* ltlsnfParser::FormulaContext::RPAREN() {
  return getToken(ltlsnfParser::RPAREN, 0);
}


size_t ltlsnfParser::FormulaContext::getRuleIndex() const {
  return ltlsnfParser::RuleFormula;
}

void ltlsnfParser::FormulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula(this);
}

void ltlsnfParser::FormulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula(this);
}

ltlsnfParser::FormulaContext* ltlsnfParser::formula() {
  FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, getState());
  enterRule(_localctx, 0, ltlsnfParser::RuleFormula);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    match(ltlsnfParser::AND);
    setState(25);
    match(ltlsnfParser::LPAREN);
    setState(26);
    listOfSnfClauses();
    setState(27);
    match(ltlsnfParser::RPAREN);
    setState(28);
    match(ltlsnfParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListOfSnfClausesContext ------------------------------------------------------------------

ltlsnfParser::ListOfSnfClausesContext::ListOfSnfClausesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltlsnfParser::ListOfSnfClausesContext::LBRACK() {
  return getToken(ltlsnfParser::LBRACK, 0);
}

tree::TerminalNode* ltlsnfParser::ListOfSnfClausesContext::RBRACK() {
  return getToken(ltlsnfParser::RBRACK, 0);
}

ltlsnfParser::SnfClauseListContext* ltlsnfParser::ListOfSnfClausesContext::snfClauseList() {
  return getRuleContext<ltlsnfParser::SnfClauseListContext>(0);
}


size_t ltlsnfParser::ListOfSnfClausesContext::getRuleIndex() const {
  return ltlsnfParser::RuleListOfSnfClauses;
}

void ltlsnfParser::ListOfSnfClausesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListOfSnfClauses(this);
}

void ltlsnfParser::ListOfSnfClausesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListOfSnfClauses(this);
}

ltlsnfParser::ListOfSnfClausesContext* ltlsnfParser::listOfSnfClauses() {
  ListOfSnfClausesContext *_localctx = _tracker.createInstance<ListOfSnfClausesContext>(_ctx, getState());
  enterRule(_localctx, 2, ltlsnfParser::RuleListOfSnfClauses);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(ltlsnfParser::LBRACK);
    setState(32);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ltlsnfParser::OR

    || _la == ltlsnfParser::ALWAYS) {
      setState(31);
      snfClauseList();
    }
    setState(34);
    match(ltlsnfParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SnfClauseListContext ------------------------------------------------------------------

ltlsnfParser::SnfClauseListContext::SnfClauseListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ltlsnfParser::SnfClauseContext *> ltlsnfParser::SnfClauseListContext::snfClause() {
  return getRuleContexts<ltlsnfParser::SnfClauseContext>();
}

ltlsnfParser::SnfClauseContext* ltlsnfParser::SnfClauseListContext::snfClause(size_t i) {
  return getRuleContext<ltlsnfParser::SnfClauseContext>(i);
}

std::vector<tree::TerminalNode *> ltlsnfParser::SnfClauseListContext::COMMA() {
  return getTokens(ltlsnfParser::COMMA);
}

tree::TerminalNode* ltlsnfParser::SnfClauseListContext::COMMA(size_t i) {
  return getToken(ltlsnfParser::COMMA, i);
}


size_t ltlsnfParser::SnfClauseListContext::getRuleIndex() const {
  return ltlsnfParser::RuleSnfClauseList;
}

void ltlsnfParser::SnfClauseListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSnfClauseList(this);
}

void ltlsnfParser::SnfClauseListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSnfClauseList(this);
}

ltlsnfParser::SnfClauseListContext* ltlsnfParser::snfClauseList() {
  SnfClauseListContext *_localctx = _tracker.createInstance<SnfClauseListContext>(_ctx, getState());
  enterRule(_localctx, 4, ltlsnfParser::RuleSnfClauseList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    snfClause();
    setState(41);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ltlsnfParser::COMMA) {
      setState(37);
      match(ltlsnfParser::COMMA);
      setState(38);
      snfClause();
      setState(43);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SnfClauseContext ------------------------------------------------------------------

ltlsnfParser::SnfClauseContext::SnfClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ltlsnfParser::AlwaysClauseContext* ltlsnfParser::SnfClauseContext::alwaysClause() {
  return getRuleContext<ltlsnfParser::AlwaysClauseContext>(0);
}

ltlsnfParser::PropositionalClauseContext* ltlsnfParser::SnfClauseContext::propositionalClause() {
  return getRuleContext<ltlsnfParser::PropositionalClauseContext>(0);
}


size_t ltlsnfParser::SnfClauseContext::getRuleIndex() const {
  return ltlsnfParser::RuleSnfClause;
}

void ltlsnfParser::SnfClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSnfClause(this);
}

void ltlsnfParser::SnfClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSnfClause(this);
}

ltlsnfParser::SnfClauseContext* ltlsnfParser::snfClause() {
  SnfClauseContext *_localctx = _tracker.createInstance<SnfClauseContext>(_ctx, getState());
  enterRule(_localctx, 6, ltlsnfParser::RuleSnfClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ltlsnfParser::ALWAYS: {
        enterOuterAlt(_localctx, 1);
        setState(44);
        alwaysClause();
        break;
      }

      case ltlsnfParser::OR: {
        enterOuterAlt(_localctx, 2);
        setState(45);
        propositionalClause();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlwaysClauseContext ------------------------------------------------------------------

ltlsnfParser::AlwaysClauseContext::AlwaysClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltlsnfParser::AlwaysClauseContext::ALWAYS() {
  return getToken(ltlsnfParser::ALWAYS, 0);
}

tree::TerminalNode* ltlsnfParser::AlwaysClauseContext::LPAREN() {
  return getToken(ltlsnfParser::LPAREN, 0);
}

ltlsnfParser::TemporalClauseContext* ltlsnfParser::AlwaysClauseContext::temporalClause() {
  return getRuleContext<ltlsnfParser::TemporalClauseContext>(0);
}

tree::TerminalNode* ltlsnfParser::AlwaysClauseContext::RPAREN() {
  return getToken(ltlsnfParser::RPAREN, 0);
}


size_t ltlsnfParser::AlwaysClauseContext::getRuleIndex() const {
  return ltlsnfParser::RuleAlwaysClause;
}

void ltlsnfParser::AlwaysClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlwaysClause(this);
}

void ltlsnfParser::AlwaysClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlwaysClause(this);
}

ltlsnfParser::AlwaysClauseContext* ltlsnfParser::alwaysClause() {
  AlwaysClauseContext *_localctx = _tracker.createInstance<AlwaysClauseContext>(_ctx, getState());
  enterRule(_localctx, 8, ltlsnfParser::RuleAlwaysClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(ltlsnfParser::ALWAYS);
    setState(49);
    match(ltlsnfParser::LPAREN);
    setState(50);
    temporalClause();
    setState(51);
    match(ltlsnfParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemporalClauseContext ------------------------------------------------------------------

ltlsnfParser::TemporalClauseContext::TemporalClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ltlsnfParser::PropositionalClauseContext* ltlsnfParser::TemporalClauseContext::propositionalClause() {
  return getRuleContext<ltlsnfParser::PropositionalClauseContext>(0);
}

ltlsnfParser::StepClauseContext* ltlsnfParser::TemporalClauseContext::stepClause() {
  return getRuleContext<ltlsnfParser::StepClauseContext>(0);
}

ltlsnfParser::SometimeClauseContext* ltlsnfParser::TemporalClauseContext::sometimeClause() {
  return getRuleContext<ltlsnfParser::SometimeClauseContext>(0);
}


size_t ltlsnfParser::TemporalClauseContext::getRuleIndex() const {
  return ltlsnfParser::RuleTemporalClause;
}

void ltlsnfParser::TemporalClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemporalClause(this);
}

void ltlsnfParser::TemporalClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemporalClause(this);
}

ltlsnfParser::TemporalClauseContext* ltlsnfParser::temporalClause() {
  TemporalClauseContext *_localctx = _tracker.createInstance<TemporalClauseContext>(_ctx, getState());
  enterRule(_localctx, 10, ltlsnfParser::RuleTemporalClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(53);
      propositionalClause();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(54);
      stepClause();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(55);
      sometimeClause();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropositionalClauseContext ------------------------------------------------------------------

ltlsnfParser::PropositionalClauseContext::PropositionalClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltlsnfParser::PropositionalClauseContext::OR() {
  return getToken(ltlsnfParser::OR, 0);
}

tree::TerminalNode* ltlsnfParser::PropositionalClauseContext::LPAREN() {
  return getToken(ltlsnfParser::LPAREN, 0);
}

tree::TerminalNode* ltlsnfParser::PropositionalClauseContext::LBRACK() {
  return getToken(ltlsnfParser::LBRACK, 0);
}

ltlsnfParser::LiteralListContext* ltlsnfParser::PropositionalClauseContext::literalList() {
  return getRuleContext<ltlsnfParser::LiteralListContext>(0);
}

tree::TerminalNode* ltlsnfParser::PropositionalClauseContext::RBRACK() {
  return getToken(ltlsnfParser::RBRACK, 0);
}

tree::TerminalNode* ltlsnfParser::PropositionalClauseContext::RPAREN() {
  return getToken(ltlsnfParser::RPAREN, 0);
}


size_t ltlsnfParser::PropositionalClauseContext::getRuleIndex() const {
  return ltlsnfParser::RulePropositionalClause;
}

void ltlsnfParser::PropositionalClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropositionalClause(this);
}

void ltlsnfParser::PropositionalClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropositionalClause(this);
}

ltlsnfParser::PropositionalClauseContext* ltlsnfParser::propositionalClause() {
  PropositionalClauseContext *_localctx = _tracker.createInstance<PropositionalClauseContext>(_ctx, getState());
  enterRule(_localctx, 12, ltlsnfParser::RulePropositionalClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(ltlsnfParser::OR);
    setState(59);
    match(ltlsnfParser::LPAREN);
    setState(60);
    match(ltlsnfParser::LBRACK);
    setState(61);
    literalList();
    setState(62);
    match(ltlsnfParser::RBRACK);
    setState(63);
    match(ltlsnfParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepClauseContext ------------------------------------------------------------------

ltlsnfParser::StepClauseContext::StepClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltlsnfParser::StepClauseContext::OR() {
  return getToken(ltlsnfParser::OR, 0);
}

tree::TerminalNode* ltlsnfParser::StepClauseContext::LPAREN() {
  return getToken(ltlsnfParser::LPAREN, 0);
}

tree::TerminalNode* ltlsnfParser::StepClauseContext::LBRACK() {
  return getToken(ltlsnfParser::LBRACK, 0);
}

ltlsnfParser::LiteralListContext* ltlsnfParser::StepClauseContext::literalList() {
  return getRuleContext<ltlsnfParser::LiteralListContext>(0);
}

tree::TerminalNode* ltlsnfParser::StepClauseContext::COMMA() {
  return getToken(ltlsnfParser::COMMA, 0);
}

ltlsnfParser::NextLiteralListContext* ltlsnfParser::StepClauseContext::nextLiteralList() {
  return getRuleContext<ltlsnfParser::NextLiteralListContext>(0);
}

tree::TerminalNode* ltlsnfParser::StepClauseContext::RBRACK() {
  return getToken(ltlsnfParser::RBRACK, 0);
}

tree::TerminalNode* ltlsnfParser::StepClauseContext::RPAREN() {
  return getToken(ltlsnfParser::RPAREN, 0);
}


size_t ltlsnfParser::StepClauseContext::getRuleIndex() const {
  return ltlsnfParser::RuleStepClause;
}

void ltlsnfParser::StepClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepClause(this);
}

void ltlsnfParser::StepClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepClause(this);
}

ltlsnfParser::StepClauseContext* ltlsnfParser::stepClause() {
  StepClauseContext *_localctx = _tracker.createInstance<StepClauseContext>(_ctx, getState());
  enterRule(_localctx, 14, ltlsnfParser::RuleStepClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(ltlsnfParser::OR);
    setState(66);
    match(ltlsnfParser::LPAREN);
    setState(67);
    match(ltlsnfParser::LBRACK);
    setState(68);
    literalList();
    setState(69);
    match(ltlsnfParser::COMMA);
    setState(70);
    nextLiteralList();
    setState(71);
    match(ltlsnfParser::RBRACK);
    setState(72);
    match(ltlsnfParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SometimeClauseContext ------------------------------------------------------------------

ltlsnfParser::SometimeClauseContext::SometimeClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltlsnfParser::SometimeClauseContext::OR() {
  return getToken(ltlsnfParser::OR, 0);
}

std::vector<tree::TerminalNode *> ltlsnfParser::SometimeClauseContext::LPAREN() {
  return getTokens(ltlsnfParser::LPAREN);
}

tree::TerminalNode* ltlsnfParser::SometimeClauseContext::LPAREN(size_t i) {
  return getToken(ltlsnfParser::LPAREN, i);
}

tree::TerminalNode* ltlsnfParser::SometimeClauseContext::LBRACK() {
  return getToken(ltlsnfParser::LBRACK, 0);
}

ltlsnfParser::LiteralListContext* ltlsnfParser::SometimeClauseContext::literalList() {
  return getRuleContext<ltlsnfParser::LiteralListContext>(0);
}

tree::TerminalNode* ltlsnfParser::SometimeClauseContext::COMMA() {
  return getToken(ltlsnfParser::COMMA, 0);
}

tree::TerminalNode* ltlsnfParser::SometimeClauseContext::SOMETIME() {
  return getToken(ltlsnfParser::SOMETIME, 0);
}

ltlsnfParser::LiteralContext* ltlsnfParser::SometimeClauseContext::literal() {
  return getRuleContext<ltlsnfParser::LiteralContext>(0);
}

std::vector<tree::TerminalNode *> ltlsnfParser::SometimeClauseContext::RPAREN() {
  return getTokens(ltlsnfParser::RPAREN);
}

tree::TerminalNode* ltlsnfParser::SometimeClauseContext::RPAREN(size_t i) {
  return getToken(ltlsnfParser::RPAREN, i);
}

tree::TerminalNode* ltlsnfParser::SometimeClauseContext::RBRACK() {
  return getToken(ltlsnfParser::RBRACK, 0);
}


size_t ltlsnfParser::SometimeClauseContext::getRuleIndex() const {
  return ltlsnfParser::RuleSometimeClause;
}

void ltlsnfParser::SometimeClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSometimeClause(this);
}

void ltlsnfParser::SometimeClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSometimeClause(this);
}

ltlsnfParser::SometimeClauseContext* ltlsnfParser::sometimeClause() {
  SometimeClauseContext *_localctx = _tracker.createInstance<SometimeClauseContext>(_ctx, getState());
  enterRule(_localctx, 16, ltlsnfParser::RuleSometimeClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(ltlsnfParser::OR);
    setState(75);
    match(ltlsnfParser::LPAREN);
    setState(76);
    match(ltlsnfParser::LBRACK);
    setState(77);
    literalList();
    setState(78);
    match(ltlsnfParser::COMMA);
    setState(79);
    match(ltlsnfParser::SOMETIME);
    setState(80);
    match(ltlsnfParser::LPAREN);
    setState(81);
    literal();
    setState(82);
    match(ltlsnfParser::RPAREN);
    setState(83);
    match(ltlsnfParser::RBRACK);
    setState(84);
    match(ltlsnfParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralListContext ------------------------------------------------------------------

ltlsnfParser::LiteralListContext::LiteralListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ltlsnfParser::LiteralContext *> ltlsnfParser::LiteralListContext::literal() {
  return getRuleContexts<ltlsnfParser::LiteralContext>();
}

ltlsnfParser::LiteralContext* ltlsnfParser::LiteralListContext::literal(size_t i) {
  return getRuleContext<ltlsnfParser::LiteralContext>(i);
}

std::vector<tree::TerminalNode *> ltlsnfParser::LiteralListContext::COMMA() {
  return getTokens(ltlsnfParser::COMMA);
}

tree::TerminalNode* ltlsnfParser::LiteralListContext::COMMA(size_t i) {
  return getToken(ltlsnfParser::COMMA, i);
}


size_t ltlsnfParser::LiteralListContext::getRuleIndex() const {
  return ltlsnfParser::RuleLiteralList;
}

void ltlsnfParser::LiteralListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralList(this);
}

void ltlsnfParser::LiteralListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralList(this);
}

ltlsnfParser::LiteralListContext* ltlsnfParser::literalList() {
  LiteralListContext *_localctx = _tracker.createInstance<LiteralListContext>(_ctx, getState());
  enterRule(_localctx, 18, ltlsnfParser::RuleLiteralList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(86);
    literal();
    setState(91);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(87);
        match(ltlsnfParser::COMMA);
        setState(88);
        literal(); 
      }
      setState(93);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NextLiteralListContext ------------------------------------------------------------------

ltlsnfParser::NextLiteralListContext::NextLiteralListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ltlsnfParser::NextLiteralListContext::NEXT() {
  return getTokens(ltlsnfParser::NEXT);
}

tree::TerminalNode* ltlsnfParser::NextLiteralListContext::NEXT(size_t i) {
  return getToken(ltlsnfParser::NEXT, i);
}

std::vector<tree::TerminalNode *> ltlsnfParser::NextLiteralListContext::LPAREN() {
  return getTokens(ltlsnfParser::LPAREN);
}

tree::TerminalNode* ltlsnfParser::NextLiteralListContext::LPAREN(size_t i) {
  return getToken(ltlsnfParser::LPAREN, i);
}

std::vector<ltlsnfParser::LiteralContext *> ltlsnfParser::NextLiteralListContext::literal() {
  return getRuleContexts<ltlsnfParser::LiteralContext>();
}

ltlsnfParser::LiteralContext* ltlsnfParser::NextLiteralListContext::literal(size_t i) {
  return getRuleContext<ltlsnfParser::LiteralContext>(i);
}

std::vector<tree::TerminalNode *> ltlsnfParser::NextLiteralListContext::RPAREN() {
  return getTokens(ltlsnfParser::RPAREN);
}

tree::TerminalNode* ltlsnfParser::NextLiteralListContext::RPAREN(size_t i) {
  return getToken(ltlsnfParser::RPAREN, i);
}

std::vector<tree::TerminalNode *> ltlsnfParser::NextLiteralListContext::COMMA() {
  return getTokens(ltlsnfParser::COMMA);
}

tree::TerminalNode* ltlsnfParser::NextLiteralListContext::COMMA(size_t i) {
  return getToken(ltlsnfParser::COMMA, i);
}


size_t ltlsnfParser::NextLiteralListContext::getRuleIndex() const {
  return ltlsnfParser::RuleNextLiteralList;
}

void ltlsnfParser::NextLiteralListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNextLiteralList(this);
}

void ltlsnfParser::NextLiteralListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNextLiteralList(this);
}

ltlsnfParser::NextLiteralListContext* ltlsnfParser::nextLiteralList() {
  NextLiteralListContext *_localctx = _tracker.createInstance<NextLiteralListContext>(_ctx, getState());
  enterRule(_localctx, 20, ltlsnfParser::RuleNextLiteralList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(ltlsnfParser::NEXT);
    setState(95);
    match(ltlsnfParser::LPAREN);
    setState(96);
    literal();
    setState(97);
    match(ltlsnfParser::RPAREN);
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ltlsnfParser::COMMA) {
      setState(98);
      match(ltlsnfParser::COMMA);
      setState(99);
      match(ltlsnfParser::NEXT);
      setState(100);
      match(ltlsnfParser::LPAREN);
      setState(101);
      literal();
      setState(102);
      match(ltlsnfParser::RPAREN);
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

ltlsnfParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltlsnfParser::LiteralContext::NOT() {
  return getToken(ltlsnfParser::NOT, 0);
}

tree::TerminalNode* ltlsnfParser::LiteralContext::LPAREN() {
  return getToken(ltlsnfParser::LPAREN, 0);
}

tree::TerminalNode* ltlsnfParser::LiteralContext::IDENTIFIER() {
  return getToken(ltlsnfParser::IDENTIFIER, 0);
}

tree::TerminalNode* ltlsnfParser::LiteralContext::RPAREN() {
  return getToken(ltlsnfParser::RPAREN, 0);
}


size_t ltlsnfParser::LiteralContext::getRuleIndex() const {
  return ltlsnfParser::RuleLiteral;
}

void ltlsnfParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void ltlsnfParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltlsnfListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

ltlsnfParser::LiteralContext* ltlsnfParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 22, ltlsnfParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(114);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ltlsnfParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(109);
        match(ltlsnfParser::NOT);
        setState(110);
        match(ltlsnfParser::LPAREN);
        setState(111);
        match(ltlsnfParser::IDENTIFIER);
        setState(112);
        match(ltlsnfParser::RPAREN);
        break;
      }

      case ltlsnfParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(113);
        match(ltlsnfParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void ltlsnfParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ltlsnfParserInitialize();
#else
  ::antlr4::internal::call_once(ltlsnfParserOnceFlag, ltlsnfParserInitialize);
#endif
}
