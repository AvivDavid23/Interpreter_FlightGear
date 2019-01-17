//
// Created by dvir on 1/8/19.
//

#ifndef SECONDYEARPROJECT_BIU_GENCLIENT_H
#define SECONDYEARPROJECT_BIU_GENCLIENT_H

#include "ClientHandler.h"
#include "../Solvers/Solver.h"
#include "../Cache/CacheManager.h"
#include "../Factory/Factory.h"

template <class Problem,class Solution>
class genClient :  public ClientHandler {
protected:
    // members
    server_side::Solver<Problem, Solution> *solver;
    server_side::cache::CacheManager<Problem, Solution> *cachemanager;
    factory::Factory<Problem,Solution> * createObjects;
};


#endif //SECONDYEARPROJECT_BIU_GENCLIENT_H