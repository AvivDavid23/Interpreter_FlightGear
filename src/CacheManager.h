//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_CACHEMANAGER_H
#define SECONDYEARPROJECT_BIU_CACHEMANAGER_H

#include "Problem.h"
#include "Solution.h"

/**
 * an Interface, which can save and load solutions to problems we already solved(on disk, database, etc...)
 */
namespace server_side {
    namespace cache {
        class CacheManager {
        public:
            /**
             * @param problem
             * @return true if the cache manager has a solution to the problem, else false
             */
            virtual bool containsSolution(Problem problem) = 0;

            /**
             * @param problem
             * @return solution the the problem
             */
            virtual Solution getSolution(Problem problem) = 0;

            /**
             * Save solution the problem
             * @param problem
             */
            virtual void saveSolution(Problem problem) = 0;
        };
    }
}
#endif //SECONDYEARPROJECT_BIU_CACHEMANAGER_H
