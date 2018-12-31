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
class Solver {
public:
    /**
     * @param problem
     * @return solution the the problem
     */
    virtual Solution solve(Problem problem) = 0;

};

#endif //SECONDYEARPROJECT_BIU_SOLVER_H
