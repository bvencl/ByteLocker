cmake_minimum_required(VERSION 3.10)

# Projekt neve és verziója
project(ByteLocker VERSION 1.0)

# C++ szabvány beállítása
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Kompilációs opciók hozzáadása
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_options(-Wall -Wextra -pedantic -g -fdiagnostics-color=always)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    if (MSVC)
        add_compile_options(/W4 /EHsc)
    else()
        add_compile_options(-Wall -Wextra -pedantic -g -fdiagnostics-color=always)
    endif()
endif()

# Platformspecifikus beállítások
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring for Linux")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    set(CMAKE_GENERATOR "Ninja")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring for Windows")
    if (MSVC)
        set(CMAKE_GENERATOR "Ninja")
    else()
        set(CMAKE_GENERATOR "Ninja")
    endif()
endif()

# Forrásfájlok megadása
include_directories(${CMAKE_SOURCE_DIR}/include)

# Végrehajtható fájl létrehozása
add_executable(bytelocker
    src/main.cpp
    src/encryption.cpp
    src/decryption.cpp
    src/rijndael.cpp
    src/read.cpp
)
