/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2016-10-20
    Notes:
        This is mostly a wrapper around openwalls implementation.
        Requires SM3 hashing which should be in the usilities dir.
*/

#include "SMS3.h"
#include "bcrypt.h"
#include <algorithm>
#include "../../../Thirdparty/openwall/ow-crypt.h"

#define BCRYPT_HASHSIZE 64

std::string AYRIA::bcrypt::CreateHash(std::string &Header, std::string Input)
{
    char Hash[BCRYPT_HASHSIZE];
    auto Result = crypt_rn(Input.c_str(), Header.c_str(), Hash, BCRYPT_HASHSIZE);

    if (Result) return std::string(Result);
    else return std::string("");
}
std::string AYRIA::bcrypt::CreateSalt(size_t Workfactor, std::string Input)
{
    // Verify that workfactor is in range.
    Workfactor = std::min(size_t(31), Workfactor);
    Workfactor = std::max(size_t(4), Workfactor);

    // Generate a nice hash of the input.
    auto Localhash = AYRIA::SMS3::Hash(Input);

    // Create the actual hash.
    char Salt[BCRYPT_HASHSIZE];
    auto Result = crypt_gensalt_rn("$2a$", Workfactor, Localhash.data(), 16, Salt, BCRYPT_HASHSIZE);

    if (Result) return std::string(Result);
    else return std::string("");
}
bool AYRIA::bcrypt::Verify(std::string &Hash, std::string Plain)
{
    std::string Localhash = CreateHash(Hash, Plain);
    return 0 == std::strcmp(Hash.c_str(), Localhash.c_str());
}
