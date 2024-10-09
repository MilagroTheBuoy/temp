#include "Know.h"

Know::Know(int modality, int power, shared_ptr<Formula> subformula) {
  modality_ = modality;
  power_ = power;

  Know *knowFormula = dynamic_cast<Know *>(subformula.get());
  if (knowFormula) {
    if (knowFormula->getModality() == modality_) {
      power_ += knowFormula->getPower();
      subformula_ = knowFormula->getSubformula();
    } else {
      subformula_ = subformula;
    }
  } else {
    subformula_ = subformula;
  }
  std::hash<FormulaType> ftype_hash;
  std::hash<int> int_hash;
  size_t totalHash = ftype_hash(getType());
  knowHash_ = totalHash + int_hash(modality_) + int_hash(power_) + subformula_->hash();
}

Know::~Know() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING KNOW" << endl;
#endif
}

int Know::getModality() const { return modality_; }

int Know::getPower() const { return power_; }

shared_ptr<Formula> Know::getSubformula() const { return subformula_; }

void Know::incrementPower() { power_++; }

string Know::toString() const {
    string ret = "";
    for (int i = 0; i < power_; ++i) ret += "K[" + to_string(modality_) + "]";
    return ret + subformula_->toString();
         
}

FormulaType Know::getType() const { return FKnow; }

shared_ptr<Formula> Know::negatedNormalForm() {
  subformula_ = subformula_->negatedNormalForm();
  return shared_from_this();
}


shared_ptr<Formula> Know::tailNormalForm() {
    assert (1 == 0);
}

shared_ptr<Formula> Know::negate() {
  return NotKnow::create(modality_, power_, subformula_->negate());
}

shared_ptr<Formula> Know::simplify() {
  subformula_ = subformula_->simplify();

  switch (subformula_->getType()) {
  case FTrue:
    return True::create();
  case FKnow: {
    Know *knowFormula = dynamic_cast<Know *>(subformula_.get());
    if (knowFormula->getModality() == modality_) {
      power_ += knowFormula->getPower();
      subformula_ = knowFormula->getSubformula();
    }
    return shared_from_this();
  }

  default:
    return shared_from_this();
  }
}



shared_ptr<Formula> Know::modalFlatten() {
  subformula_ = subformula_->modalFlatten();
  if (subformula_->getType() == FKnow) {
    Know *k = dynamic_cast<Know *>(subformula_.get());
    if (k->getModality() == modality_) {
      power_ += k->getPower();
      subformula_ = k->getSubformula();
    }
  }
  return shared_from_this();
}

shared_ptr<Formula> Know::axiomSimplify(int axiom, int depth) { 
    subformula_ = subformula_->axiomSimplify(axiom, depth+power_);
    if (depth > 0)
        power_ = 1;
    else
        power_ = min(power_, 2);
    return shared_from_this(); 
}

shared_ptr<Formula> Know::create(int modality, int power,
                                const shared_ptr<Formula> &subformula) {
  if (power == 0) {
    return subformula;
  }
  return shared_ptr<Formula>(new Know(modality, power, subformula));
}

shared_ptr<Formula> Know::create(vector<int> modality,
                                const shared_ptr<Formula> &subformula) {
  if (modality.size() == 0) {
    return subformula;
  }
  shared_ptr<Formula> formula =
      Know::create(modality[modality.size() - 1], 1, subformula);
  for (size_t i = modality.size() - 1; i > 0; i--) {
    formula = Know::create(modality[i - 1], 1, formula);
  }
  return formula;
}

shared_ptr<Formula> Know::constructKnowReduced() const {
  return Know::create(modality_, power_ - 1, subformula_);
}

shared_ptr<Formula> Know::clone() const {
  return create(modality_, power_, subformula_->clone());
}

bool Know::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const Know *otherKnow = dynamic_cast<const Know *>(&other);
  return modality_ == otherKnow->modality_ && power_ == otherKnow->power_ &&
         *subformula_ == *(otherKnow->subformula_);
}

bool Know::operator!=(const Formula &other) const {
  return !(operator==(other));
}

size_t Know::hash() const {
  return knowHash_;
}
