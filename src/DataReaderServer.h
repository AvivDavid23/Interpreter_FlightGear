#ifndef SECONDYEARPROJECT_BIU_DATAREADERSERVER_H
#define SECONDYEARPROJECT_BIU_DATAREADERSERVER_H

#include "thread"
#include "map"
#include "vector"
#include "PathsTable.h"
#include "SymbolTable.h"
#include "BindingTable.h"

#define PARAMETERS_SIZE 23
#define BUFFER_SIZE 1024
static std::vector<std::string> pathsVec{"/instrumentation/airspeed-indicator/indicated-speed-kt",
                                         "/instrumentation/altimeter/indicated-altitude-ft",
                                         "/instrumentation/altimeter/pressure-alt-ft",
                                         "/instrumentation/attitude-indicator/indicated-pitch-deg",
                                         "/instrumentation/attitude-indicator/indicated-roll-deg",
                                         "/instrumentation/attitude-indicator/internal-pitch-deg",
                                         "/instrumentation/attitude-indicator/internal-roll-deg",
                                         "/instrumentation/encoder/indicated-altitude-ft",
                                         "/instrumentation/encoder/pressure-alt-ft",
                                         "/instrumentation/gps/indicated-altitude-ft",
                                         "/instrumentation/gps/indicated-ground-speed-kt",
                                         "/instrumentation/gps/indicated-vertical-speed",
                                         "/instrumentation/heading-indicator/indicated-heading-deg",
                                         "/instrumentation/magnetic-compass/indicated-heading-deg",
                                         "/instrumentation/slip-skid-ball/indicated-slip-skid",
                                         "/instrumentation/turn-indicator/indicated-turn-rate",
                                         "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                         "/controls/flight/aileron",
                                         "/controls/flight/elevator",
                                         "/controls/flight/rudder",
                                         "/controls/flight/flaps",
                                         "/controls/engines/current-engine/throttle",
                                         "/engines/engine/rpm"};
class DataReaderServer {

    static bool open;

    static int sockFd;

    /**
     * Updates the Paths table
     * @param vector vector
     */
    static void updatePathsTable(std::vector<std::string> vec);

    /**
     * Updates symbol table
     */
    static void updateSymbolTable();

    /**
     * split by ,
     * @param buffer buffer
     * @return vector of values
     */
    static std::vector<std::string> splitByComma(const char *buffer);


public:
    /**
     * Opens the server
     * @param port port
     * @param hz hz
     */
    static void openServer(int port, int hz);

    /**
         * @return true if server is open, else false
     */
    inline static bool isOpen(){ return open;}

    inline static int getSocketFD(){ return sockFd;}
};


#endif //SECONDYEARPROJECT_BIU_DATAREADERSERVER_H