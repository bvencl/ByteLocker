# ByteLocker

<!-- Home project for a file/folder locker for Windows. @2024.05.14 21:23 -->

ByteLocker is a C++ project aimed at creating a custom file encryption tool, inspired by BitLocker. The primary goal of ByteLocker is to provide secure file encryption and decryption using a user-defined password. This tool is designed to be cross-platform, working on both Windows and Ubuntu systems.

## Features

- **File Encryption**: Encrypt files using strong encryption algorithms (e.g., AES).
- **File Decryption**: Decrypt files using the same password used for encryption.
- **Cross-Platform Compatibility**: Designed to work on both Windows and Ubuntu systems. Supporting both Bash and PowerShell.
- **User-Friendly Interface**: Simple command-line interface for ease of use. (Or maybe a GUI later)

## Used packages

### OpenSSL

**Windows:**

If you have chocolatey installed you can install openssl via a single command i.e.

    choco install openssl

OR: (please don't... just use a package manager)

1. Download the OpenSSL for Windows installer from the following website: <https://slproweb.com/products/Win32OpenSSL.html>
2. Open the downloaded installer and follow the installation instructions.
3. After the installation is complete, add the OpenSSL library to the PATH environment variable. This can be done as follows:
    - Open System Properties.
    - Click on Environment Variables.
    - In the System variables section, find the PATH variable and click Edit.
    - Click New and add the path to the OpenSSL library (for example, `C:\OpenSSL-Win64\bin`).
    - Click OK to close the windows.

**Ubuntu:**

    sudo apt install libssl-dev

### CMake version 3.28.3

**Windows:**
[Official site of CMake](https://cmake.org/download/)

**Ubuntu:**

    sudo apt install cmake

### Ninja version 1.11.1

**Windows:** [Ninja GitHub](https://github.com/ninja-build/ninja)

**Ubuntu:**

    sudo apt install ninja-build
