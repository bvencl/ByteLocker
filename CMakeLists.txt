cmake_minimum_required(VERSION 3.10) # veri veri importánté

# Projekt neve és verziója
project(ByteLocker VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Forrásfájlok megadása
include_directories(${CMAKE_SOURCE_DIR}/include)

# Compiler kapcsolók, lehet a -Wextra túlzás, ha zavar akkor kivesszük
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_options(-Wall -Wextra -pedantic -g -fdiagnostics-color=always)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_options(/W4 /EHsc)
endif()

# Platformspecifikus beállítások, remélem eltaláltam mindent, javítsd ha érint és nem tetszik valami
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring for Linux")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    set(CMAKE_GENERATOR "Ninja")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring for Windows")
    set(CMAKE_GENERATOR "Visual Studio 16 2019") # Remélem jó, ha valakinek nem tetszik javítsa ki, én úgysem ezt használom
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
    endif()
endif()

# OpenSSL könyvtár, ha van jobb ötlet várom :)
find_package(OpenSSL REQUIRED)

# SFML könyvtár... Nem biztos hogy ezt az állatságot csinálnám, de egyelőre nincsen jobb ötletem
# find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

#Exectuable létrehozása
add_executable(ByteLocker
    src/main.cpp
    src/encryption.cpp
    src/decryption.cpp
    )

# Könyvtárak linkelése
# target_link_libraries(ByteLocker OpenSSL::SSL OpenSSL::Crypto sfml-graphics sfml-window sfml-system)
