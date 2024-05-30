#include "argumenthandler.hpp"

// "Usage: bytelocker [options] [filepath]"
int main(int argc, char *argv[])
{
    try
    {
        manageArguments(argc, argv);
    }
    catch (std::runtime_error &rtr)
    {
        std::cout << rtr.what()
                  << "\n"
                  << std::endl;
    }

    return 0;
}