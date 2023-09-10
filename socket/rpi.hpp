/*
    rpi.hpp
    created on :30/8/2023
    author     :shrief mahmoud

*/
#ifndef RPI_h_
#define RPI_h_



#include <iostream>
#include <cstring>
#include <thread>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

/********************Configuration*****************/
#define SOCKET_TYPE SOCK_STREAM
#define SOCKET_DOMAIN AF_INET
#define SOCKET_PROTOCOL 0 // default protocol "IP" most probably
#define SOCKET_PORT 6666//port number must be the same in the two connected devices to complete the connection

using namespace std;

class MyRpiSocketClient {
public:
    MyRpiSocketClient(const char *serverIpAddress);
    ~MyRpiSocketClient();
    void sendDataToServer(char *dataArray, int dataSize);

private:
    int socketFileDescriptor;
    struct sockaddr_in serverAddress;
    static const int SERVER_PORT = 6666;
};



#endif
