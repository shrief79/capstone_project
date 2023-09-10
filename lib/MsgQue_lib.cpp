/*
 MsgQue_lib.cpp
 created on :27/8/2023
 author:shrief mahmoud
*/
#include "MsgQue_lib.hpp"

// Receiver class
Receiver ::Receiver(const char *mq_host)
{ 
    // Set message queue attributes
    struct mq_attr attr;
    attr.mq_maxmsg = MAX_MSG_COUNT;
    attr.mq_msgsize = MAX_MSG_SIZE;
    // Create a message queue with read-write permissions
    mq = mq_open(mq_host, O_CREAT | O_RDWR, 0666, &attr);
}

// Create a message queue
ErrorCode Receiver::MsgQueCreate(const char *mq_host)
{
    // Set message queue attributes
    struct mq_attr attr;
    attr.mq_maxmsg = MAX_MSG_COUNT;
    attr.mq_msgsize = MAX_MSG_SIZE;
    // Create a message queue with read-write permissions
    mq = mq_open(mq_host, O_CREAT | O_RDWR, 0666, &attr);

    if (mq == -1)
    {
        return ErrorCode::QUEUE_CREATION_FAILED;
    }
    // creation ended
    return ErrorCode::SUCCESS;
}

// Receive values from the message queue (asynchronous)
ErrorCode Receiver::MsgQueAsyncReceive(char *str)
{
    // create a buffer with maximum size of message to receive in
    unsigned int priority;
    struct timespec timeout;

    // setting time out
    timeout.tv_sec = time(NULL) + 10;
    timeout.tv_nsec = 0;

    // Check if the queue is empty
    ssize_t last_byte = mq_timedreceive(mq, str, MAX_MSG_SIZE, &priority, &timeout);
    if (last_byte == -1)
    {
        return ErrorCode::QUEUE_RECEIVE_FAILED;
    }

    // Null-terminate the received message
    str[last_byte] = '\0';
    cout << str << endl;
    return ErrorCode::SUCCESS;
}

// Receive values from the message queue (synchronous)
ErrorCode Receiver::MsgQueSyncReceive(char *str)
{

    // char buffer[MAX_MSG_SIZE];
    unsigned int priority;

    // Receive a message from the queue (blocking)
    ssize_t bytesRead = mq_receive(mq, str, MAX_MSG_SIZE, &priority);

    if (bytesRead == -1)
    {
        return ErrorCode::QUEUE_RECEIVE_FAILED;
    }

    // Null-terminate the received message
    str[bytesRead] = '\0';
    return ErrorCode::SUCCESS;
}

// Sender class
Sender ::Sender() {}

// Connect to an existing message queue
ErrorCode Sender::MsgQueConnect(const char *mq_host)
{
    // Open the existing message queue with read-write permissions
    mq = mq_open(mq_host, O_RDWR);
    if (mq == -1)
    {
        return ErrorCode::QUEUE_CONNECTION_FAILED;
    }

    return ErrorCode::SUCCESS;
}

// Send a message to the connected message queue
ErrorCode Sender::MsgQueSend(const std::string &message)
{
    // Check if the receiver exists
    if (mq == -1)
    {
        return ErrorCode::RECEIVER_NOT_FOUND;
    }

    // Send the message to the queue
    int res = mq_send(mq, message.c_str(), message.size(), 0);
    if (res == -1)
    {
        return ErrorCode::QUEUE_SEND_FAILED;
    }
    return ErrorCode::SUCCESS;
}
