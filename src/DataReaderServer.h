#ifndef SECONDYEARPROJECT_BIU_DATAREADERSERVER_H
#define SECONDYEARPROJECT_BIU_DATAREADERSERVER_H

#include "thread"
#include "map"


class DataReaderServer {

public:
    static void openServer(int port, int hz, std::map<std::string, double> &symbolTable);
};


#endif //SECONDYEARPROJECT_BIU_DATAREADERSERVER_H