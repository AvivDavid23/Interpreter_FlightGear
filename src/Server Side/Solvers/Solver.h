//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_SOLVER_H
#define SECONDYEARPROJECT_BIU_SOLVER_H



/**
 * Solver Interface
 */
namespace server_side {
    template <class Problem, class Solution>
    class Solver {
    public:
        /**
         * @param problem
         * @return solution the the problem
         */
        virtual Solution solve(Problem *problem) = 0;

    };

}
#endif //SECONDYEARPROJECT_BIU_SOLVER_H
