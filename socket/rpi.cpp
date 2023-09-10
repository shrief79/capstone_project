/*
    rpi.cpp
    created on :30/8/2023
    author     :shrief mahmoud

*/
#include "rpi.hpp"

MyRpiSocketClient::MyRpiSocketClient(const char *serverIpAddress)
{
    // Constructor for the MyRpiSocketClient class.
    
    // Create a socket
    if ((socketFileDescriptor = socket(SOCKET_DOMAIN, SOCKET_TYPE, SOCKET_PROTOCOL)) < 0)
    {
        cerr << "Error: Could not create socket\n";  // Print an error message if socket creation fails.
        exit(EXIT_FAILURE);  // Exit the program with a failure status code.
    }
    else
    {
        cout << "Socket is open" << endl;  // Print a success message for socket creation.
        cout << "Socket file descriptor: " << socketFileDescriptor << endl;  // Print the socket file descriptor.
    }

    // Initialize server configuration
    serverAddress.sin_family = AF_INET;  // Set the address family to IPv4.
    serverAddress.sin_port = htons(SERVER_PORT);  // Set the port number in network byte order.
    if (inet_pton(AF_INET, serverIpAddress, &serverAddress.sin_addr) <= 0)
    {
        cerr << "Invalid address or address not supported" << endl;  // Print an error message for invalid server address.
        exit(EXIT_FAILURE);  // Exit the program with a failure status code.
    }

    // Create a connection to the server
    if (connect(socketFileDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        cerr << "Failed to connect to the RPI" << endl;  // Print an error message for connection failure.
        exit(EXIT_FAILURE);  // Exit the program with a failure status code.
    }
    else
    {
        cout << "RPI CONNECTED" << endl;  // Print a success message for successful connection.
        cout << "IP address: " << serverIpAddress << endl;  // Print the server IP address.
        cout << "PORT: " << SERVER_PORT << endl;  // Print the server port number.
    }
}

MyRpiSocketClient::~MyRpiSocketClient()
{
    // Destructor for the MyRpiSocketClient class.
    
    cout << "Socket is closed" << endl;  // Print a message indicating that the socket is closed.
    close(socketFileDescriptor);  // Close the socket.
}

void MyRpiSocketClient::sendDataToServer(char *dataArray, int dataSize)
{
    // Function to send data to the server.
    
    if (send(socketFileDescriptor, dataArray, dataSize, 0) < 0)
    {
        cerr << "Error: Failed to send data" << endl;  // Print an error message for data sending failure.
    }
    else
    {
        cout << "Data sent successfully!" << endl;  // Print a success message for successful data sending.
    }
}

