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
public:
    static void createClient(int port, std::string address, std::map<std::string, double> &symbolTable);
};


#endif //SECONDYEARPROJECT_BIU_DATAWRITERCLIENT_H
