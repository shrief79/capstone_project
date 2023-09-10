/*
    machine.cpp
    created on :30/8/2023
    author     :shrief mahmoud

*/
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>

using namespace std;

/******************** Configuration ********************/
#define SOCKET_TYPE SOCK_STREAM
#define SOCKET_DOMAIN AF_INET
#define SOCKET_PROTOCOL 0 // 0 = default protocol "IP" most probably
#define SERVER_PORT 6666 // Port number must be the same in the two connected devices to complete the connection

class SimpleSocketServer
{
public:
    // Constructor
    SimpleSocketServer()
    {
        // Create a server socket
        if ((serverSocket = socket(SOCKET_DOMAIN, SOCKET_TYPE, SOCKET_PROTOCOL)) < 0)
        {
            cerr << "Error: Could not create socket\n";
            exit(EXIT_FAILURE);
        }
        else
            cout << "Socket file descriptor: " << serverSocket << endl;

        // Initialize server configuration
        memset(&serverAddress, '0', sizeof(serverAddress)); // Clear the memory to avoid garbage values
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(SERVER_PORT);
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

        // Bind the server to the socket
        if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
        {
            cerr << "Error: Failed to bind socket\n";
            exit(EXIT_FAILURE);
        }
        else
            cout << "Server is bound to port number: " << SERVER_PORT << endl;

        // Set the server socket in listening mode for incoming connections
        if (listen(serverSocket, 10) < 0)
        {
            cerr << "Failed to listen on socket";
            exit(EXIT_FAILURE);
        }
        else
        {
            cout << "Listening..." << endl;
        }
    }

    // Start the server
    void Start()
    {
        while (true)
        {
            // Accept incoming client connections
            if ((clientSocket = accept(serverSocket, nullptr, nullptr)) < 0)
            {
                cerr << "Failed to accept connection\n";
                continue;
            }
            else
            {
                // Handle data communication with the connected client using a new thread
                thread clientThread(&SimpleSocketServer::HandleClient, this, clientSocket);
                clientThread.detach(); // Detach the thread to run independently
            }
        }
    }

    // Handle data communication with a connected client
    void HandleClient(int clientSocket)
    {
        char receiveBuffer[1025];
        static char isFirstTime = 0;
        memset(receiveBuffer, '0', sizeof(receiveBuffer));
        if (isFirstTime == 0)
        {
            isFirstTime = 1;
            cout << "Received:\n";
        }
        else
        {
            cout << "\n";
        }
        while (true)
        {
            if ((bytesReceived = read(clientSocket, receiveBuffer, sizeof(receiveBuffer) - 1)) > 0)
            {
                receiveBuffer[bytesReceived] = 0;
                if (fputs(receiveBuffer, stdout) == EOF)
                {
                    cerr << "Error: Fputs error\n";
                    exit(EXIT_FAILURE);
                }
                cout << endl;
                fflush(stdout); // Flush the output buffer
            }
        }
        close(clientSocket);
    }

    // Destructor
    ~SimpleSocketServer()
    {
        cout << "\nSocket is closed" << endl;
        close(serverSocket);
    }

private:
    // Private member variables
    int bytesReceived;
    int serverSocket;
    int clientSocket;
    struct sockaddr_in serverAddress
    {
    };
};

int main()
{
    SimpleSocketServer server;
    server.Start();
    return 0;
}

