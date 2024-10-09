
// Generated from ltloriginal.g4 by ANTLR 4.13.0


#include "ltloriginalListener.h"

#include "ltloriginalParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LtloriginalParserStaticData final {
  LtloriginalParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LtloriginalParserStaticData(const LtloriginalParserStaticData&) = delete;
  LtloriginalParserStaticData(LtloriginalParserStaticData&&) = delete;
  LtloriginalParserStaticData& operator=(const LtloriginalParserStaticData&) = delete;
  LtloriginalParserStaticData& operator=(LtloriginalParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ltloriginalParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LtloriginalParserStaticData *ltloriginalParserStaticData = nullptr;

void ltloriginalParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ltloriginalParserStaticData != nullptr) {
    return;
  }
#else
  assert(ltloriginalParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LtloriginalParserStaticData>(
    std::vector<std::string>{
      "start", "ltl_formula", "ltl_term", "ltl_factor"
    },
    std::vector<std::string>{
      "", "'('", "')'", "", "", "", "", "'next'"
    },
    std::vector<std::string>{
      "", "", "", "NOT", "AND", "OR", "ALWAYS", "NEXT", "SOMETIME", "UNTIL", 
      "IMPLIES", "IFF", "WS", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,58,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,27,8,1,10,1,12,1,30,9,
  	1,1,2,1,2,1,2,1,2,1,2,1,2,5,2,38,8,2,10,2,12,2,41,9,2,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,56,8,3,1,3,0,2,2,4,4,0,2,4,6,
  	0,0,63,0,8,1,0,0,0,2,11,1,0,0,0,4,31,1,0,0,0,6,55,1,0,0,0,8,9,3,2,1,0,
  	9,10,5,0,0,1,10,1,1,0,0,0,11,12,6,1,-1,0,12,13,3,4,2,0,13,28,1,0,0,0,
  	14,15,10,5,0,0,15,16,5,4,0,0,16,27,3,4,2,0,17,18,10,4,0,0,18,19,5,5,0,
  	0,19,27,3,4,2,0,20,21,10,3,0,0,21,22,5,10,0,0,22,27,3,4,2,0,23,24,10,
  	2,0,0,24,25,5,11,0,0,25,27,3,4,2,0,26,14,1,0,0,0,26,17,1,0,0,0,26,20,
  	1,0,0,0,26,23,1,0,0,0,27,30,1,0,0,0,28,26,1,0,0,0,28,29,1,0,0,0,29,3,
  	1,0,0,0,30,28,1,0,0,0,31,32,6,2,-1,0,32,33,3,6,3,0,33,39,1,0,0,0,34,35,
  	10,2,0,0,35,36,5,9,0,0,36,38,3,6,3,0,37,34,1,0,0,0,38,41,1,0,0,0,39,37,
  	1,0,0,0,39,40,1,0,0,0,40,5,1,0,0,0,41,39,1,0,0,0,42,43,5,3,0,0,43,56,
  	3,6,3,0,44,45,5,7,0,0,45,56,3,6,3,0,46,47,5,6,0,0,47,56,3,6,3,0,48,49,
  	5,8,0,0,49,56,3,6,3,0,50,51,5,1,0,0,51,52,3,2,1,0,52,53,5,2,0,0,53,56,
  	1,0,0,0,54,56,5,13,0,0,55,42,1,0,0,0,55,44,1,0,0,0,55,46,1,0,0,0,55,48,
  	1,0,0,0,55,50,1,0,0,0,55,54,1,0,0,0,56,7,1,0,0,0,4,26,28,39,55
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ltloriginalParserStaticData = staticData.release();
}

}

ltloriginalParser::ltloriginalParser(TokenStream *input) : ltloriginalParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ltloriginalParser::ltloriginalParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ltloriginalParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ltloriginalParserStaticData->atn, ltloriginalParserStaticData->decisionToDFA, ltloriginalParserStaticData->sharedContextCache, options);
}

ltloriginalParser::~ltloriginalParser() {
  delete _interpreter;
}

const atn::ATN& ltloriginalParser::getATN() const {
  return *ltloriginalParserStaticData->atn;
}

std::string ltloriginalParser::getGrammarFileName() const {
  return "ltloriginal.g4";
}

const std::vector<std::string>& ltloriginalParser::getRuleNames() const {
  return ltloriginalParserStaticData->ruleNames;
}

const dfa::Vocabulary& ltloriginalParser::getVocabulary() const {
  return ltloriginalParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ltloriginalParser::getSerializedATN() const {
  return ltloriginalParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

ltloriginalParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ltloriginalParser::Ltl_formulaContext* ltloriginalParser::StartContext::ltl_formula() {
  return getRuleContext<ltloriginalParser::Ltl_formulaContext>(0);
}

tree::TerminalNode* ltloriginalParser::StartContext::EOF() {
  return getToken(ltloriginalParser::EOF, 0);
}


size_t ltloriginalParser::StartContext::getRuleIndex() const {
  return ltloriginalParser::RuleStart;
}

void ltloriginalParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void ltloriginalParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

ltloriginalParser::StartContext* ltloriginalParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, ltloriginalParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    ltl_formula(0);
    setState(9);
    match(ltloriginalParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ltl_formulaContext ------------------------------------------------------------------

ltloriginalParser::Ltl_formulaContext::Ltl_formulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ltloriginalParser::Ltl_termContext* ltloriginalParser::Ltl_formulaContext::ltl_term() {
  return getRuleContext<ltloriginalParser::Ltl_termContext>(0);
}

ltloriginalParser::Ltl_formulaContext* ltloriginalParser::Ltl_formulaContext::ltl_formula() {
  return getRuleContext<ltloriginalParser::Ltl_formulaContext>(0);
}

tree::TerminalNode* ltloriginalParser::Ltl_formulaContext::AND() {
  return getToken(ltloriginalParser::AND, 0);
}

tree::TerminalNode* ltloriginalParser::Ltl_formulaContext::OR() {
  return getToken(ltloriginalParser::OR, 0);
}

tree::TerminalNode* ltloriginalParser::Ltl_formulaContext::IMPLIES() {
  return getToken(ltloriginalParser::IMPLIES, 0);
}

tree::TerminalNode* ltloriginalParser::Ltl_formulaContext::IFF() {
  return getToken(ltloriginalParser::IFF, 0);
}


size_t ltloriginalParser::Ltl_formulaContext::getRuleIndex() const {
  return ltloriginalParser::RuleLtl_formula;
}

void ltloriginalParser::Ltl_formulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtl_formula(this);
}

void ltloriginalParser::Ltl_formulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtl_formula(this);
}


ltloriginalParser::Ltl_formulaContext* ltloriginalParser::ltl_formula() {
   return ltl_formula(0);
}

ltloriginalParser::Ltl_formulaContext* ltloriginalParser::ltl_formula(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ltloriginalParser::Ltl_formulaContext *_localctx = _tracker.createInstance<Ltl_formulaContext>(_ctx, parentState);
  ltloriginalParser::Ltl_formulaContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ltloriginalParser::RuleLtl_formula, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(12);
    ltl_term(0);
    _ctx->stop = _input->LT(-1);
    setState(28);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(26);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Ltl_formulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl_formula);
          setState(14);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(15);
          match(ltloriginalParser::AND);
          setState(16);
          ltl_term(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Ltl_formulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl_formula);
          setState(17);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(18);
          match(ltloriginalParser::OR);
          setState(19);
          ltl_term(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Ltl_formulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl_formula);
          setState(20);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(21);
          match(ltloriginalParser::IMPLIES);
          setState(22);
          ltl_term(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<Ltl_formulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLtl_formula);
          setState(23);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(24);
          match(ltloriginalParser::IFF);
          setState(25);
          ltl_term(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(30);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Ltl_termContext ------------------------------------------------------------------

ltloriginalParser::Ltl_termContext::Ltl_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ltloriginalParser::Ltl_factorContext* ltloriginalParser::Ltl_termContext::ltl_factor() {
  return getRuleContext<ltloriginalParser::Ltl_factorContext>(0);
}

ltloriginalParser::Ltl_termContext* ltloriginalParser::Ltl_termContext::ltl_term() {
  return getRuleContext<ltloriginalParser::Ltl_termContext>(0);
}

tree::TerminalNode* ltloriginalParser::Ltl_termContext::UNTIL() {
  return getToken(ltloriginalParser::UNTIL, 0);
}


size_t ltloriginalParser::Ltl_termContext::getRuleIndex() const {
  return ltloriginalParser::RuleLtl_term;
}

void ltloriginalParser::Ltl_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtl_term(this);
}

void ltloriginalParser::Ltl_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtl_term(this);
}


ltloriginalParser::Ltl_termContext* ltloriginalParser::ltl_term() {
   return ltl_term(0);
}

ltloriginalParser::Ltl_termContext* ltloriginalParser::ltl_term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ltloriginalParser::Ltl_termContext *_localctx = _tracker.createInstance<Ltl_termContext>(_ctx, parentState);
  ltloriginalParser::Ltl_termContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, ltloriginalParser::RuleLtl_term, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(32);
    ltl_factor();
    _ctx->stop = _input->LT(-1);
    setState(39);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Ltl_termContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLtl_term);
        setState(34);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(35);
        match(ltloriginalParser::UNTIL);
        setState(36);
        ltl_factor(); 
      }
      setState(41);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Ltl_factorContext ------------------------------------------------------------------

ltloriginalParser::Ltl_factorContext::Ltl_factorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ltloriginalParser::Ltl_factorContext::NOT() {
  return getToken(ltloriginalParser::NOT, 0);
}

ltloriginalParser::Ltl_factorContext* ltloriginalParser::Ltl_factorContext::ltl_factor() {
  return getRuleContext<ltloriginalParser::Ltl_factorContext>(0);
}

tree::TerminalNode* ltloriginalParser::Ltl_factorContext::NEXT() {
  return getToken(ltloriginalParser::NEXT, 0);
}

tree::TerminalNode* ltloriginalParser::Ltl_factorContext::ALWAYS() {
  return getToken(ltloriginalParser::ALWAYS, 0);
}

tree::TerminalNode* ltloriginalParser::Ltl_factorContext::SOMETIME() {
  return getToken(ltloriginalParser::SOMETIME, 0);
}

ltloriginalParser::Ltl_formulaContext* ltloriginalParser::Ltl_factorContext::ltl_formula() {
  return getRuleContext<ltloriginalParser::Ltl_formulaContext>(0);
}

tree::TerminalNode* ltloriginalParser::Ltl_factorContext::IDENTIFIER() {
  return getToken(ltloriginalParser::IDENTIFIER, 0);
}


size_t ltloriginalParser::Ltl_factorContext::getRuleIndex() const {
  return ltloriginalParser::RuleLtl_factor;
}

void ltloriginalParser::Ltl_factorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtl_factor(this);
}

void ltloriginalParser::Ltl_factorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ltloriginalListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtl_factor(this);
}

ltloriginalParser::Ltl_factorContext* ltloriginalParser::ltl_factor() {
  Ltl_factorContext *_localctx = _tracker.createInstance<Ltl_factorContext>(_ctx, getState());
  enterRule(_localctx, 6, ltloriginalParser::RuleLtl_factor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ltloriginalParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(42);
        match(ltloriginalParser::NOT);
        setState(43);
        ltl_factor();
        break;
      }

      case ltloriginalParser::NEXT: {
        enterOuterAlt(_localctx, 2);
        setState(44);
        match(ltloriginalParser::NEXT);
        setState(45);
        ltl_factor();
        break;
      }

      case ltloriginalParser::ALWAYS: {
        enterOuterAlt(_localctx, 3);
        setState(46);
        match(ltloriginalParser::ALWAYS);
        setState(47);
        ltl_factor();
        break;
      }

      case ltloriginalParser::SOMETIME: {
        enterOuterAlt(_localctx, 4);
        setState(48);
        match(ltloriginalParser::SOMETIME);
        setState(49);
        ltl_factor();
        break;
      }

      case ltloriginalParser::T__0: {
        enterOuterAlt(_localctx, 5);
        setState(50);
        match(ltloriginalParser::T__0);
        setState(51);
        ltl_formula(0);
        setState(52);
        match(ltloriginalParser::T__1);
        break;
      }

      case ltloriginalParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 6);
        setState(54);
        match(ltloriginalParser::IDENTIFIER);
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

bool ltloriginalParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return ltl_formulaSempred(antlrcpp::downCast<Ltl_formulaContext *>(context), predicateIndex);
    case 2: return ltl_termSempred(antlrcpp::downCast<Ltl_termContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ltloriginalParser::ltl_formulaSempred(Ltl_formulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool ltloriginalParser::ltl_termSempred(Ltl_termContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void ltloriginalParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ltloriginalParserInitialize();
#else
  ::antlr4::internal::call_once(ltloriginalParserOnceFlag, ltloriginalParserInitialize);
#endif
}
