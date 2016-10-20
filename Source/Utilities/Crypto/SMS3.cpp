/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2016-10-20
    Notes:
        This is mostly a wrapper around Goldboars implementation.
        See Thirdparty/goldboar for more information.
*/

#include "SMS3.h"
#include <memory>
#include "../../../Thirdparty\goldboar\sm3.h"

std::string AYRIA::SMS3::Hash(std::string Input)
{
    return Hash(Input.data(), Input.size());
}
std::string AYRIA::SMS3::Hash(const void *Data, size_t Length)
{
    auto Buffer = std::make_unique<uint8_t[]>(32);

    sm3((uint8_t *)Data, Length, Buffer.get());

    return std::string((char *)Buffer.get(), 32);
}
