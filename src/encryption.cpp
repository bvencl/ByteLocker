#include "encryption.hpp"

void encryption(const std::string &filePath)
{
    std::string password = getPassword();
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

    //! Most be van olvasva a file, és van egy jelszó. A jelszó alapján kell egy kulcsot generálni, majd aszerint egy új fájlba lekódolni az eredetiből beolvasott "szöveget"
    //! Ezek után ki kell törölni az eredeti fájlt.
    // de nem itt :)

    {
        for (unsigned char c : contents)
        {
             std::cout << c;
            //std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast<int>(c) << ' ';
        }
        std::cout << '\n';
        std::cout << '\n';
        std::cout << std::dec << contents.size() << '\n';

        std::cout << password << "\n\n"
                  << std::endl;

        std::fstream file("generatedtest.txt", std::ios::out | std::ios::binary);
        if (!file.is_open())
        {
            throw std::runtime_error("Couldnt open the new file!");
            return;
        }
        file.write(reinterpret_cast<const char *>(contents.data()), contents.size());
        file.close();
    }

    // Fasza, most már tudok binárisan másolni xd
}