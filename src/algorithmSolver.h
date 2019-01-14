//
// Created by dvir on 1/12/19.
//

#ifndef SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H
#define SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "ISearcher.h"
#include "ISearchable.h"

template<class T, class Solution,class Problem>
class algorithmSolver : public server_side::Solver<Problem, Solution> {
    ISearcher<T, Solution> *searcher;
public:
    algorithmSolver(ISearcher<T, Solution> *searcher) : searcher(searcher) {}

    Solution solve(Problem &problem) {
        searcher->search(&problem);
    }
};


#endif //SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H
