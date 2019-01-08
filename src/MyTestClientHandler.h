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
#define   LINES 256
/**
 * A type of Client Handler
 */
 template <class Problem,class Solution>
class MyTestClientHandler : public genClient<std::string ,std::string> {
public:
        void handleClient(std::istream inputStream, std::ostream outputStream) {
            char sent[LINES];
            inputStream.getline(sent, LINES);
            while (sent != "end") {
                if (this->cacheManager->containsSolution(inputStream))
                    this->cacheManager->getSolution(inputStream);
                else
                    outputStream = this->solver->solve(inputStream);
                this->cacheManager->saveSolution(sent, outputStream);
                inputStream.getline(sent, LINES);
            }
        }

    MyTestClientHandler() {
        this->solver = new StringReverser();
        this->cacheManager = server_side::cache::FileCacheManager<std::string,std::string>();
    }
};

#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
