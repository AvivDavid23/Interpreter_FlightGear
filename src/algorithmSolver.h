//
// Created by dvir on 1/12/19.
//

#ifndef SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H
#define SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "ISearcher.h"
template <class Problem,class Solution>
class algorithmSolver: public server_side::Solver<Problem,Solution>{
    ISearcher <Problem,Solution> * searchable;
    ISearchable<Problem,Solution> * iSearchable;
public:
    Solution solve(Problem & problem) {
        searchable->search(iSearchable);
    }
};


#endif //SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H
