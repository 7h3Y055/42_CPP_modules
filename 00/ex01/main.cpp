#include "phonebook.hpp"

void    print_help(){
    std::cout << "\t+----------------------------------+" << std::endl;
    std::cout << "\t|                           OPTIONS|" << std::endl;
    std::cout << "\t+----------------------------------+" << std::endl;
    std::cout << "\t|    ADD|         Add a new contact|" << std::endl;
    std::cout << "\t| SEARCH|      Search for a contact|" << std::endl;
    std::cout << "\t|   EXIT|      Exit the application|" << std::endl;
    std::cout << "\t+----------------------------------+" << std::endl;
}

int main()
{
    phonebook book;
    std::string cmd;
    print_help();
    std::cout << "> " ;
    while (std::getline(std::cin, cmd).good()){
        if (cmd == "ADD")
            book.add();
        else if (cmd == "SEARCH")
            book.search();
        else if (cmd == "EXIT")
            break;
        else if (!cmd.empty())
            std::cout << "Wrong input!" << std::endl;
        std::cout << "> " ;
    }
    std::cout << std::endl << "Bye" << std::endl;
    return 0;
}
