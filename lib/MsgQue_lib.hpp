/*
 MsgQue_lib.hpp
 created on :27/8/2023
 author:shrief mahmoud
*/

#ifndef MSGQUE_LIB_HPP_
#define MSGQUE_LIB_HPP_

#include <iostream>
#include <mqueue.h>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <boost/log/core/core.hpp>
#include <boost/log/expressions/formatters/date_time.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <fstream>
#include <ostream>

// name space for std
using namespace std;

// Define message queue attributes
const int MAX_MSG_SIZE = 1024;
const int MAX_MSG_COUNT = 10;

// Custom error codes
enum class ErrorCode
{
    SUCCESS,
    QUEUE_CREATION_FAILED,
    QUEUE_CONNECTION_FAILED,
    QUEUE_SEND_FAILED,
    QUEUE_RECEIVE_FAILED,
    RECEIVER_NOT_FOUND
};

class Receiver
{
private:
    mqd_t mq; // Message queue descriptor

public:
    Receiver(const char *mq_host);
    // Create a message queue
    ErrorCode MsgQueCreate(const char *mq_name);
    // Receive values from the message queue (asynchronous)
    ErrorCode MsgQueAsyncReceive(char *str);
    // Receive values from the message queue (synchronous)
    ErrorCode MsgQueSyncReceive(char *str);
};

// Sender class
class Sender
{
private:
    mqd_t mq; // Message queue descriptor

public:
    Sender();

    // Connect to an existing message queue
    ErrorCode MsgQueConnect(const char *mq_name);

    // Send a message to the connected message queue
    ErrorCode MsgQueSend(const std::string &message);
};

#endif
