#ifndef SOMETIME_H
#define SOMETIME_H

#include "../../Defines/Defines.h"
#include "../FEnum/FEnum.h"
#include "../Formula/Formula.h"
#include "../Until/Until.h"
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include "../Always/Always.h"

using namespace std;

class Sometime : public Formula, public enable_shared_from_this<Sometime> {
private:
  shared_ptr<Formula> subformula_;

public:
  Sometime(shared_ptr<Formula> subformula);
  ~Sometime();

  shared_ptr<Formula> getSubformula() const;

  string toString() const;
  FormulaType getType() const;

  shared_ptr<Formula> negatedNormalForm();
  shared_ptr<Formula> tailNormalForm();
  shared_ptr<Formula> negate();
  shared_ptr<Formula> simplify();
  shared_ptr<Formula> modalFlatten();
  shared_ptr<Formula> axiomSimplify(int axiom, int depth);

  shared_ptr<Formula> clone() const;

  bool isPrimitive() const;

  static shared_ptr<Formula> create(shared_ptr<Formula> subformula);

  bool operator==(const Formula &other) const;
  bool operator!=(const Formula &other) const;

  size_t hash() const;
};

#endif
