cmake_minimum_required(VERSION 3.10)

# Projekt neve és verziója
project(ByteLocker VERSION 1.0)

# C++ szabvány beállítása
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Forrásfájlok megadása
include_directories(${CMAKE_SOURCE_DIR}/include)

# Kompilációs opciók hozzáadása
add_compile_options(-Wall -Wextra -pedantic -g -fdiagnostics-color=always)

# Platformspecifikus beállítások
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring for Linux")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring for Windows")
    set(CMAKE_GENERATOR "Visual Studio 16 2019") # Remélem jó, ha valakinek nem tetszik javítsa ki, én úgysem ezt használom
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
    endif()
endif()

# OpenSSL könyvtár megtalálása
find_package(OpenSSL REQUIRED)

# SFML könyvtár megtalálása
# find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Végrehajtható fájl létrehozása
add_executable(ByteLocker
    src/main.cpp
    
    )

# Könyvtárak linkelése
# target_link_libraries(ByteLocker OpenSSL::SSL OpenSSL::Crypto sfml-graphics sfml-window sfml-system)
