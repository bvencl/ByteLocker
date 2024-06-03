#include "encryption.hpp"
#include <termios.h>
#include <unistd.h>
#include <iomanip>

std::string getPassword()
{
    std::cout << "Please give my a password to encrypt with! \n\tMy super storng password:" << std::endl;

    termios old, neww;             // struktúra, ami a terminál beállytásait tárolja
    tcgetattr(STDIN_FILENO, &old); // lekérjük a terminál attribútumait
    neww = old;                    // az újat a régivel inicializájuk

    neww.c_lflag &= ~ECHO;                   // ECHO kikapcsolása, hogy ne jelenjen meg a jelszó a képernyőn (Logikai ÉS művelettel bitenként allítjuk a flageket)
    tcsetattr(STDIN_FILENO, TCSANOW, &neww); // Beállítjuk az új flageket

    std::string password;
    std::getline(std::cin, password); // bekérjük a jelszót, immár úgy, hogy a karakterek nem jelennek meg a képernyőn

    tcsetattr(STDIN_FILENO, TCSANOW, &old); // visszaállítjuk a terminál régi beállításait

    std::cout << std::endl;
    return password;
}

void encryption(const std::string &filePath)
{
    std::vector<unsigned char> contents;

    try
    {
        contents = readFileAsBinary(filePath);
    }
    catch (const std::runtime_error &rtr)
    {
        std::cerr << rtr.what() << '\n';
        return;
    }

    std::string password = getPassword();
    // std::cout << password << "\n\n" << std::endl;

    // Akkor itt most be van olvasva a file, és van egy jelszó. A jelszó alapján kell egy kulcsot generálni, majd aszerint egy új fájlba lekódolni az eredetiből beolvasott "szöveget"
    // Ezek után ki kell törölni az eredeti fájlt.

    for (unsigned char c : contents)
    {
        // std::cout << c;
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast<int>(c) << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';
    std::cout << std::dec << contents.size() << '\n';

    std::fstream file("hihi_kimasoltam_a_fiz_pdfet.pdf", std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Couldnt open the new file!");
        return;
    }

    file.write(reinterpret_cast<const char *>(contents.data()), contents.size());
    file.close();

    // Fasza, most már tudok binárisan másolni xd
}