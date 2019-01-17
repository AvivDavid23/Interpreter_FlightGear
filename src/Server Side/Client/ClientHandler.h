//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_CLIENTHANDLER_H
#define SECONDYEARPROJECT_BIU_CLIENTHANDLER_H

#include "istream"
#include "ostream"
#include "../Solvers/Solver.h"
#include "../Cache/CacheManager.h"
// Client Handler Interface
class ClientHandler {
public:
    /**
     * Handles the client
     * @param inputStream input stream which contains the clients's message
     * @param outputStream output stream which we will write our answer in
     */
    virtual void handleClient(int newsockfd) = 0;
};
#endif //SECONDYEARPROJECT_BIU_CLIENTHANDLER_H
