/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2017-1-8
    Notes:
        A simple system to log messages to disk and stdout.
        The logfile is stored in LOGFILEDIR/MODULENAME.log.
*/

#pragma once
#include <cstdio>
#include <ctime>
#include <mutex>
#include "Variadicstring.h"

// Ensure we have something defined.
#ifndef LOGFILEDIR
#define LOGFILEDIR "./"
#endif
#ifndef MODULENAME
#define MODULENAME "Ayria"
#endif

namespace
{
    // The full path to the logfile.
    constexpr const char *Logfilepath = LOGFILEDIR MODULENAME ".log";
    static std::mutex Logthreadguard;

    inline void Deletelogfile()
    {
        std::remove(Logfilepath);
    }
    inline void Log(const char *Message)
    {
        // Prevent multiple writes to the log.
        Logthreadguard.lock();
        {
            auto Filehandle = std::fopen(Logfilepath, "a");
            if (Filehandle)
            {
                std::fputs(Message, Filehandle);
                std::fputs("\n", Filehandle);
                std::fclose(Filehandle);
            }
        }
        Logthreadguard.unlock();

        // Duplicate the output to stdout.
#ifdef DEBUGTOSTREAM
        std::fputs(Message, stdout);
        std::fputs("\n", stdout);
#endif
    }
    inline void LogPrefix(const char *Message, const char *Prefix)
    {
        return Log(va("[%-8s] %s", Prefix, Message).c_str());
    }
    inline void LogTimestamp(const char *Message)
    {
        std::time_t Now = time(NULL);
        char Buffer [80];

        std::strftime(Buffer, 80, "%H:%M:%S", std::localtime(&Now));
        return LogPrefix(Message, Buffer);
    }
}
