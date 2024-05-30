#include "encryption.hpp"

void encryption(std::string filePath)
{
    std::vector<unsigned char> contents = readFileAsBinary(filePath);

    {
        for (unsigned char c : contents)
        {
            std::cout << std::hex << c;
        }
        std::cout << '\n';
    }
}