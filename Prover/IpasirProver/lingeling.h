// TODO destructors
// A wrapper for Lingeling for convenient use
extern "C" {
#include "ipasir.h" // Needs to be included from solver directory
}
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
//#include <glog/logging.h>
#include <algorithm>

// From Dagster/Tinisat
//#include "utilities.h"
//#include "exceptions.h"
///#include "mpi_global.h"

using namespace std;

class Lingeling {
  public:
    Lingeling();
    ~Lingeling();
    Lingeling clone();
    void flush_cache();
    void add_clause(const vector<int>& inClause);
    int create_variable();
    void add_clauses(const vector<vector<int>>& inClauses);
    bool solve(const vector<int>& assumptions);
    bool solve_unmentioned_assumptions(const vector<int>& assumptions, const vector<int>& unmentioned_assumptions);
    vector<int> get_model(int lowest, int largest);
    vector<int> get_model();
    vector<int> used_assumptions();
    void set_important(const vector<int>& variables);

  private:
    char assigned_fname[10000];
    int max_var = 0;
    vector<int> last_assumptions;
    vector<int> last_unmentioned_assumptions;
    void * solver = NULL;

    // TODO refine these tinisat variables
    unsigned vc;	// var count
    unsigned cc;	// clause count
    int **clauses;	// 2-dim. array with entries same as in cnf file
    unsigned *cl;	// clause length
};
