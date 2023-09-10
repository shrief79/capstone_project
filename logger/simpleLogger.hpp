/*
    simpleLogger.hpp
    created on :28/8/2023
    author     :shrief mahmoud
*/
#ifndef simpleLogger_h__
#define simpleLogger_h__
/*
 *  choose the ip of your ubunto there
 */
/********************Configuration*****************/
//SELECT the IP
#define MY_IP "192.168.1.22"

/*select the receiving syncronization 
    0->ASYNC
    1->SYNC
             |
             V   */
#define SYNC 1

/* the path of the LOG file*/
#define LOGFILE "/home/shrief/Desktop/FINAL_project/build/run_logs.txt"
/* the path of the configuration file*/
#define CONFIGFILE "/home/shrief/Desktop/FINAL_project/logger/config/LoggerConfig.txt"

/*
 *include the libraries
 */
#include "../socket/rpi.hpp"
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
#include <boost/log/utility/setup/file.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup.hpp>
#include <random>
#include <fstream>
#include <ostream>
#include <iostream>
#include "../lib/MsgQue_lib.hpp"
#include <unistd.h>
#include <signal.h>
#include "config_lib.hpp"
#include <boost/log/trivial.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#define BOOST_LOG_USE_GLOBAL_LOGGER

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace logkw = logging::keywords;
namespace fs = boost::filesystem;

/*
 * attributes of the log line
 */
BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", boost::posix_time::ptime)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", logging::trivial::severity_level)



/*just log messages with severity >= SEVERITY_THRESHOLD are written*/
#define SEVERITY_THRESHOLD logging::trivial::warning

/*register a global logger*/
BOOST_LOG_GLOBAL_LOGGER(logger, boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level>)

/*just a helper macro used by the macros below - don't use it in your code*/
#define LOG(severity) BOOST_LOG_SEV(logger::get(), boost::log::trivial::severity)

/*===== log macros ========================================================================================*/
#define LOG_TRACE LOG(trace)
#define LOG_DEBUG LOG(debug)
#define LOG_INFO LOG(info)
#define LOG_WARNING LOG(warning)
#define LOG_ERROR LOG(error)
#define LOG_FATAL LOG(fatal)

//...


#endif
