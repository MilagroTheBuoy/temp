#include "Release.h"

Release::Release(shared_ptr<Formula> left, shared_ptr<Formula> right) { left_ = left; right_ = right;}
Release::~Release() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING NOT" << endl;
#endif
}

shared_ptr<Formula> Release::getLeftSubformula() const { return left_; }
shared_ptr<Formula> Release::getRightSubformula() const { return right_; }

string Release::toString() const { return "(~(~" + left_->toString() + " U ~" + right_->toString() + "))";}

FormulaType Release::getType() const { return FRelease; }

shared_ptr<Formula> Release::negatedNormalForm() { 
    left_ = left_->negatedNormalForm();
    right_ = right_->negatedNormalForm();
    return shared_from_this(); }
shared_ptr<Formula> Release::negate() { return Until::create(left_->negate(), right_->negate()); }


shared_ptr<Formula> Release::tailNormalForm() { 
    auto tail = Atom::create("tail");
    left_ = Or::create({tail, left_->tailNormalForm()});
    right_ = right_->tailNormalForm();
    return shared_from_this(); 
}

shared_ptr<Formula> Release::simplify() {
  left_ = left_->simplify();
  right_ = right_->simplify();
  return shared_from_this();
}

shared_ptr<Formula> Release::modalFlatten() {
    assert(1 == 0);
}


shared_ptr<Formula> Release::axiomSimplify(int axiom, int depth) { 
    assert(1 == 0);
}


shared_ptr<Formula> Release::create(shared_ptr<Formula> left, shared_ptr<Formula> right) {
  return shared_ptr<Formula>(new Release(left, right));
}

shared_ptr<Formula> Release::clone() const { return create(left_->clone(), right_->clone()); }

bool Release::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const Release *otherRelease = dynamic_cast<const Release *>(&other);
  return (*left_ == *(otherRelease->left_)) &&  (*right_ == *(otherRelease->right_));
}

bool Release::operator!=(const Formula &other) const { return !(operator==(other)); }

size_t Release::hash() const {
  std::hash<FormulaType> ftype_hash;
  size_t totalHash = ftype_hash(getType());
  return totalHash + left_->hash() + right_->hash();
}

bool Release::isPrimitive() const { return false; }
