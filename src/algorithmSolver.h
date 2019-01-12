//
// Created by dvir on 1/12/19.
//

#ifndef SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H
#define SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H

#include "Solver.h"
#include "Searcher.h"
template <class Problem,class Solution>
class algorithmSolver: public server_side::Solver<Problem,Solution>{
Searcher < Problem,Solution> * searcher;
public:
    Solution solve(Problem & problem) {
        searcher
    }
};


#endif //SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H
