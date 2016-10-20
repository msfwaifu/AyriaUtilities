/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2016-10-20
    Notes:
        This is mostly a wrapper around Goldboars implementation.
        See Thirdparty/goldboar for more information.
*/

#pragma once
#include <cstdint>
#include <string>

namespace AYRIA
{
    namespace SMS3
    {
        std::string Hash(std::string Input);
        std::string Hash(const void *Data, size_t Length);
    }
}
