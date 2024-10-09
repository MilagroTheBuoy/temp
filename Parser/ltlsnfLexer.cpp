
// Generated from ltlsnf.g4 by ANTLR 4.13.0


#include "ltlsnfLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LtlsnfLexerStaticData final {
  LtlsnfLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LtlsnfLexerStaticData(const LtlsnfLexerStaticData&) = delete;
  LtlsnfLexerStaticData(LtlsnfLexerStaticData&&) = delete;
  LtlsnfLexerStaticData& operator=(const LtlsnfLexerStaticData&) = delete;
  LtlsnfLexerStaticData& operator=(LtlsnfLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ltlsnflexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LtlsnfLexerStaticData *ltlsnflexerLexerStaticData = nullptr;

void ltlsnflexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ltlsnflexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(ltlsnflexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LtlsnfLexerStaticData>(
    std::vector<std::string>{
      "T__0", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "COMMA", "NOT", "AND", 
      "OR", "ALWAYS", "NEXT", "SOMETIME", "WS", "DIGIT", "LETTER", "IDENTIFIER"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,14,93,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,
  	6,1,6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,
  	1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,15,5,15,89,8,15,10,15,
  	12,15,92,9,15,0,0,16,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,23,12,25,13,27,0,29,0,31,14,1,0,3,3,0,9,10,13,13,32,32,1,0,48,57,1,
  	0,97,122,92,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,
  	21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,31,1,0,0,0,1,33,1,0,0,0,3,35,1,
  	0,0,0,5,37,1,0,0,0,7,39,1,0,0,0,9,41,1,0,0,0,11,43,1,0,0,0,13,45,1,0,
  	0,0,15,49,1,0,0,0,17,53,1,0,0,0,19,56,1,0,0,0,21,63,1,0,0,0,23,68,1,0,
  	0,0,25,77,1,0,0,0,27,81,1,0,0,0,29,83,1,0,0,0,31,85,1,0,0,0,33,34,5,46,
  	0,0,34,2,1,0,0,0,35,36,5,40,0,0,36,4,1,0,0,0,37,38,5,41,0,0,38,6,1,0,
  	0,0,39,40,5,91,0,0,40,8,1,0,0,0,41,42,5,93,0,0,42,10,1,0,0,0,43,44,5,
  	44,0,0,44,12,1,0,0,0,45,46,5,110,0,0,46,47,5,111,0,0,47,48,5,116,0,0,
  	48,14,1,0,0,0,49,50,5,97,0,0,50,51,5,110,0,0,51,52,5,100,0,0,52,16,1,
  	0,0,0,53,54,5,111,0,0,54,55,5,114,0,0,55,18,1,0,0,0,56,57,5,97,0,0,57,
  	58,5,108,0,0,58,59,5,119,0,0,59,60,5,97,0,0,60,61,5,121,0,0,61,62,5,115,
  	0,0,62,20,1,0,0,0,63,64,5,110,0,0,64,65,5,101,0,0,65,66,5,120,0,0,66,
  	67,5,116,0,0,67,22,1,0,0,0,68,69,5,115,0,0,69,70,5,111,0,0,70,71,5,109,
  	0,0,71,72,5,101,0,0,72,73,5,116,0,0,73,74,5,105,0,0,74,75,5,109,0,0,75,
  	76,5,101,0,0,76,24,1,0,0,0,77,78,7,0,0,0,78,79,1,0,0,0,79,80,6,12,0,0,
  	80,26,1,0,0,0,81,82,7,1,0,0,82,28,1,0,0,0,83,84,7,2,0,0,84,30,1,0,0,0,
  	85,90,3,29,14,0,86,89,3,29,14,0,87,89,3,27,13,0,88,86,1,0,0,0,88,87,1,
  	0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,32,1,0,0,0,92,90,1,
  	0,0,0,3,0,88,90,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ltlsnflexerLexerStaticData = staticData.release();
}

}

ltlsnfLexer::ltlsnfLexer(CharStream *input) : Lexer(input) {
  ltlsnfLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ltlsnflexerLexerStaticData->atn, ltlsnflexerLexerStaticData->decisionToDFA, ltlsnflexerLexerStaticData->sharedContextCache);
}

ltlsnfLexer::~ltlsnfLexer() {
  delete _interpreter;
}

std::string ltlsnfLexer::getGrammarFileName() const {
  return "ltlsnf.g4";
}

const std::vector<std::string>& ltlsnfLexer::getRuleNames() const {
  return ltlsnflexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ltlsnfLexer::getChannelNames() const {
  return ltlsnflexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ltlsnfLexer::getModeNames() const {
  return ltlsnflexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ltlsnfLexer::getVocabulary() const {
  return ltlsnflexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ltlsnfLexer::getSerializedATN() const {
  return ltlsnflexerLexerStaticData->serializedATN;
}

const atn::ATN& ltlsnfLexer::getATN() const {
  return *ltlsnflexerLexerStaticData->atn;
}




void ltlsnfLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ltlsnflexerLexerInitialize();
#else
  ::antlr4::internal::call_once(ltlsnflexerLexerOnceFlag, ltlsnflexerLexerInitialize);
#endif
}
