//
// Created by dvir on 1/11/19.
//

#ifndef SECONDYEARPROJECT_BIU_STRINGREVERSEFACTORY_H
#define SECONDYEARPROJECT_BIU_STRINGREVERSEFACTORY_H


#include "Factory.h"
#include "string"
namespace factory {
    class StringReverseFactory : public factory::Factory<std::string, std::string> {

        virtual std::string CreateProblem(std::vector<std::string> lines) { return lines[0]; }

        virtual std::string CreateSolution(std::vector<std::string> lines) { return lines[0];};
    };
}

#endif //SECONDYEARPROJECT_BIU_STRINGREVERSEFACTORY_H
