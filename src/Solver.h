//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_SOLVER_H
#define SECONDYEARPROJECT_BIU_SOLVER_H

#include "Problem.h"
#include "Solution.h"

/**
 * Solver Interface
 */
namespace server_side {
    namespace algorithm {
        class Solver {
        public:
            /**
             * @param problem
             * @return solution the the problem
             */
            virtual problem::Solution solve(problem::Problem problem) = 0;

        };

    }
}
#endif //SECONDYEARPROJECT_BIU_SOLVER_H
