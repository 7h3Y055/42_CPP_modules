#include "BitcoinExchange.hpp"


int main(int argc, char const *argv[])
{
    try
    {
        if (argc == 2)
            BitcoinExchange(argv[1]);
        else
            throw std::invalid_argument("Invalid number of arguments.");
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: "  << e.what() << "." << std::endl;
    }
    return 0;
}
