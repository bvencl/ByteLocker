#pragma once

#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

// Can be 256, 192 and 128, default is 256
template <unsigned NUM = 256>
class Rijndael
{
public:
    Rijndael(std::string passwordp) : password(passwordp){};
    ~Rijndael() = default;

    void generateKeyFromPassword(const std::string &password);
    void generateSaltFromPassword(const std::string &password);

private:
    std::string password;
};