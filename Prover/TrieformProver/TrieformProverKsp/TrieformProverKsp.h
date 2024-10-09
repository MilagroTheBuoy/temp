#ifndef TRIEFORM_PROVER_KSP
#define TRIEFORM_PROVER_KSP

#include <memory>
#include <string>
#include <unordered_map>

#include "../../../Bitset/Bitset.h"
#include "../../../Clausifier/Trieform/Trieform.h"
#include "../../../Clausifier/TrieformFactory/TrieformFactory.h"
#include "../../LocalSolutionMemo/LocalSolutionMemo.h"
#include "../../ExactSolutionMemo/ExactSolutionMemo.h"
#include "../TrieformProverK/TrieformProverK.h"

using namespace std;

class TrieformProverKsp : public TrieformProverK {
    public:

    TrieformProverKsp();
    ~TrieformProverKsp();

    virtual shared_ptr<Trieform> create(const shared_ptr<Formula> &formula) override;
    virtual shared_ptr<Trieform> create(const shared_ptr<Formula> &formula,
                                        const vector<int> &newModality) override;
    virtual shared_ptr<Trieform> create(const vector<int> &newModality) override;

    Solution prove(literal_set assumptions = literal_set()) override;
    Solution prove(int depth, literal_set assumptions = literal_set());
};

#endif
