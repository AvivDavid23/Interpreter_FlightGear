//
// Created by dvir on 1/8/19.
//

#ifndef SECONDYEARPROJECT_BIU_GENCLIENT_H
#define SECONDYEARPROJECT_BIU_GENCLIENT_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template <class Problem,class Solution>
class genClient : ClientHandler {
protected:
    server_side::Solver<Problem, Solution> *solver;
    server_side::cache::CacheManager <Problem,Solution> *cacheManager;
};


#endif //SECONDYEARPROJECT_BIU_GENCLIENT_H
