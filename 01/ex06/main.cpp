#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl test;

    if (argc != 2){
        std::cout << "[+] Usage: Please specify one of the following options:" << std::endl;
        std::cout << "\tDEBUG" <<std::endl;
        std::cout << "\tINFO" <<std::endl;
        std::cout << "\tWARNING" <<std::endl;
        std::cout << "\tERROR" <<std::endl;
        std::cout << "Example: ./harlfilter DEBUG" << std::endl;
        return 1;
    }
    test.complain(argv[1]);
    return 0;
}
