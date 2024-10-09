#include "Until.h"

Until::Until(shared_ptr<Formula> left, shared_ptr<Formula> right) { left_ = left; right_ = right;}
Until::~Until() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING NOT" << endl;
#endif
}

shared_ptr<Formula> Until::getLeftSubformula() const { return left_; }
shared_ptr<Formula> Until::getRightSubformula() const { return right_; }

string Until::toString() const { return "(" + left_->toString() + " U " + right_->toString() + ")";}

FormulaType Until::getType() const { return FUntil; }

shared_ptr<Formula> Until::negatedNormalForm() { 
    left_ = left_->negatedNormalForm();
    right_ = right_->negatedNormalForm();
    return shared_from_this(); 
}


shared_ptr<Formula> Until::tailNormalForm() { 
    auto tail = Atom::create("tail");
    left_ = And::create({Not::create(tail), left_->tailNormalForm()});
    //left_ = And::create({Atom::create("true"), left_->tailNormalForm()});
    right_ = right_->tailNormalForm();
    return shared_from_this(); 
}

shared_ptr<Formula> Until::negate() { return Release::create(left_->negate(), right_->negate()); }

shared_ptr<Formula> Until::simplify() {
  left_ = left_->simplify();
  right_ = right_->simplify();
  return shared_from_this();
}

shared_ptr<Formula> Until::modalFlatten() {
    assert(1 == 0);
}


shared_ptr<Formula> Until::axiomSimplify(int axiom, int depth) { 
    assert(1 == 0);
}


shared_ptr<Formula> Until::create(shared_ptr<Formula> left, shared_ptr<Formula> right) {
  return shared_ptr<Formula>(new Until(left, right));
}

shared_ptr<Formula> Until::clone() const { return create(left_->clone(), right_->clone()); }

bool Until::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const Until *otherUntil = dynamic_cast<const Until *>(&other);
  return (*left_ == *(otherUntil->left_)) &&  (*right_ == *(otherUntil->right_));
}

bool Until::operator!=(const Formula &other) const { return !(operator==(other)); }

size_t Until::hash() const {
  std::hash<FormulaType> ftype_hash;
  size_t totalHash = ftype_hash(getType());
  return totalHash + left_->hash() + right_->hash();
}

bool Until::isPrimitive() const { return false; }
