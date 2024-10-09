#include "NotKnow.h"

NotKnow::NotKnow(int modality, int power, shared_ptr<Formula> subformula) {
  modality_ = modality;
  power_ = power;

  NotKnow *notKnowFormula = dynamic_cast<NotKnow *>(subformula.get());
  if (notKnowFormula) {
    if (notKnowFormula->getModality() == modality_) {
      power_ += notKnowFormula->getPower();
      subformula_ = notKnowFormula->getSubformula();
    } else {
      subformula_ = subformula;
    }
  } else {
    subformula_ = subformula;
  }
  std::hash<FormulaType> ftype_hash;
  std::hash<int> int_hash;
  size_t totalHash = ftype_hash(getType());
  notKnowHash_ = totalHash + int_hash(modality_) + int_hash(power_) +
         subformula_->hash();
}

NotKnow::~NotKnow() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING NOTKNOW" << endl;
#endif
}

int NotKnow::getModality() const { return modality_; }

int NotKnow::getPower() const { return power_; }

shared_ptr<Formula> NotKnow::getSubformula() const { return subformula_; }

void NotKnow::incrementPower() { power_++; }

string NotKnow::toString() const {
    string ret = "";
    for (int i = 0; i < power_; ++i) ret += "?[" + to_string(modality_) + "]";
    return ret + subformula_->toString();
}

FormulaType NotKnow::getType() const { return FNotKnow; }

shared_ptr<Formula> NotKnow::negatedNormalForm() {
  subformula_ = subformula_->negatedNormalForm();
  return shared_from_this();
}

shared_ptr<Formula> NotKnow::tailNormalForm() {
    assert (1 == 0);
}
shared_ptr<Formula> NotKnow::negate() {
  return Know::create(modality_, power_, subformula_->negate());
}

shared_ptr<Formula> NotKnow::simplify() {
  subformula_ = subformula_->simplify();

  switch (subformula_->getType()) {
  case FFalse:
    return False::create();
  case FNotKnow: {
    NotKnow *notKnowFormula = dynamic_cast<NotKnow *>(subformula_.get());
    if (notKnowFormula->getModality() == modality_) {
      power_ += notKnowFormula->getPower();
      subformula_ = notKnowFormula->getSubformula();
    }
    return shared_from_this();
  }

  default:
    return shared_from_this();
  }
}

shared_ptr<Formula> NotKnow::modalFlatten() {
  subformula_ = subformula_->modalFlatten();
  if (subformula_->getType() == FNotKnow) {
    NotKnow *d = dynamic_cast<NotKnow *>(subformula_.get());
    if (d->getModality() == modality_) {
      power_ += d->getPower();
      subformula_ = d->getSubformula();
    }
  }
  return shared_from_this();
}


shared_ptr<Formula> NotKnow::axiomSimplify(int axiom, int depth) { 
    if (axiom == 2 && depth >= 1) {
        if (subformula_->getType() == FKnow) {
            Know *b = dynamic_cast<Know *>(subformula_.get());
            return b->getSubformula()->axiomSimplify(axiom, depth);
        }
        return shared_from_this();
    } else {
        subformula_ = subformula_->axiomSimplify(axiom, depth+power_);
        if (depth > 0)
            power_ = 1;
        else
            power_ = min(power_, 2);
        return shared_from_this(); 
    }
}

shared_ptr<Formula> NotKnow::create(int modality, int power,
                                    shared_ptr<Formula> subformula) {
  if (power == 0) {
    return subformula;
  }
  return shared_ptr<Formula>(new NotKnow(modality, power, subformula));
}

shared_ptr<Formula> NotKnow::create(vector<int> modality,
                                    const shared_ptr<Formula> &subformula) {
  if (modality.size() == 0) {
    return subformula;
  }
  shared_ptr<Formula> formula =
      NotKnow::create(modality[modality.size() - 1], 1, subformula);
  for (size_t i = modality.size() - 1; i > 0; i--) {
    formula = NotKnow::create(modality[i - 1], 1, formula);
  }
  return formula;
}

shared_ptr<Formula> NotKnow::constructNotKnowReduced() const {
  return NotKnow::create(modality_, power_ - 1, subformula_);
}

shared_ptr<Formula> NotKnow::clone() const {
  return create(modality_, power_, subformula_->clone());
}

bool NotKnow::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const NotKnow *otherNotKnow = dynamic_cast<const NotKnow *>(&other);
  return modality_ == otherNotKnow->modality_ &&
         power_ == otherNotKnow->power_ &&
         *subformula_ == *(otherNotKnow->subformula_);
}

bool NotKnow::operator!=(const Formula &other) const {
  return !(operator==(other));
}

size_t NotKnow::hash() const {
  return notKnowHash_;
}
