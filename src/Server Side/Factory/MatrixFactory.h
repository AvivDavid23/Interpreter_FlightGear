//
// Created by dvir on 1/13/19.
//

#ifndef SECONDYEARPROJECT_BIU_MATRIXFACTORY_H
#define SECONDYEARPROJECT_BIU_MATRIXFACTORY_H

#include "Factory.h"
#include "../Problems/MatrixMaze.h"
namespace factory {
class MatrixFactory : public factory::Factory<MatrixMaze,std::string>{
public:
    MatrixMaze CreateProblem(std::vector<std::string> lines) {
        MatrixMaze matrixMaze(lines);
        return matrixMaze;
    }
    std::string CreateSolution(std::string lines) {
        return lines;
    }
    };
}

#endif //SECONDYEARPROJECT_BIU_MATRIXFACTORY_H
