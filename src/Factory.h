//
// Created by dvir on 1/11/19.
//

#ifndef SECONDYEARPROJECT_BIU_FACTORY_H
#define SECONDYEARPROJECT_BIU_FACTORY_H

#include <string>
namespace factory {
    template<class Problem, class Solution>

    class Factory {
    public:
        virtual Problem CreateProblem(std::string &line) = 0;

        virtual Solution CreateSolution(std::string &line) = 0;
    };
}
#endif //SECONDYEARPROJECT_BIU_FACTORY_H
