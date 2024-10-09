#ifndef ALWAYS_H
#define ALWAYS_H

#include "../../Defines/Defines.h"
#include "../FEnum/FEnum.h"
#include "../Formula/Formula.h"
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include "../Sometime/Sometime.h"

using namespace std;

class Always : public Formula, public enable_shared_from_this<Always> {
private:
  shared_ptr<Formula> subformula_;

public:
  Always(shared_ptr<Formula> subformula);
  ~Always();

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
