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
/**
 * A type of Client Handler
 */
class MyTestClientHandler : public genClient<std::string ,std::string> {
public:
        void handleClient(std::istream &inputStream, std::ostream &outputStream) {
            string line,answer;
            getline(inputStream,line);
            string sent(line);
            while (sent != "end" ||!sent.empty()) {
                if (this->cachemanager->containsSolution(&sent))
                    this->cachemanager->getSolution(&sent);
                else
                    answer= this->solver->solve(sent);
                this->cachemanager->saveSolution(&sent, &answer);
                std::getline(std::cin,sent);
            }
        }

    MyTestClientHandler() {
        this->solver = new StringReverser();
        this->cachemanager = new server_side::cache::FileCacheManager<string,string>();
    }
};

#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
