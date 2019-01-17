//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
#define SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H

#include <zconf.h>
#include "ClientHandler.h"
//#include "Solver.h"
#include "../Cache/CacheManager.h"
//#include "Position.h"
//#include "StringReverser.h"
#include "../Cache/FileCacheManager.h"
#include "genClient.h"
//#include "StringReverseFactory.h"
#include "../Solvers/algorithmSolver.h"
#include "../Problems/MatrixMaze.h"
#include "../Factory/MatrixFactory.h"
//#include <algorithm>
#include "../Solvers/Astar.h"
#include <sys/socket.h>

/**
 * A type of Client Handler
 */
class MyClientHandler : public genClient<MatrixMaze, std::string> {
    ISearcher<Position, string>* iSearcher;
public:
    void handleClient(int newsockfd) {
        this->cachemanager->RefreshMap(createObjects);
        std::string solution,problem;
        std:: vector<string> matrix;
        char buf[1024];
        // read from user
            while ((read(newsockfd, buf, 1024) > 0)) {
            solution = buf;
            problem = buf;
            // if it's end
            if(solution.substr(0,3) == "end" || solution.empty()) {
                MatrixMaze matrixMaze(matrix);
                // if there is a solution.
                if(this->cachemanager->containsSolution(matrixMaze))
                    solution = this->cachemanager->getSolution(matrixMaze);
                else {
                    // solve and save
                    solution =this->solver->solve(&matrixMaze) + "\n";
                    this->cachemanager->saveSolution(matrixMaze, solution);
                    this->cachemanager->saveData();
                }
                // send answer to the user.
                send(newsockfd,solution.c_str(), solution.length(),0);
                break;
            }
             // for part 2
            /* if(this->cachemanager->containsSolution(solution))
                solution = this->cachemanager->getSolution(solution);
            else
            solution  = solver->solve(solution);
            this->cachemanager->saveSolution(problem,solution);
             send(newsockfd,solution.c_str(), solution.length(),0);
             */
            else {
                matrix.push_back(problem);
            }
        }
    }

    MyClientHandler() {
        iSearcher = new Astar<Position>();
        solver = new algorithmSolver<Position,MatrixMaze,string>(iSearcher);
        this->cachemanager = new server_side::cache::FileCacheManager<MatrixMaze, std::string>();
        this->createObjects = new factory::MatrixFactory();
    }

     ~MyClientHandler(){
         delete solver;
         delete cachemanager;
         delete createObjects;
         delete iSearcher;
    }
};


#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
