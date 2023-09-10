/*
    simpleLogger.cpp
    created on :28/8/2023
    author     :shrief mahmoud
*/
#include "simpleLogger.hpp"

// Initialize the logger
BOOST_LOG_GLOBAL_LOGGER_INIT(logger, src::severity_logger_mt)
{
    src::severity_logger_mt<boost::log::trivial::severity_level> logger;

    // Add attributes
    logger.add_attribute("LineID", attrs::counter<unsigned int>(1)); // Lines are sequentially numbered
    logger.add_attribute("TimeStamp", attrs::local_clock());         // Each log line gets a timestamp

    // Create a text sink for logging
    typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
    boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

    // Define the log line format
    logging::formatter formatter = expr::stream
                                   << std::setw(7) << std::setfill('0') << line_id << std::setfill(' ') << " | "
                                   << expr::format_date_time(timestamp, "%Y-%m-%d, %H:%M:%S.%f") << " "
                                   << "[" << logging::trivial::severity << "]"
                                   << " - " << expr::smessage;

    // Set the formatter for the sink
    sink->set_formatter(formatter);

    // Set the formatter for the sink
    sink->set_formatter(formatter);
    // Add a file log for storing log messages
    auto fileSink = logging::add_file_log(
        logkw::file_name = LOGFILE,
        logkw::rotation_size = 1024); // Rotate the file when it reaches 1024 bytes
    /*
     *  this part creates a logs directory in the build directory,
     *  the major file  named "run_logs.txt" has a maximum size 1024 byte
     *  after the logs exceeds the size it will create a new
     *  log file in the log directory and move the old logs to it    */
    fileSink->locked_backend()->set_file_collector(
        sinks::file::make_collector(
            logkw::target = "/home/shrief/Desktop/FINAL_project/build/logs"));

    fileSink->set_formatter(formatter);

    // Set the maximum number of log files to keep
    logging::core::get()->add_global_attribute("RotationCounter", attrs::counter<unsigned int>(0, 1)); // Start from 0 and increment by 1
    logging::core::get()->add_global_attribute("RotationSize", attrs::constant<unsigned int>(1024));   // Set the rotation size

    // Enable automatic file rotation
    logging::core::get()->add_global_attribute("FileRotation", attrs::constant<unsigned int>(1)); // Enable file rotation

    // Set the file name pattern for rotated files
    logging::core::get()->add_global_attribute("FileRotationPattern", attrs::constant<std::string>("%run%_%logs%.log")); // Set the file name pattern

    // Only messages with severity >= SEVERITY_THRESHOLD are written
    sink->set_filter(severity >= SEVERITY_THRESHOLD);

    // Register the sink with the logging core
    logging::core::get()->add_sink(sink);
    logging::keywords::auto_flush = true;

    return logger;
}

/*
 *arg: state of the message queque receiver
 *Function to log received messages based on the error status.
 */
void LogReceivedMessage(ErrorCode status)
{
    switch (status)
    {
    case ErrorCode::SUCCESS:
        LOG_DEBUG << "RECEIVING_SUCCESS"; // Log a success message.
        boost::log::core::get()->flush();
        break;

    case ErrorCode::QUEUE_CONNECTION_FAILED:
        LOG_ERROR << "QUEUE_CONNECTION_FAILED"; // Log an error message for queue connection failure.
        boost::log::core::get()->flush();
        break;

    case ErrorCode::QUEUE_RECEIVE_FAILED:
        LOG_ERROR << "QUEUE_RECEIVE_FAILED"; // Log an error message for queue receive failure.
        boost::log::core::get()->flush();
        break;

    default:
        LOG_TRACE << "WAITING"; // Log a trace message indicating waiting.
        boost::log::core::get()->flush();
        break;
    }
}

// Function to create a vector of Receiver objects based on a vector of object names.
vector<Receiver> CreateReceiverObjects(vector<string> objectNames)
{
    vector<Receiver> receiverObjects;

    for (string objectName : objectNames)
    {
        Receiver receiver(std::string("/" + objectName).c_str());
        receiverObjects.push_back(receiver);
    }

    return receiverObjects;
}

int main()
{
    LOG_TRACE << "ENTERED_LOGGER"; // Log that you entered the logger.
    boost::log::core::get()->flush();

    vector<string> objectNames = getStringsFromFile(CONFIGFILE); // Get strings from a configuration file.
    char buffer[1024] = {0}; // Create a buffer for receiving data.
    string receivedData = {0}; // Initialize a string for processing received data.
    ErrorCode receiveState; // Declare a variable to store error codes.
    MyRpiSocketClient rpi(MY_IP); // Create an instance of MyRpiSocketClient.

    vector<Receiver> receivers = CreateReceiverObjects(objectNames); // Create a vector of Receiver objects.

    while (true)
    {
        // Loop for receiving data from multiple queues.

        if (SYNC)
        {
            // Synchronous mode for receiving data.

            for (size_t i = 0; i < objectNames.size(); i++)
            {
                receiveState = receivers[i].MsgQueSyncReceive(buffer); // Receive data synchronously from a queue.
                LogReceivedMessage(receiveState); // Log the receive status.
                if (receiveState == ErrorCode::SUCCESS)
                {
                    receivedData = buffer; // Convert received data to a string.
                    LOG_TRACE << receivedData; // Log the received data.
                    boost::log::core::get()->flush(); // Flush the log.
                    rpi.sendDataToServer(buffer, sizeof(buffer)); // Send data to the server.
                }
                // Additional handling for other error states can be added here.
            }
        }
        else
        {
            // Asynchronous mode for receiving data.

            for (size_t i = 0; i < objectNames.size(); i++)
            {
                receiveState = receivers[i].MsgQueAsyncReceive(buffer); // Receive data asynchronously from a queue.
                LogReceivedMessage(receiveState); // Log the receive status.
                if (receiveState == ErrorCode::SUCCESS)
                {
                    receivedData = buffer; // Convert received data to a string.
                    LOG_TRACE << receivedData; // Log the received data.
                    boost::log::core::get()->flush(); // Flush the log.
                    rpi.sendDataToServer(buffer, sizeof(buffer)); // Send data to the server.
                }
                // Additional handling for other error states can be added here.
            }
        }
    }
    return 0;
}

