#ifndef SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H
#define SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "ISearcher.h"
#include "../Problems/ISearchable.h"

template<class T, class Problem,class Solution>
class algorithmSolver : public server_side::Solver<Problem, Solution> {
public:
    ISearcher<T, Solution> *searcher;
    algorithmSolver(ISearcher<T, Solution> *searcher) : searcher(searcher) {}
    /**
     * @param problem
     * @return
     */
    Solution solve(Problem *problem) {
        return searcher->search(problem);

    }
};


#endif //SECONDYEARPROJECT_BIU_ALGORITHMSOLVER_H