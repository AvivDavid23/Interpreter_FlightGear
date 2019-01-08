//
// Created by dvir on 1/8/19.
//

#ifndef SECONDYEARPROJECT_BIU_STRINGREVERSER_H
#define SECONDYEARPROJECT_BIU_STRINGREVERSER_H

#include <string>
#include "Solver.h"
#include "algorithm"

class StringReverser: public server_side::Solver<std::string,std::string>{
public:
    virtual std::string solve(std:: string problem) {
         std::reverse(problem.begin(),problem.end());
        return problem;
    }
};


#endif //SECONDYEARPROJECT_BIU_STRINGREVERSER_H
