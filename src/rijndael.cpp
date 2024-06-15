#include "rijndael.hpp"

void Rijndael::generateKeyFromPassword(std::string passwoprd)
{
    for (size_t i = 0; i < passwoprd.length(); i++)
    {
        if (i % 3 == 0)
            shortkey |= passwoprd[i];
        else if (i % 3 == 1)
            shortkey &= passwoprd[i];
        else
            shortkey ^= passwoprd[i];
    }
    std::cout << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast<int>(shortkey) << "\n\n";
}