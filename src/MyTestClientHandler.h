//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
#define SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H

#include <zconf.h>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
//#include "StringReverser.h"
#include "FileCacheManager.h"
#include "genClient.h"
#include "StringReverseFactory.h"
#include "algorithmSolver.h"
#include "MatrixMaze.h"
#include "MatrixFactory.h"
#include <algorithm>
#include <sys/socket.h>

/**
 * A type of Client Handler
 */
class MyTestClientHandler : public genClient<MatrixMaze, std::string> {
public:
    void handleClient(int newsockfd) {
        this->cachemanager->RefreshMap(createObjects);
        /*
        std::string solution, answer;
        getline(inputStream, solution);
        std::string sent(solution);
        while (sent != "end" && !sent.empty()) {
            if (this->cachemanager->containsSolution(sent))
                this->cachemanager->getSolution(sent);
            else
                answer = this->solver->solve(sent);
            outputStream << answer << endl;
            this->cachemanager->saveSolution(sent, answer);
            std::getline(std::cin, sent);
            */
        std::string solution,problem;
        std:: vector<string> matrix;
        unsigned int getRow ,getCow ;
        char buf[1024];
        int n = 0;
        while ((n = read(newsockfd, buf, 1024) > 0)) {
            solution = buf;
            problem = buf;
            if(solution.substr(0,3) == "end" || solution.empty()) {
                getRow = (unsigned int )matrix.size() - 2 ;
                getCow = (unsigned int )std::count(matrix[0].begin(),matrix[0].end(), ',');
                MatrixMaze matrixMaze(getRow,getCow);
                // if there is a solution.
                if(this->cachemanager->containsSolution(matrixMaze))
                    solution = this->cachemanager->getSolution(matrixMaze);
                else {
                    // solve and save
                    solution = solver->solve(matrixMaze);
                    this->cachemanager->saveSolution(matrixMaze, solution);
                    this->cachemanager->saveData();
                }
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

    MyTestClientHandler() {
        solver = new algorithmSolver<MatrixMaze,string>();
        this->cachemanager = new server_side::cache::FileCacheManager<MatrixMaze, std::string>();
        this->createObjects = new factory::MatrixFactory();
    }

     ~MyTestClientHandler(){
         delete solver;
         delete cachemanager;
         delete createObjects;
    }
};


#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
