
// Generated from kspclauses.g4 by ANTLR 4.13.0


#include "kspclausesListener.h"

#include "kspclausesParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct KspclausesParserStaticData final {
  KspclausesParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  KspclausesParserStaticData(const KspclausesParserStaticData&) = delete;
  KspclausesParserStaticData(KspclausesParserStaticData&&) = delete;
  KspclausesParserStaticData& operator=(const KspclausesParserStaticData&) = delete;
  KspclausesParserStaticData& operator=(KspclausesParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag kspclausesParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
KspclausesParserStaticData *kspclausesParserStaticData = nullptr;

void kspclausesParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (kspclausesParserStaticData != nullptr) {
    return;
  }
#else
  assert(kspclausesParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<KspclausesParserStaticData>(
    std::vector<std::string>{
      "file", "section", "section_header", "clause", "clause_body", "diamond_clause", 
      "box_clause", "classical_clause", "term"
    },
    std::vector<std::string>{
      "", "'('", "','", "')'", "'['", "'].'", "'=>'", "'box'", "'|'", "", 
      "", "'~'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "SECTION_NAME", "INT", "NOT", 
      "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,78,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,1,0,5,0,20,8,0,10,0,12,0,23,9,0,1,0,1,0,1,1,1,1,5,1,29,8,
  	1,10,1,12,1,32,9,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,4,1,4,1,4,3,4,53,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,
  	1,6,1,6,1,7,1,7,1,7,5,7,68,8,7,10,7,12,7,71,9,7,1,8,3,8,74,8,8,1,8,1,
  	8,1,8,0,0,9,0,2,4,6,8,10,12,14,16,0,0,74,0,21,1,0,0,0,2,26,1,0,0,0,4,
  	33,1,0,0,0,6,35,1,0,0,0,8,52,1,0,0,0,10,54,1,0,0,0,12,60,1,0,0,0,14,64,
  	1,0,0,0,16,73,1,0,0,0,18,20,3,2,1,0,19,18,1,0,0,0,20,23,1,0,0,0,21,19,
  	1,0,0,0,21,22,1,0,0,0,22,24,1,0,0,0,23,21,1,0,0,0,24,25,5,0,0,1,25,1,
  	1,0,0,0,26,30,3,4,2,0,27,29,3,6,3,0,28,27,1,0,0,0,29,32,1,0,0,0,30,28,
  	1,0,0,0,30,31,1,0,0,0,31,3,1,0,0,0,32,30,1,0,0,0,33,34,5,9,0,0,34,5,1,
  	0,0,0,35,36,5,1,0,0,36,37,5,10,0,0,37,38,5,2,0,0,38,39,5,10,0,0,39,40,
  	5,3,0,0,40,41,5,4,0,0,41,42,5,10,0,0,42,43,5,2,0,0,43,44,5,10,0,0,44,
  	45,5,5,0,0,45,46,3,16,8,0,46,47,5,6,0,0,47,48,3,8,4,0,48,7,1,0,0,0,49,
  	53,3,12,6,0,50,53,3,10,5,0,51,53,3,14,7,0,52,49,1,0,0,0,52,50,1,0,0,0,
  	52,51,1,0,0,0,53,9,1,0,0,0,54,55,5,11,0,0,55,56,5,7,0,0,56,57,5,10,0,
  	0,57,58,5,11,0,0,58,59,3,16,8,0,59,11,1,0,0,0,60,61,5,7,0,0,61,62,5,10,
  	0,0,62,63,3,16,8,0,63,13,1,0,0,0,64,69,3,16,8,0,65,66,5,8,0,0,66,68,3,
  	16,8,0,67,65,1,0,0,0,68,71,1,0,0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,15,
  	1,0,0,0,71,69,1,0,0,0,72,74,5,11,0,0,73,72,1,0,0,0,73,74,1,0,0,0,74,75,
  	1,0,0,0,75,76,5,12,0,0,76,17,1,0,0,0,5,21,30,52,69,73
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  kspclausesParserStaticData = staticData.release();
}

}

kspclausesParser::kspclausesParser(TokenStream *input) : kspclausesParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

kspclausesParser::kspclausesParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  kspclausesParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *kspclausesParserStaticData->atn, kspclausesParserStaticData->decisionToDFA, kspclausesParserStaticData->sharedContextCache, options);
}

kspclausesParser::~kspclausesParser() {
  delete _interpreter;
}

const atn::ATN& kspclausesParser::getATN() const {
  return *kspclausesParserStaticData->atn;
}

std::string kspclausesParser::getGrammarFileName() const {
  return "kspclauses.g4";
}

const std::vector<std::string>& kspclausesParser::getRuleNames() const {
  return kspclausesParserStaticData->ruleNames;
}

const dfa::Vocabulary& kspclausesParser::getVocabulary() const {
  return kspclausesParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView kspclausesParser::getSerializedATN() const {
  return kspclausesParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

kspclausesParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* kspclausesParser::FileContext::EOF() {
  return getToken(kspclausesParser::EOF, 0);
}

std::vector<kspclausesParser::SectionContext *> kspclausesParser::FileContext::section() {
  return getRuleContexts<kspclausesParser::SectionContext>();
}

kspclausesParser::SectionContext* kspclausesParser::FileContext::section(size_t i) {
  return getRuleContext<kspclausesParser::SectionContext>(i);
}


size_t kspclausesParser::FileContext::getRuleIndex() const {
  return kspclausesParser::RuleFile;
}

void kspclausesParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void kspclausesParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

kspclausesParser::FileContext* kspclausesParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, kspclausesParser::RuleFile);
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
    setState(21);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == kspclausesParser::SECTION_NAME) {
      setState(18);
      section();
      setState(23);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(24);
    match(kspclausesParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SectionContext ------------------------------------------------------------------

kspclausesParser::SectionContext::SectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

kspclausesParser::Section_headerContext* kspclausesParser::SectionContext::section_header() {
  return getRuleContext<kspclausesParser::Section_headerContext>(0);
}

std::vector<kspclausesParser::ClauseContext *> kspclausesParser::SectionContext::clause() {
  return getRuleContexts<kspclausesParser::ClauseContext>();
}

kspclausesParser::ClauseContext* kspclausesParser::SectionContext::clause(size_t i) {
  return getRuleContext<kspclausesParser::ClauseContext>(i);
}


size_t kspclausesParser::SectionContext::getRuleIndex() const {
  return kspclausesParser::RuleSection;
}

void kspclausesParser::SectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection(this);
}

void kspclausesParser::SectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection(this);
}

kspclausesParser::SectionContext* kspclausesParser::section() {
  SectionContext *_localctx = _tracker.createInstance<SectionContext>(_ctx, getState());
  enterRule(_localctx, 2, kspclausesParser::RuleSection);
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
    setState(26);
    section_header();
    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == kspclausesParser::T__0) {
      setState(27);
      clause();
      setState(32);
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

//----------------- Section_headerContext ------------------------------------------------------------------

kspclausesParser::Section_headerContext::Section_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* kspclausesParser::Section_headerContext::SECTION_NAME() {
  return getToken(kspclausesParser::SECTION_NAME, 0);
}


size_t kspclausesParser::Section_headerContext::getRuleIndex() const {
  return kspclausesParser::RuleSection_header;
}

void kspclausesParser::Section_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_header(this);
}

void kspclausesParser::Section_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_header(this);
}

kspclausesParser::Section_headerContext* kspclausesParser::section_header() {
  Section_headerContext *_localctx = _tracker.createInstance<Section_headerContext>(_ctx, getState());
  enterRule(_localctx, 4, kspclausesParser::RuleSection_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(kspclausesParser::SECTION_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClauseContext ------------------------------------------------------------------

kspclausesParser::ClauseContext::ClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> kspclausesParser::ClauseContext::INT() {
  return getTokens(kspclausesParser::INT);
}

tree::TerminalNode* kspclausesParser::ClauseContext::INT(size_t i) {
  return getToken(kspclausesParser::INT, i);
}

kspclausesParser::TermContext* kspclausesParser::ClauseContext::term() {
  return getRuleContext<kspclausesParser::TermContext>(0);
}

kspclausesParser::Clause_bodyContext* kspclausesParser::ClauseContext::clause_body() {
  return getRuleContext<kspclausesParser::Clause_bodyContext>(0);
}


size_t kspclausesParser::ClauseContext::getRuleIndex() const {
  return kspclausesParser::RuleClause;
}

void kspclausesParser::ClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClause(this);
}

void kspclausesParser::ClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClause(this);
}

kspclausesParser::ClauseContext* kspclausesParser::clause() {
  ClauseContext *_localctx = _tracker.createInstance<ClauseContext>(_ctx, getState());
  enterRule(_localctx, 6, kspclausesParser::RuleClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(kspclausesParser::T__0);
    setState(36);
    match(kspclausesParser::INT);
    setState(37);
    match(kspclausesParser::T__1);
    setState(38);
    match(kspclausesParser::INT);
    setState(39);
    match(kspclausesParser::T__2);
    setState(40);
    match(kspclausesParser::T__3);
    setState(41);
    match(kspclausesParser::INT);
    setState(42);
    match(kspclausesParser::T__1);
    setState(43);
    match(kspclausesParser::INT);
    setState(44);
    match(kspclausesParser::T__4);
    setState(45);
    term();
    setState(46);
    match(kspclausesParser::T__5);
    setState(47);
    clause_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Clause_bodyContext ------------------------------------------------------------------

kspclausesParser::Clause_bodyContext::Clause_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

kspclausesParser::Box_clauseContext* kspclausesParser::Clause_bodyContext::box_clause() {
  return getRuleContext<kspclausesParser::Box_clauseContext>(0);
}

kspclausesParser::Diamond_clauseContext* kspclausesParser::Clause_bodyContext::diamond_clause() {
  return getRuleContext<kspclausesParser::Diamond_clauseContext>(0);
}

kspclausesParser::Classical_clauseContext* kspclausesParser::Clause_bodyContext::classical_clause() {
  return getRuleContext<kspclausesParser::Classical_clauseContext>(0);
}


size_t kspclausesParser::Clause_bodyContext::getRuleIndex() const {
  return kspclausesParser::RuleClause_body;
}

void kspclausesParser::Clause_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClause_body(this);
}

void kspclausesParser::Clause_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClause_body(this);
}

kspclausesParser::Clause_bodyContext* kspclausesParser::clause_body() {
  Clause_bodyContext *_localctx = _tracker.createInstance<Clause_bodyContext>(_ctx, getState());
  enterRule(_localctx, 8, kspclausesParser::RuleClause_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(52);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(49);
      box_clause();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(50);
      diamond_clause();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(51);
      classical_clause();
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

//----------------- Diamond_clauseContext ------------------------------------------------------------------

kspclausesParser::Diamond_clauseContext::Diamond_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> kspclausesParser::Diamond_clauseContext::NOT() {
  return getTokens(kspclausesParser::NOT);
}

tree::TerminalNode* kspclausesParser::Diamond_clauseContext::NOT(size_t i) {
  return getToken(kspclausesParser::NOT, i);
}

tree::TerminalNode* kspclausesParser::Diamond_clauseContext::INT() {
  return getToken(kspclausesParser::INT, 0);
}

kspclausesParser::TermContext* kspclausesParser::Diamond_clauseContext::term() {
  return getRuleContext<kspclausesParser::TermContext>(0);
}


size_t kspclausesParser::Diamond_clauseContext::getRuleIndex() const {
  return kspclausesParser::RuleDiamond_clause;
}

void kspclausesParser::Diamond_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiamond_clause(this);
}

void kspclausesParser::Diamond_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiamond_clause(this);
}

kspclausesParser::Diamond_clauseContext* kspclausesParser::diamond_clause() {
  Diamond_clauseContext *_localctx = _tracker.createInstance<Diamond_clauseContext>(_ctx, getState());
  enterRule(_localctx, 10, kspclausesParser::RuleDiamond_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(kspclausesParser::NOT);
    setState(55);
    match(kspclausesParser::T__6);
    setState(56);
    match(kspclausesParser::INT);
    setState(57);
    match(kspclausesParser::NOT);
    setState(58);
    term();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Box_clauseContext ------------------------------------------------------------------

kspclausesParser::Box_clauseContext::Box_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* kspclausesParser::Box_clauseContext::INT() {
  return getToken(kspclausesParser::INT, 0);
}

kspclausesParser::TermContext* kspclausesParser::Box_clauseContext::term() {
  return getRuleContext<kspclausesParser::TermContext>(0);
}


size_t kspclausesParser::Box_clauseContext::getRuleIndex() const {
  return kspclausesParser::RuleBox_clause;
}

void kspclausesParser::Box_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBox_clause(this);
}

void kspclausesParser::Box_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBox_clause(this);
}

kspclausesParser::Box_clauseContext* kspclausesParser::box_clause() {
  Box_clauseContext *_localctx = _tracker.createInstance<Box_clauseContext>(_ctx, getState());
  enterRule(_localctx, 12, kspclausesParser::RuleBox_clause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(kspclausesParser::T__6);
    setState(61);
    match(kspclausesParser::INT);
    setState(62);
    term();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Classical_clauseContext ------------------------------------------------------------------

kspclausesParser::Classical_clauseContext::Classical_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<kspclausesParser::TermContext *> kspclausesParser::Classical_clauseContext::term() {
  return getRuleContexts<kspclausesParser::TermContext>();
}

kspclausesParser::TermContext* kspclausesParser::Classical_clauseContext::term(size_t i) {
  return getRuleContext<kspclausesParser::TermContext>(i);
}


size_t kspclausesParser::Classical_clauseContext::getRuleIndex() const {
  return kspclausesParser::RuleClassical_clause;
}

void kspclausesParser::Classical_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassical_clause(this);
}

void kspclausesParser::Classical_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassical_clause(this);
}

kspclausesParser::Classical_clauseContext* kspclausesParser::classical_clause() {
  Classical_clauseContext *_localctx = _tracker.createInstance<Classical_clauseContext>(_ctx, getState());
  enterRule(_localctx, 14, kspclausesParser::RuleClassical_clause);
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
    setState(64);
    term();
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == kspclausesParser::T__7) {
      setState(65);
      match(kspclausesParser::T__7);
      setState(66);
      term();
      setState(71);
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

//----------------- TermContext ------------------------------------------------------------------

kspclausesParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* kspclausesParser::TermContext::ID() {
  return getToken(kspclausesParser::ID, 0);
}

tree::TerminalNode* kspclausesParser::TermContext::NOT() {
  return getToken(kspclausesParser::NOT, 0);
}


size_t kspclausesParser::TermContext::getRuleIndex() const {
  return kspclausesParser::RuleTerm;
}

void kspclausesParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void kspclausesParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<kspclausesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

kspclausesParser::TermContext* kspclausesParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 16, kspclausesParser::RuleTerm);
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
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == kspclausesParser::NOT) {
      setState(72);
      match(kspclausesParser::NOT);
    }
    setState(75);
    match(kspclausesParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void kspclausesParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  kspclausesParserInitialize();
#else
  ::antlr4::internal::call_once(kspclausesParserOnceFlag, kspclausesParserInitialize);
#endif
}
