//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
#define SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "Problem.h"
#include "Solution.h"

/**
 * A cache manager that save solutions in a file
 */
namespace server_side {
    namespace cache {
        class FileCacheManager : public CacheManager {
        public:
            bool containsSolution(problem::Problem problem);

            problem::Solution getSolution(problem::Problem problem);

            void saveSolution(problem::Problem problem);
        };
    }
}

#endif //SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H