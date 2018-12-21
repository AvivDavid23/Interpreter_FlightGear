//
// Created by aviv on 12/16/18.
//

#ifndef SECONDYEARPROJECT_BIU_DATAWRITERCLIENT_H
#define SECONDYEARPROJECT_BIU_DATAWRITERCLIENT_H

#include "map"

/**
 * A client that connects to the server of the simulation
 */
class DataWriterClient {
    static std::string message;
public:

    static void setMessage(const std::string &message1);

    static void createClient(int port, std::string address);

};


#endif //SECONDYEARPROJECT_BIU_DATAWRITERCLIENT_H
