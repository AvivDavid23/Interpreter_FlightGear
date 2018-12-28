//
// Created by aviv on 12/22/18.
//

#ifndef SECONDYEARPROJECT_BIU_DATAWRITERCLIENT_H
#define SECONDYEARPROJECT_BIU_DATAWRITERCLIENT_H


#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include "../Tables/SymbolTable.h"

using namespace std;

/**
 * A client that connects to the server of the simulation
 */


class DataWriterClient {
    static int sockFd;
public:

    static void writeMessage(const string &message1);

    static void createClient(int port, string address);

    inline static int getSocketFD() { return sockFd; }

};

#endif //SECONDYEARPROJECT_BIU_DATAWRITERCLIENT_H
