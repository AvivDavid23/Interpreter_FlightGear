//
// Created by dvir on 1/11/19.
//

#ifndef SECONDYEARPROJECT_BIU_STRINGREVERSEFACTORY_H
#define SECONDYEARPROJECT_BIU_STRINGREVERSEFACTORY_H


#include "Factory.h"
#include "string"
namespace factory {
    class StringReverseFactory : public factory::Factory<std::string, std::string> {

        virtual std::string CreateProblem(std::string &line) { return line; }

        virtual std::string CreateSolution(std::string &line) { return line;};
    };
}

#endif //SECONDYEARPROJECT_BIU_STRINGREVERSEFACTORY_H
