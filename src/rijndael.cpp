#include "rijndael.hpp"

void Rijndael::generateKeyFromPassword(std::string passwoprd)
{
    for (size_t i = 0; i < passwoprd.length(); i++)
    {
        if (i % 3 == 0)
            shortkey &= passwoprd[i];
        else if (i % 3 == 1)
            shortkey |= passwoprd[i];
        else
            shortkey ^= passwoprd[i];
    }
}