#ifndef UNTIL_H
#define UNTIL_H

#include "../../Defines/Defines.h"
#include "../FEnum/FEnum.h"
#include "../Formula/Formula.h"
#include "../Atom/Atom.h"
#include "../Not/Not.h"
#include "../And/And.h"
#include "../Release/Release.h"
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <cassert>

using namespace std;

class Until : public Formula, public enable_shared_from_this<Until> {
private:
  shared_ptr<Formula> left_;
  shared_ptr<Formula> right_;

public:
  Until(shared_ptr<Formula> _left, shared_ptr<Formula> _right);
  ~Until();

  shared_ptr<Formula> getLeftSubformula() const;
  shared_ptr<Formula> getRightSubformula() const;

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

  static shared_ptr<Formula> create(shared_ptr<Formula> left, shared_ptr<Formula> right);

  bool operator==(const Formula &other) const;
  bool operator!=(const Formula &other) const;

  size_t hash() const;
};

#endif
