#include "read.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

std::string getPassword()
{
    std::cout << "Please give my a password to encrypt with! \nMy super storng password:" << std::endl;

#ifdef _WIN32

    HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
    DWORD newmode = 0;

    GetConsoleMode(console, &newmode);

    newmode &= ~ENABLE_ECHO_INPUT;

    SetConsoleMode(console, newmode);

    std::string password;
    std::getline(std::cin, password);

    newmode |= ENABLE_ECHO_INPUT;
    SetConsoleMode(console, newmode);

#else

    termios old, neww;             // struktúra, ami a terminál beállytásait tárolja
    tcgetattr(STDIN_FILENO, &old); // lekérjük a terminál attribútumait
    neww = old;                    // az újat a régivel inicializájuk

    neww.c_lflag &= ~ECHO;                   // ECHO kikapcsolása, hogy ne jelenjen meg a jelszó a képernyőn (Logikai ÉS művelettel bitenként allítjuk a flageket)
    tcsetattr(STDIN_FILENO, TCSANOW, &neww); // Beállítjuk az új flageket

    std::string password;
    std::getline(std::cin, password); // bekérjük a jelszót, immár úgy, hogy a karakterek nem jelennek meg a képernyőn

    tcsetattr(STDIN_FILENO, TCSANOW, &old); // visszaállítjuk a terminál régi beállításait

#endif

    return password;
}