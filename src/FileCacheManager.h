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
using namespace std;
/**
 * A cache manager that save solutions in a file
 */
namespace server_side {
    namespace cache {
        template <class Problem,class Solution>
                /**
                 * @tparam Problem the problem we solve.
                 * @tparam Solution the solution.
                 */
        class FileCacheManager : public CacheManager<Problem,Solution> {
            std::ofstream file1;
            std::ifstream read;
            std::unordered_map<string,string> probAndSol;
        public:
            FileCacheManager() {};

            bool containsSolution(Problem problem){
                auto got = probAndSol.find (problem.to_string());
                return !(got ==probAndSol.end());
            }

            Solution getSolution(Problem problem){
                    return this->probAndSol[problem.to_string()];
            }

            void saveData() {
                if(!file1.is_open()) file1.open(FILEQ);
                for ( auto it = probAndSol.begin(); it != probAndSol.end(); ++it ) {
                    file1 << it->first;
                    file1 << "\n";
                }
                file1.close();
                file1.open(FILEAS);
                for ( auto it = probAndSol.begin(); it != probAndSol.end(); ++it ) {
                    file1 << it ->second;
                    file1 << "\n";
                }
                file1.close();
            }
            void saveSolution(Problem problem,Solution solution){
                    this->probAndSol[problem.to_string()] = solution;
            }

            void RefreshMap(factory::Factory<Problem,Solution> *factory1) {
                // open the file of the Answers
                if(!read.is_open()) read.open(FILEAS);
                std::vector<string> solutions;
                std::vector <string>problems;
                std::string line;
                while(getline(read ,line)) {
                    if(line!= "")
                    solutions.push_back(line);
                }

                int i =0;
                read.close();
                read.open(FILEQ);
                while(getline(read ,line)) {
                    if(line!= "")
                    problems.push_back(line);
                    else {
                        if(! problems.empty()) {
                            Problem problem = factory1->CreateProblem(problems);
                            Solution solution = factory1->CreateSolution(solutions[i]);
                            this->probAndSol[problem.to_string()] = solution;
                            ++i;
                            problems.clear();
                        }
                    }
                }
                read.close();
            }
        };
    }
}

#endif //SECONDYEARPROJECT_BIU_FILECACHEMANAGER_H
