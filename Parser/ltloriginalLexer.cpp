
// Generated from ltloriginal.g4 by ANTLR 4.13.0


#include "ltloriginalLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LtloriginalLexerStaticData final {
  LtloriginalLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LtloriginalLexerStaticData(const LtloriginalLexerStaticData&) = delete;
  LtloriginalLexerStaticData(LtloriginalLexerStaticData&&) = delete;
  LtloriginalLexerStaticData& operator=(const LtloriginalLexerStaticData&) = delete;
  LtloriginalLexerStaticData& operator=(LtloriginalLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag ltloriginallexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LtloriginalLexerStaticData *ltloriginallexerLexerStaticData = nullptr;

void ltloriginallexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ltloriginallexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(ltloriginallexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LtloriginalLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "NOT", "AND", "OR", "ALWAYS", "NEXT", "SOMETIME", 
      "UNTIL", "IMPLIES", "IFF", "WS", "DIGIT", "LETTER", "IDENTIFIER"
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
      "IMPLIES", "IFF", "WS", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,13,116,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,3,2,40,8,2,1,3,1,3,1,3,1,3,3,3,46,
  	8,3,1,4,1,4,1,4,3,4,51,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,61,8,5,
  	1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,78,8,
  	7,1,8,1,8,1,8,1,8,1,8,1,8,3,8,86,8,8,1,9,1,9,1,9,1,9,3,9,92,8,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,3,10,100,8,10,1,11,1,11,1,11,1,11,1,12,1,12,
  	1,13,1,13,1,14,1,14,5,14,112,8,14,10,14,12,14,115,9,14,0,0,15,1,1,3,2,
  	5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,0,27,0,29,13,1,0,
  	6,2,0,45,45,126,126,3,0,9,10,13,13,32,32,1,0,48,57,1,0,97,122,3,0,65,
  	90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,122,0,1,1,0,0,0,0,3,1,0,
  	0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,29,1,0,
  	0,0,1,31,1,0,0,0,3,33,1,0,0,0,5,39,1,0,0,0,7,45,1,0,0,0,9,50,1,0,0,0,
  	11,60,1,0,0,0,13,62,1,0,0,0,15,77,1,0,0,0,17,85,1,0,0,0,19,91,1,0,0,0,
  	21,99,1,0,0,0,23,101,1,0,0,0,25,105,1,0,0,0,27,107,1,0,0,0,29,109,1,0,
  	0,0,31,32,5,40,0,0,32,2,1,0,0,0,33,34,5,41,0,0,34,4,1,0,0,0,35,36,5,110,
  	0,0,36,37,5,111,0,0,37,40,5,116,0,0,38,40,7,0,0,0,39,35,1,0,0,0,39,38,
  	1,0,0,0,40,6,1,0,0,0,41,42,5,97,0,0,42,43,5,110,0,0,43,46,5,100,0,0,44,
  	46,5,38,0,0,45,41,1,0,0,0,45,44,1,0,0,0,46,8,1,0,0,0,47,48,5,111,0,0,
  	48,51,5,114,0,0,49,51,5,124,0,0,50,47,1,0,0,0,50,49,1,0,0,0,51,10,1,0,
  	0,0,52,53,5,97,0,0,53,54,5,108,0,0,54,55,5,119,0,0,55,56,5,97,0,0,56,
  	57,5,121,0,0,57,61,5,115,0,0,58,59,5,91,0,0,59,61,5,93,0,0,60,52,1,0,
  	0,0,60,58,1,0,0,0,61,12,1,0,0,0,62,63,5,110,0,0,63,64,5,101,0,0,64,65,
  	5,120,0,0,65,66,5,116,0,0,66,14,1,0,0,0,67,68,5,115,0,0,68,69,5,111,0,
  	0,69,70,5,109,0,0,70,71,5,101,0,0,71,72,5,116,0,0,72,73,5,105,0,0,73,
  	74,5,109,0,0,74,78,5,101,0,0,75,76,5,60,0,0,76,78,5,62,0,0,77,67,1,0,
  	0,0,77,75,1,0,0,0,78,16,1,0,0,0,79,86,5,85,0,0,80,81,5,117,0,0,81,82,
  	5,110,0,0,82,83,5,116,0,0,83,84,5,105,0,0,84,86,5,108,0,0,85,79,1,0,0,
  	0,85,80,1,0,0,0,86,18,1,0,0,0,87,88,5,61,0,0,88,92,5,62,0,0,89,90,5,45,
  	0,0,90,92,5,62,0,0,91,87,1,0,0,0,91,89,1,0,0,0,92,20,1,0,0,0,93,94,5,
  	60,0,0,94,95,5,61,0,0,95,100,5,62,0,0,96,97,5,60,0,0,97,98,5,45,0,0,98,
  	100,5,62,0,0,99,93,1,0,0,0,99,96,1,0,0,0,100,22,1,0,0,0,101,102,7,1,0,
  	0,102,103,1,0,0,0,103,104,6,11,0,0,104,24,1,0,0,0,105,106,7,2,0,0,106,
  	26,1,0,0,0,107,108,7,3,0,0,108,28,1,0,0,0,109,113,7,4,0,0,110,112,7,5,
  	0,0,111,110,1,0,0,0,112,115,1,0,0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,
  	30,1,0,0,0,115,113,1,0,0,0,10,0,39,45,50,60,77,85,91,99,113,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ltloriginallexerLexerStaticData = staticData.release();
}

}

ltloriginalLexer::ltloriginalLexer(CharStream *input) : Lexer(input) {
  ltloriginalLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ltloriginallexerLexerStaticData->atn, ltloriginallexerLexerStaticData->decisionToDFA, ltloriginallexerLexerStaticData->sharedContextCache);
}

ltloriginalLexer::~ltloriginalLexer() {
  delete _interpreter;
}

std::string ltloriginalLexer::getGrammarFileName() const {
  return "ltloriginal.g4";
}

const std::vector<std::string>& ltloriginalLexer::getRuleNames() const {
  return ltloriginallexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ltloriginalLexer::getChannelNames() const {
  return ltloriginallexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ltloriginalLexer::getModeNames() const {
  return ltloriginallexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ltloriginalLexer::getVocabulary() const {
  return ltloriginallexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ltloriginalLexer::getSerializedATN() const {
  return ltloriginallexerLexerStaticData->serializedATN;
}

const atn::ATN& ltloriginalLexer::getATN() const {
  return *ltloriginallexerLexerStaticData->atn;
}




void ltloriginalLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ltloriginallexerLexerInitialize();
#else
  ::antlr4::internal::call_once(ltloriginallexerLexerOnceFlag, ltloriginallexerLexerInitialize);
#endif
}
