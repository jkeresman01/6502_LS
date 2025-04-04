#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <chrono>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "TimeUtil.h"

#define MAX_BUFFER_SIZE 256

#define STR(format, ...) \
    [](const char *fmt, auto... args) { \
        char buffer[MAX_BUFFER_SIZE]; \
        snprintf(buffer, sizeof(buffer), fmt, args...); \
        return std::string(buffer); \
    }(format, __VA_ARGS__)

#define LOG(severity, message) ls6502::Logger::log(severity, message, __FILE__, __LINE__)

#define LS_6502_DEBUG(message) LOG("DEBUG", message)
#define LS_6502_INFO(message)  LOG("INFO", message)
#define LS_6502_WARN(message)  LOG("WARN", message)
#define LS_6502_ERROR(message) LOG("ERROR", message)

namespace ls6502
{

class Logger
{
  public:
    ////////////////////////////////////////////////////////////
    Logger() = delete;

    ////////////////////////////////////////////////////////////
    static void log(const std::string &severity, const std::string &message, const char *file,
                    uint32_t lineNumber)
    {
        std::ofstream logfile("/tmp/log.txt", std::ios::app);

        if (!logfile.is_open())
        {
            std::cerr << "No can do for opening log file!" << std::endl;
            return;
        }

        putLogMessage(logfile, message, severity, lineNumber, file);

        logfile.close();
    }

  private:
    ////////////////////////////////////////////////////////////
    static void putLogMessage(std::ofstream &log, const std::string &message, const std::string &severity,
                              uint32_t lineNumber, const char *file)
    {
        log << "[";
        TimeUtil::putTime(log, TimeUtil::now());
        log << "] ";

        std::ostringstream location;
        location << "[" << file << ":" << lineNumber << "]";

        log << location.str();

        int padding = 74 - location.str().length();
        if (padding > 0)
        {
            log << std::setw(padding) << " ";
        }

        log << severity << ": " << message << std::endl;
    }
};

} // namespace ls6502
