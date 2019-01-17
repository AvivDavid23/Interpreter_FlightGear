//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_CACHEMANAGER_H
#define SECONDYEARPROJECT_BIU_CACHEMANAGER_H

/**
 * an Interface, which can save and load solutions to problems we already solved(on disk, database, etc...)
 */
#include <map>
#include "../Factory/Factory.h"
namespace server_side {
    namespace cache {
        template <class Problem,class Solution>
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
            virtual Solution getSolution(Problem problem1) = 0;

            /**
             * Save solution the problem
             * @param problem
             */
            virtual void saveSolution(Problem problem,Solution solution) = 0;
            /**
             * @param factory1 refresh our map from the files.
             */
            virtual void RefreshMap(factory::Factory<Problem,Solution> *factory1) = 0;
            /**
             * save the dada on the files.
             */
            virtual void saveData() = 0;
        };
    }
}
#endif //SECONDYEARPROJECT_BIU_CACHEMANAGER_H
