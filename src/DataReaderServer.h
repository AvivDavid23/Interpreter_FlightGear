//
// Created by dvir on 12/13/18.
//

#ifndef SECONDYEARPROJECT_BIU_DATAREADERSERVER_H
#define SECONDYEARPROJECT_BIU_DATAREADERSERVER_H


class DataReaderServer {
    int port;
    int hz;
public:
    DataReaderServer(int port, int hz);

    void openServer();
};


#endif //SECONDYEARPROJECT_BIU_DATAREADERSERVER_H
