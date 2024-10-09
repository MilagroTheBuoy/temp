#ifndef NOTKNOW_H
#define NOTKNOW_H

#include "../../Defines/Defines.h"
#include "../Know/Know.h"
#include "../FEnum/FEnum.h"
#include "../False/False.h"
#include "../Formula/Formula.h"
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <cassert>

using namespace std;

class NotKnow : public Formula, public enable_shared_from_this<NotKnow> {
private:
  int modality_, power_;
  int notKnowHash_ = -1;
  shared_ptr<Formula> subformula_;

public:
  NotKnow(int modality, int power, shared_ptr<Formula> subformula);
  ~NotKnow();

  int getModality() const;
  int getPower() const;
  shared_ptr<Formula> getSubformula() const;

  void incrementPower();

  string toString() const;
  FormulaType getType() const;

  shared_ptr<Formula> negatedNormalForm();
  shared_ptr<Formula> tailNormalForm();
  shared_ptr<Formula> negate();
  shared_ptr<Formula> simplify();
  shared_ptr<Formula> modalFlatten();
  shared_ptr<Formula> axiomSimplify(int axiom, int depth);

  shared_ptr<Formula> clone() const;

  shared_ptr<Formula> constructNotKnowReduced() const;

  static shared_ptr<Formula> create(int modality, int power,
                                    shared_ptr<Formula> subformula);
  static shared_ptr<Formula> create(vector<int> modality,
                                    const shared_ptr<Formula> &subformula);

  bool operator==(const Formula &other) const;
  bool operator!=(const Formula &other) const;

  size_t hash() const;
};

#endif
