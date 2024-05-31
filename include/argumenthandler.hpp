#pragma once

#include <iostream>
#include <map>
#include <functional>
#include <string>
#include "encryption.hpp"
#include "decryption.hpp"

inline void printHelp()
{
    using namespace std;

    cout << "\nByteLocker version Alpha \n"
         << "Usage: bytelocker [options] [filepath]\n\n"
         << "\t --help \tDisplay this information.\n"
         << "\t -encrypt \tencrypt a file with ______ encryption algorythm.\n"
         << "\t -decrypt \tdecrypt a file with ______ encryption algorythm.\n"
         << endl;
}

inline void manageArguments(int argc, char *argv[])
{
    if (argc < 2)
        throw std::runtime_error("Too few arguments! For help please type --help");

    std::map<std::string, std::function<void(const std::string &)>> funcMap;
    funcMap["--help"] = [](const std::string &)
    { printHelp(); };
    funcMap["-encrypt"] = encryption;
    funcMap["-decrypt"] = decryption;

    std::string command = argv[1];
    if (funcMap.count(command))
    {
        if (command == "--help")
        {
            funcMap[command]("");
        }
        else
        {
            if (argc < 3)
                throw std::runtime_error("File path not provided! For help please type --help");

            std::string filePath = argv[2];
            funcMap[command](filePath); // Meghívódik a kívánt funkció a filePath változóval
        }
    }
    else
    {
        throw std::runtime_error("Invalid argument! For help please type --help");
    }
}
