//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
#define SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <fstream>
#define FILE "saveSolution.txt"

/**
 * A cache manager that save solutions in a file
 */
namespace server_side {
    namespace cache {
        template <class Problem,class Solution>
        class FileCacheManager : public CacheManager<Problem,Solution> {
            std::fstream *file;
        public:
            FileCacheManager() {
            };
            bool containsSolution(Problem *problem){
                return (this->works.find(*problem) != this->works());
            }

            Solution getSolution(Problem *problem){
                return this->works[*problem];
            }

            void saveSolution(Problem *problem,Solution *solution){
                if(!file->is_open()) file->open(FILE);
                file << problem.tostring() << "" << solution.tostring();
            }
        };
    }
}

#endif //SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
