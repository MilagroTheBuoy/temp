#include "WeakNext.h"

WeakNext::WeakNext(shared_ptr<Formula> subformula) { subformula_ = subformula; }
WeakNext::~WeakNext() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING WEAKNEXT" << endl;
#endif
}

shared_ptr<Formula> WeakNext::getSubformula() const { return subformula_; }

string WeakNext::toString() const { return "(weaknext " + subformula_->toString() + ")"; }

FormulaType WeakNext::getType() const { return FWeakNext; }

shared_ptr<Formula> WeakNext::negatedNormalForm() {
    subformula_ = subformula_->negatedNormalForm(); 
    return shared_from_this();
}
shared_ptr<Formula> WeakNext::tailNormalForm() {
    auto tail = Atom::create("tail");
    return Or::create({tail, Next::create(subformula_->tailNormalForm())});
}

// Must return weak next in LTL-f mode
shared_ptr<Formula> WeakNext::negate() { return Next::create(subformula_->negate());}

shared_ptr<Formula> WeakNext::simplify() {
  subformula_ = subformula_->simplify();
  return shared_from_this();
}

shared_ptr<Formula> WeakNext::modalFlatten() {
    assert (1 == 0);
}


shared_ptr<Formula> WeakNext::axiomSimplify(int axiom, int depth) { 
    assert (1 == 0);
}


shared_ptr<Formula> WeakNext::create(shared_ptr<Formula> subformula) {
  return shared_ptr<Formula>(new WeakNext(subformula));
}

shared_ptr<Formula> WeakNext::clone() const { return create(subformula_->clone()); }

bool WeakNext::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const WeakNext *otherWeakNext = dynamic_cast<const WeakNext *>(&other);
  return *subformula_ == *(otherWeakNext->subformula_);
}

bool WeakNext::operator!=(const Formula &other) const { return !(operator==(other)); }

size_t WeakNext::hash() const {
  std::hash<FormulaType> ftype_hash;
  size_t totalHash = ftype_hash(getType());
  return totalHash + subformula_->hash();
}

bool WeakNext::isPrimitive() const { return subformula_->isPrimitive(); }
