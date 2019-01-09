//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
#define SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <fstream>
#include "algorithm"
#include <unordered_map>
#define FILE "saveSolution.txt"

/**
 * A cache manager that save solutions in a file
 */
namespace server_side {
    namespace cache {
        template <class Problem,class Solution>
        class FileCacheManager : public CacheManager<Problem,Solution> {
            std::fstream file;
            unordered_map<Problem*,Solution*> problems;
        public:
            FileCacheManager() {};
            bool containsSolution(Problem *problem){
                auto got = problems.find (problem);
                return !(got ==problems.end());


            }

            Solution* getSolution(Problem* problem){
               return this->problems[problem];
            }

            void saveSolution(Problem* problem,Solution* solution){
                    file.open(FILE,std::fstream::in | std::fstream::out | std::fstream::app);
//                file <<solution.tostring();
                this->problems[problem] = solution;
            }
        };
    }
}

#endif //SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
