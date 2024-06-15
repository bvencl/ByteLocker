#pragma once

#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

#include "read.hpp"

class Rijndael
{
public:
    Rijndael(std::string passwordp) : password(passwordp)
    {
        generateKeyFromPassword(passwordp);
    }
    ~Rijndael() = default;

    void generateKeyFromPassword(std::string passwordp);
    // void generateKey();
    // void generateRoundKeys();
    // void generateSaltFromPassword();

    unsigned char shortkey;

private:
    std::string password;
    std::string key;
    std::string salt;
};

/*
Először a kulcsot kell legenerálni a jelszóból
Ebből a kulcsból további kulcsokat generálni a többi "körhöz"
Elvégezni a köröket
Új fájlba beírni a ciphertextet

Salt? IV?



*/