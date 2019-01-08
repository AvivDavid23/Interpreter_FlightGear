//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
#define SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "genClient.h"
/**
 * A type of Client Handler
 */
 template <class Problem,class Solution>
class MyTestClientHandler : public genClient<std::string ,std::string> {
public:
        void handleClient(std::istream inputStream, std::ostream outputStream){

        }

    MyTestClientHandler() {
        this->solver = new StringReverser();
        this->cacheManager = server_side::cache::FileCacheManager<std::string,std::string>();
    }
};

#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
