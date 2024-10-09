#include "Distributed.h"

Distributed::Distributed(vector<int> modality, int power, shared_ptr<Formula> subformula) {
  modalityList_ = modality;
  power_ = power;

  Distributed *distributedFormula = dynamic_cast<Distributed *>(subformula.get());
  if (distributedFormula) {
    if (distributedFormula->getModalityList() == modalityList_) {
      power_ += distributedFormula->getPower();
      subformula_ = distributedFormula->getSubformula();
    } else {
      subformula_ = subformula;
    }
  } else {
    subformula_ = subformula;
  }
  std::hash<FormulaType> ftype_hash;
  std::hash<int> int_hash;
  //std::hash<vector<int>> vector_hash;
  size_t totalHash = ftype_hash(getType());
  size_t vectorHash = 0;
  modalityListString_ = "";
  for(auto item: modalityList_){
    vectorHash += int_hash(item);
    modalityListString_ += to_string(item) + ",";
    cout << "Item: " << item<< '\n';
  }
  
  modalityListString_ = modalityListString_.substr(0, modalityListString_.length() - 1);
  cout << "MOdalityString: " << modalityListString_ << '\n';
  distributedHash_ = totalHash + int_hash(vectorHash) + int_hash(power_) + subformula_->hash();
}

Distributed::~Distributed() {
#if DEBUG_DESTRUCT
  cout << "DESTRUCTING DISTRIBUTED" << endl;
#endif
}

vector<int> Distributed::getModalityList() const { return modalityList_; }

string Distributed::getModalityListString() const { return modalityListString_; }

int Distributed::getPower() const { return power_; }

shared_ptr<Formula> Distributed::getSubformula() const { return subformula_; }

void Distributed::incrementPower() { power_++; }

string Distributed::toString() const {
    string ret = "";
    for (int i = 0; i < power_; ++i) ret += "D[" + modalityListString_ + "]";
    return ret + subformula_->toString();
         
}

FormulaType Distributed::getType() const { return FDistributed; }

shared_ptr<Formula> Distributed::negatedNormalForm() {
  subformula_ = subformula_->negatedNormalForm();
  return shared_from_this();
}


shared_ptr<Formula> Distributed::tailNormalForm() {
    assert (1 == 0);
}

// TODO : CREATE NOTDISTRIBUTED
shared_ptr<Formula> Distributed::negate() {
  return Distributed::create(modalityList_, power_, subformula_->negate());
}

shared_ptr<Formula> Distributed::simplify() {
  subformula_ = subformula_->simplify();

  switch (subformula_->getType()) {
  case FTrue:
    return True::create();
  case FDistributed: {
    Distributed *distributedFormula = dynamic_cast<Distributed *>(subformula_.get());
    if (distributedFormula->getModalityListString() == modalityListString_) {
      power_ += distributedFormula->getPower();
      subformula_ = distributedFormula->getSubformula();
    }
    return shared_from_this();
  }

  default:
    return shared_from_this();
  }
}

shared_ptr<Formula> Distributed::modalFlatten() {
  subformula_ = subformula_->modalFlatten();
  if (subformula_->getType() == FDistributed) {
    Distributed *k = dynamic_cast<Distributed *>(subformula_.get());
    if (k->getModalityListString() == modalityListString_) {
      power_ += k->getPower();
      subformula_ = k->getSubformula();
    }
  }
  return shared_from_this();
}

shared_ptr<Formula> Distributed::axiomSimplify(int axiom, int depth) { 
    subformula_ = subformula_->axiomSimplify(axiom, depth+power_);
    if (depth > 0)
        power_ = 1;
    else
        power_ = min(power_, 2);
    return shared_from_this(); 
}

shared_ptr<Formula> Distributed::create(vector<int> modality, int power,
                                const shared_ptr<Formula> &subformula) {
  if (power == 0) {
    return subformula;
  }
  return shared_ptr<Formula>(new Distributed(modality, power, subformula));
}

shared_ptr<Formula> Distributed::create(vector<vector<int>> modality,
                                const shared_ptr<Formula> &subformula) {
  if (modality.size() == 0) {
    return subformula;
  }
  shared_ptr<Formula> formula =
      Distributed::create(modality[modality.size() - 1], 1, subformula);
  for (size_t i = modality.size() - 1; i > 0; i--) {
    formula = Distributed::create(modality[i - 1], 1, formula);
  }
  return formula;
}

shared_ptr<Formula> Distributed::constructDistributedReduced() const {
  return Distributed::create(modalityList_, power_ - 1, subformula_);
}

shared_ptr<Formula> Distributed::clone() const {
  return create(modalityList_, power_, subformula_->clone());
}

bool Distributed::operator==(const Formula &other) const {
  if (other.getType() != getType()) {
    return false;
  }
  const Distributed *otherDistributed = dynamic_cast<const Distributed *>(&other);
  return modalityListString_ == otherDistributed->modalityListString_ && power_ == otherDistributed->power_ &&
         *subformula_ == *(otherDistributed->subformula_);
}

bool Distributed::operator!=(const Formula &other) const {
  return !(operator==(other));
}

size_t Distributed::hash() const {
  return distributedHash_;
}
