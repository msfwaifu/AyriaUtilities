/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2016-10-20
    Notes:
        A simple system to log messages to disk and stdout.
        The logfile is stored in LOGFILEDIR\\MODULENAME.log.
*/

#pragma once

// Ensure we have something defined.
#ifndef LOGFILEDIR
#define LOGFILEDIR "./"
#endif
#ifndef MODULENAME
#define MODULENAME "Ayria"
#endif

namespace AYRIA
{
    namespace Debug
    {
        void DeleteLogfile();
        void AppendLogfileTimestamp(const char *Message);
        void AppendLogfile(const char *Message, const char *Prefix = nullptr);
    }
}
