/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2017-1-8
    Notes:
        Creates a new string from variadic arguments.
*/

#pragma once
#include <cstdarg>
#include <string>

namespace
{
    inline std::string va(const char *Format, ...)
    {
        char Resultbuffer[2049]{};
        std::va_list Varlist;

        // Create a string from the arguments and truncate if needed.
        va_start(Varlist, Format);
        std::vsnprintf(Resultbuffer, 2048, Format, Varlist);
        va_end(Varlist);

        return std::string(Resultbuffer);
    }
}
