//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
#define SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <fstream>
#include "vector"
#include <unordered_map>
#define FILEAS "saveSolution.txt"
#define FILEQ "saveQuestion.txt"
/**
 * A cache manager that save solutions in a file
 */
namespace server_side {
    namespace cache {
        template <class Problem,class Solution>
        class FileCacheManager : public CacheManager<Problem,Solution> {
            std::ofstream file1;
            std::ifstream read;
            std::unordered_map<Problem,Solution> probAndSol;
        public:
            FileCacheManager() {};
            bool containsSolution(Problem problem){
                auto got = probAndSol.find (problem);
                return !(got ==probAndSol.end());


            }

            Solution getSolution(Problem problem){
                return this->probAndSol[problem];
            }

            void saveData() {
                if(!file1.is_open()) file1.open(FILEQ);
                for ( auto it = probAndSol.begin(); it != probAndSol.end(); ++it ) {
                    Problem problem = it-> first;
                    file1 << problem;
                }
                file1.close();
                file1.open(FILEAS);
                for ( auto it = probAndSol.begin(); it != probAndSol.end(); ++it ) {
                    Solution solution = it ->second;
                    file1 << solution;
                }
                file1.close();
            }
            void saveSolution(Problem problem,Solution solution){
                this->probAndSol[problem] = solution;
            }

            void RefreshMap(factory::Factory<Problem,Solution> *factory1) {
                if(!read.is_open()) read.open(FILEAS);
                std::vector<Solution> solutions;
                std::vector <Problem>problems;
                std::string line;
                while(read >> line) {
                    solutions.push_back(factory1->CreateSolution(line));
                }
                read.close();
                read.open(FILEQ);
                while(read >> line) {
                    problems.push_back(factory1->CreateProblem(line));
                }
                read.close();
                auto it2 = solutions.begin();
                for (auto const &problem:problems) {
                    this->probAndSol[problem] = *it2;
                    it2++;
                }
            }

        };
    }
}

#endif //SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
