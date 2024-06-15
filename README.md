# ByteLocker - under development, project started on 2024.05.29

<!-- Home project for a file/folder locker for Windows. @2024.05.14 21:23 -->

ByteLocker is a C++ project aimed at creating a custom file encryption tool, inspired by BitLocker. The primary goal of ByteLocker is to provide secure file encryption and decryption using a user-defined password. This tool is designed to be cross-platform, working on both Windows and Linux/Ubuntu systems.

## Features when project finishes

- **File Encryption**: Encrypt files using strong encryption algorithms (e.g., AES, RSA...).
- **File Decryption**: Decrypt files using the same password used for encryption.
- **Cross-Platform Compatibility**: Designed to work on both Windows and Ubuntu systems. Supporting both Bash and PowerShell.
- **User-Friendly Interface**: Simple CLI for ease of use. (Or maybe a simple GUI later)

## Used packages / Toolchains for developing

### CMake version 3.28.3 or higher

**Windows:**
[Official site of CMake](https://cmake.org/download/)

**Ubuntu:**

    sudo apt install cmake

### Ninja version 1.11.1

**Windows:** [Ninja GitHub](https://github.com/ninja-build/ninja) (Or you could just use Visual Studio's)

**Ubuntu:**

    sudo apt install ninja-build
