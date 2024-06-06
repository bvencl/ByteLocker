#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


inline std::vector<unsigned char> readFileAsBinary(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file.is_open())
        throw std::runtime_error("Unable to open the file @ fist open " + filePath);
    std::size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> readBuffer(size);

    if (!file.read(reinterpret_cast<char *>(readBuffer.data()), size))
        throw std::runtime_error("Unable to open the file @ reading " + filePath);

    return readBuffer;
}

std::string getPassword();
