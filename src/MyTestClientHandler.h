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

/**
 * A type of Client Handler
 */
class MyTestClientHandler : public genClient<std::string, std::string> {
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
        char buf[1024];
        int n = 0;
        while ((n = read(newsockfd, buf, 1024) > 0)) {
            solution = buf;
            problem = buf;
            if(solution.substr(0,3) == "end" || solution.empty()) {
                this->cachemanager->writeToFiles();
                break;
            }
            if(this->cachemanager->containsSolution(solution))
                solution = this->cachemanager->getSolution(solution);
            else
            solution  = solver->solve(solution);
            this->cachemanager->saveSolution(problem,solution);
             send(newsockfd,solution.c_str(), solution.length(),0);
        }
    }

    MyTestClientHandler() {
        this->solver = new StringReverser();
        this->cachemanager = new server_side::cache::FileCacheManager<std::string, std::string>();
        this->createObjects = new factory::StringReverseFactory();
    }
};

#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
