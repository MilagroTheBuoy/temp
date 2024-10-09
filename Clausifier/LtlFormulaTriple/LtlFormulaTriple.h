#ifndef LTL_FORMULA_TRIPLE_H
#define LTL_FORMULA_TRIPLE_H

#include "../../Formula/Atom/Atom.h"
#include "../../Formula/Formula/Formula.h"
#include "../../Formula/Not/Not.h"
#include "../FormulaTriple/FormulaTriple.h"
#include "../../Prover/Literal/Literal.h"
#include <memory>
#include <string>
#include <vector>

struct LtlClause {
    literal_set left;
    Literal right;
    LtlClause(const literal_set& l, const Literal& r) : left(l), right(r) {}
};



typedef std::vector<LtlClause> ltl_clause_list;
typedef std::vector<literal_set> clause_list;
class LtlFormulaTriple {
private:
  clause_list clauses;
  ltl_clause_list stepClauses;
  ltl_clause_list eventualityClauses;
  literal_set unconditionalEventualities;

public:
  LtlFormulaTriple();
  ~LtlFormulaTriple();

  const clause_list &getClauses() const;
  const ltl_clause_list &getStepClauses() const;
  const ltl_clause_list &getEventualityClauses() const;
  const literal_set&getUnconditionalEventualities() const;

  void setClauses(clause_list newClauses);
  void setStepClauses(ltl_clause_list newStepClauses);
  void setEventualityClauses(ltl_clause_list newEventualityClauses);
  void setUnconditionalEventualities(literal_set newEventualities);

  void eraseClauses();
  void eraseStepClauses();
  void eraseEventualityClauses();

  void addStepClause(literal_set left, Literal right);
  void addEventualityClause(literal_set left, Literal right);
  void addClause(literal_set clause);
  void addStepClause(LtlClause stepClause);
  void addEventualityClause(LtlClause eventualityClause);
  void addUnconditionalEventuality(Literal eventuality);

  vector<string> toStringComponents() const;
  string toString() const;

  void simplify();

    void simplifyEventuality();
    void simplifyNext();
    void simplifyNextOrs();
    literal_set getUniverse();
};

#endif
