#include "BitcoinExchange.hpp"


int main(int argc, char const *argv[])
{
    try
    {
        if (argc == 2)
            BitcoinExchange(argv[1]);
        else
            throw std::invalid_argument("could not open file");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: "  << e.what() << "." << std::endl;
    }
    
    return 0;
}
