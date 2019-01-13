//
// Created by dvir on 1/13/19.
//

#ifndef SECONDYEARPROJECT_BIU_MATRIXFACTORY_H
#define SECONDYEARPROJECT_BIU_MATRIXFACTORY_H

#include "Factory.h"
#include "MatrixMaze.h"
namespace factory {
class MatrixFactory : public factory::Factory<MatrixMaze,std::string>{
public:
    MatrixMaze CreateProblem(std::vector<std::string> lines) {
        MatrixMaze matrixMaze(lines);
        return matrixMaze;
    }
    std::string CreateSolution(std::vector<std::string> lines) {
        return lines[0];
    }
    };
}

#endif //SECONDYEARPROJECT_BIU_MATRIXFACTORY_H
