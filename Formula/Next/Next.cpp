#include "Next.h"

Next::Next(shared_ptr<Formula> subformula) { subformula_ = subformula; }
Next::~Next() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING NEXT" << endl;
#endif
}

shared_ptr<Formula> Next::getSubformula() const { return subformula_; }

string Next::toString() const { return "(next " + subformula_->toString() + ")"; }

FormulaType Next::getType() const { return FNext; }

shared_ptr<Formula> Next::negatedNormalForm() {
    subformula_ = subformula_->negatedNormalForm(); 
    return shared_from_this();
}
shared_ptr<Formula> Next::tailNormalForm() {
    auto tail = Atom::create("tail");
    return And::create({Not::create(tail), Next::create(subformula_->tailNormalForm())});
}

// Must return weak next in LTL-f mode
shared_ptr<Formula> Next::negate() { 
    return WeakNext::create(subformula_->negate());
}

shared_ptr<Formula> Next::simplify() {
  subformula_ = subformula_->simplify();
  return shared_from_this();
}

shared_ptr<Formula> Next::modalFlatten() {
    assert (1 == 0);
}


shared_ptr<Formula> Next::axiomSimplify(int axiom, int depth) { 
    assert (1 == 0);
}


shared_ptr<Formula> Next::create(shared_ptr<Formula> subformula) {
  return shared_ptr<Formula>(new Next(subformula));
}

shared_ptr<Formula> Next::clone() const { return create(subformula_->clone()); }

bool Next::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const Next *otherNext = dynamic_cast<const Next *>(&other);
  return *subformula_ == *(otherNext->subformula_);
}

bool Next::operator!=(const Formula &other) const { return !(operator==(other)); }

size_t Next::hash() const {
  std::hash<FormulaType> ftype_hash;
  size_t totalHash = ftype_hash(getType());
  return totalHash + subformula_->hash();
}

bool Next::isPrimitive() const { return subformula_->isPrimitive(); }
