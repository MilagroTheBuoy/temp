#include "Sometime.h"

Sometime::Sometime(shared_ptr<Formula> subformula) { subformula_ = subformula; }
Sometime::~Sometime() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING SOMETIME" << endl;
#endif
}

shared_ptr<Formula> Sometime::getSubformula() const { return subformula_; }

string Sometime::toString() const { return "(sometime " + subformula_->toString() + " )"; }

FormulaType Sometime::getType() const { return FSometime; }

shared_ptr<Formula> Sometime::negatedNormalForm() { 
    subformula_ = subformula_->negatedNormalForm(); 
    return shared_from_this();
}

shared_ptr<Formula> Sometime::tailNormalForm() { 
    auto tail = Atom::create("tail");
    // T U p better than !tail U p
    return Until::create(Atom::create("true"), subformula_->tailNormalForm()); 
}


shared_ptr<Formula> Sometime::negate() { 
  return Always::create(subformula_->negate());
 }

shared_ptr<Formula> Sometime::simplify() {
  subformula_ = subformula_->simplify();
  return shared_from_this();
}

shared_ptr<Formula> Sometime::modalFlatten() {
    assert (1 == 0);
}


shared_ptr<Formula> Sometime::axiomSimplify(int axiom, int depth) { 
    assert (1 == 0);
}


shared_ptr<Formula> Sometime::create(shared_ptr<Formula> subformula) {
  return shared_ptr<Formula>(new Sometime(subformula));
}

shared_ptr<Formula> Sometime::clone() const { return create(subformula_->clone()); }

bool Sometime::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const Sometime *otherSometime = dynamic_cast<const Sometime *>(&other);
  return *subformula_ == *(otherSometime->subformula_);
}

bool Sometime::operator!=(const Formula &other) const { return !(operator==(other)); }

size_t Sometime::hash() const {
  std::hash<FormulaType> ftype_hash;
  size_t totalHash = ftype_hash(getType());
  return totalHash + subformula_->hash();
}

bool Sometime::isPrimitive() const { return false; }
