//
// Created by aviv on 12/31/18.
//


#include "MySerialServer.h"

using namespace std;
void server_side::MySerialServer::open(int port, ClientHandler* clientHandler) {
    int sockfd, newsockfd, clilen;
    char buffer[BUFFER_SIZE];
    std::string values;
    std::string leftovers;
    bzero(buffer, BUFFER_SIZE);
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    while (sockfd < 0) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        //try...
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */
    /* Now start listening for the clients, here process will
     * go in sleep mode and will wait for the incoming connection
  */

    // only one can conncet.
    listen(sockfd, 1);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    // the massage.
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    openCustumer = true;
    string output,input;
    int start = leftovers.length() ? leftovers.length() - 1 : 0;
    // set input
     read(newsockfd, buffer + start, BUFFER_SIZE - start);
     input = string(buffer);
     // set output
     output = write(this->portID,"1",1);
     istringstream realInput(input);
     stringstream output1(output);
//     clientHandler->handleClient(realInput,output1);

}

void server_side::MySerialServer::stopPro(){
    this->openCustumer = false;
    close(this->portID);
}

void server_side::MySerialServer::start(int port, ClientHandler* clientHandler) {
    portID = port;
//    thread t(&MySerialServer::open, port,this);
//    t.detach();
}
