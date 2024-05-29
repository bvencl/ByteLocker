cmake_minimum_required(VERSION 3.10)

# Projekt neve és verziója
project(ByteLocker VERSION 1.0)

# C++ szabvány beállítása
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Forrásfájlok megadása
include_directories(${CMAKE_SOURCE_DIR}/include)

add_compile_options(-Wall -Wextra -pedantic -g -fdiagnostics-color=always)

add_executable(ByteLocker
    src/main.cpp
    
    )