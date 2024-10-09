
// Generated from ltloriginal.g4 by ANTLR 4.13.0


#include "ltlleftrecursiveLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LtlleftrecursiveLexerStaticData final {
  LtlleftrecursiveLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LtlleftrecursiveLexerStaticData(const LtlleftrecursiveLexerStaticData&) = delete;
  LtlleftrecursiveLexerStaticData(LtlleftrecursiveLexerStaticData&&) = delete;
  LtlleftrecursiveLexerStaticData& operator=(const LtlleftrecursiveLexerStaticData&) = delete;
  LtlleftrecursiveLexerStaticData& operator=(LtlleftrecursiveLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag ltlleftrecursivelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LtlleftrecursiveLexerStaticData *ltlleftrecursivelexerLexerStaticData = nullptr;

void ltlleftrecursivelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ltlleftrecursivelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(ltlleftrecursivelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LtlleftrecursiveLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "NOT", "AND", "OR", "ALWAYS", "NEXT", "SOMETIME", 
      "UNTIL", "WS", "DIGIT", "LETTER", "IDENTIFIER"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "", "", "", "", "'next'"
    },
    std::vector<std::string>{
      "", "", "", "NOT", "AND", "OR", "ALWAYS", "NEXT", "SOMETIME", "UNTIL", 
      "WS", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,11,99,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,1,0,1,1,1,
  	1,1,2,1,2,1,2,1,2,3,2,36,8,2,1,3,1,3,1,3,1,3,3,3,42,8,3,1,4,1,4,1,4,3,
  	4,47,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,57,8,5,1,6,1,6,1,6,1,6,1,
  	6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,74,8,7,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,3,8,83,8,8,1,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,
  	5,12,95,8,12,10,12,12,12,98,9,12,0,0,13,1,1,3,2,5,3,7,4,9,5,11,6,13,7,
  	15,8,17,9,19,10,21,0,23,0,25,11,1,0,6,2,0,45,45,126,126,3,0,9,10,13,13,
  	32,32,1,0,48,57,1,0,97,122,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,
  	95,97,122,103,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,
  	0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,
  	0,25,1,0,0,0,1,27,1,0,0,0,3,29,1,0,0,0,5,35,1,0,0,0,7,41,1,0,0,0,9,46,
  	1,0,0,0,11,56,1,0,0,0,13,58,1,0,0,0,15,73,1,0,0,0,17,82,1,0,0,0,19,84,
  	1,0,0,0,21,88,1,0,0,0,23,90,1,0,0,0,25,92,1,0,0,0,27,28,5,40,0,0,28,2,
  	1,0,0,0,29,30,5,41,0,0,30,4,1,0,0,0,31,32,5,110,0,0,32,33,5,111,0,0,33,
  	36,5,116,0,0,34,36,7,0,0,0,35,31,1,0,0,0,35,34,1,0,0,0,36,6,1,0,0,0,37,
  	38,5,97,0,0,38,39,5,110,0,0,39,42,5,100,0,0,40,42,5,38,0,0,41,37,1,0,
  	0,0,41,40,1,0,0,0,42,8,1,0,0,0,43,44,5,111,0,0,44,47,5,114,0,0,45,47,
  	5,124,0,0,46,43,1,0,0,0,46,45,1,0,0,0,47,10,1,0,0,0,48,49,5,97,0,0,49,
  	50,5,108,0,0,50,51,5,119,0,0,51,52,5,97,0,0,52,53,5,121,0,0,53,57,5,115,
  	0,0,54,55,5,91,0,0,55,57,5,93,0,0,56,48,1,0,0,0,56,54,1,0,0,0,57,12,1,
  	0,0,0,58,59,5,110,0,0,59,60,5,101,0,0,60,61,5,120,0,0,61,62,5,116,0,0,
  	62,14,1,0,0,0,63,64,5,115,0,0,64,65,5,111,0,0,65,66,5,109,0,0,66,67,5,
  	101,0,0,67,68,5,116,0,0,68,69,5,105,0,0,69,70,5,109,0,0,70,74,5,101,0,
  	0,71,72,5,60,0,0,72,74,5,62,0,0,73,63,1,0,0,0,73,71,1,0,0,0,74,16,1,0,
  	0,0,75,83,5,85,0,0,76,77,5,117,0,0,77,78,5,110,0,0,78,79,5,108,0,0,79,
  	80,5,101,0,0,80,81,5,115,0,0,81,83,5,115,0,0,82,75,1,0,0,0,82,76,1,0,
  	0,0,83,18,1,0,0,0,84,85,7,1,0,0,85,86,1,0,0,0,86,87,6,9,0,0,87,20,1,0,
  	0,0,88,89,7,2,0,0,89,22,1,0,0,0,90,91,7,3,0,0,91,24,1,0,0,0,92,96,7,4,
  	0,0,93,95,7,5,0,0,94,93,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,1,0,
  	0,0,97,26,1,0,0,0,98,96,1,0,0,0,8,0,35,41,46,56,73,82,96,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ltlleftrecursivelexerLexerStaticData = staticData.release();
}

}

ltlleftrecursiveLexer::ltlleftrecursiveLexer(CharStream *input) : Lexer(input) {
  ltlleftrecursiveLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ltlleftrecursivelexerLexerStaticData->atn, ltlleftrecursivelexerLexerStaticData->decisionToDFA, ltlleftrecursivelexerLexerStaticData->sharedContextCache);
}

ltlleftrecursiveLexer::~ltlleftrecursiveLexer() {
  delete _interpreter;
}

std::string ltlleftrecursiveLexer::getGrammarFileName() const {
  return "ltloriginal.g4";
}

const std::vector<std::string>& ltlleftrecursiveLexer::getRuleNames() const {
  return ltlleftrecursivelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ltlleftrecursiveLexer::getChannelNames() const {
  return ltlleftrecursivelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ltlleftrecursiveLexer::getModeNames() const {
  return ltlleftrecursivelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ltlleftrecursiveLexer::getVocabulary() const {
  return ltlleftrecursivelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ltlleftrecursiveLexer::getSerializedATN() const {
  return ltlleftrecursivelexerLexerStaticData->serializedATN;
}

const atn::ATN& ltlleftrecursiveLexer::getATN() const {
  return *ltlleftrecursivelexerLexerStaticData->atn;
}




void ltlleftrecursiveLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ltlleftrecursivelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(ltlleftrecursivelexerLexerOnceFlag, ltlleftrecursivelexerLexerInitialize);
#endif
}
