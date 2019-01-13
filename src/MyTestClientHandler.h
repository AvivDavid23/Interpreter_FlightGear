//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
#define SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H

#include <iostream>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "genClient.h"
#include "StringReverseFactory.h"
#include "algorithmSolver.h"
#include "MatrixMaze.h"

/**
 * A type of Client Handler
 */
class MyTestClientHandler : public genClient<MatrixMaze, std::string> {
public:
    void handleClient(int newsockfd) {
        this->cachemanager->RefreshMap(this->createObjects);
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
                solver = new algorithmSolver<MatrixMaze<5,3>,string>();
                solution = solver->solve(matrix);
                this->cachemanager->saveData();
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
            else
                matrix.push_back(problem);
        }
    }

    MyTestClientHandler() {
//        this->solver = new algorithmSolver <MatrixMaze,string()>;
        this->cachemanager = new server_side::cache::FileCacheManager<MatrixMaze, std::string>();
        this->createObjects = new factory::StringReverseFactory();
    }
};

#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
