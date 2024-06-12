#pragma once

#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

#include "read.hpp"

// Can be 256, 192 and 128, default is 256
template <unsigned NUM = 256>
class Rijndael
{
public:
    Rijndael(std::string passwordp) : password(passwordp), bitcount(NUM){};
    ~Rijndael() = default;

    void generateKeyFromPassword();
    void generateKey();
    void generateRoundKeys();
    void generateSaltFromPassword();

private:
    std::string password;
    std::string key;
    std::string salt;
    unsigned bitcount;
};

/*
Először a kulcsot kell legenerálni a jelszóból
Ebből a kulcsból további kulcsokat generálni a többi "körhöz"
Elvégezni a köröket
Új fájlba beírni a ciphertextet

Salt? IV?



*/