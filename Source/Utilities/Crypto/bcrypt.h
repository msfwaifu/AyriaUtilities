/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2016-10-20
    Notes:
        This is mostly a wrapper around openwalls implementation.
        Requires SM3 hashing which should be in the usilities dir.
*/

#pragma once
#include <string>
#include <cstdint>

namespace AYRIA
{
    namespace bcrypt
    {
        std::string CreateHash(std::string &Header, std::string Input);
        std::string CreateSalt(size_t Workfactor, std::string Input);
        bool Verify(std::string &Hash, std::string Plain);
    }
}
