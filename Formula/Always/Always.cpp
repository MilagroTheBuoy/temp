#include "Always.h"

Always::Always(shared_ptr<Formula> subformula) { subformula_ = subformula; }
Always::~Always() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING ALWAYS" << endl;
#endif
}

shared_ptr<Formula> Always::getSubformula() const { return subformula_; }

string Always::toString() const { return "(always " + subformula_->toString() + " )"; }

FormulaType Always::getType() const { return FAlways; }

shared_ptr<Formula> Always::negatedNormalForm() { 
    subformula_ = subformula_->negatedNormalForm(); 
    return shared_from_this();
}


shared_ptr<Formula> Always::tailNormalForm() { 
    //auto tail = Atom::create("tail");
    return Release::create(Atom::create("tail"), subformula_->tailNormalForm()); 
}
shared_ptr<Formula> Always::negate() { 
  return Sometime::create(subformula_->negate());
 }

shared_ptr<Formula> Always::simplify() {
  subformula_ = subformula_->simplify();
  return shared_from_this();
}

shared_ptr<Formula> Always::modalFlatten() {
    assert (1 == 0);
}


shared_ptr<Formula> Always::axiomSimplify(int axiom, int depth) { 
    assert (1 == 0);
}


shared_ptr<Formula> Always::create(shared_ptr<Formula> subformula) {
  return shared_ptr<Formula>(new Always(subformula));
}

shared_ptr<Formula> Always::clone() const { return create(subformula_->clone()); }

bool Always::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const Always *otherAlways = dynamic_cast<const Always *>(&other);
  return *subformula_ == *(otherAlways->subformula_);
}

bool Always::operator!=(const Formula &other) const { return !(operator==(other)); }

size_t Always::hash() const {
  std::hash<FormulaType> ftype_hash;
  size_t totalHash = ftype_hash(getType());
  return totalHash + subformula_->hash();
}

bool Always::isPrimitive() const { return false; }
