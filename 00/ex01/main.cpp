#include "phonebook.hpp"

int main()
{
    phonebook book;
    std::string cmd;

    // book.add();
    // book.add();
    // book.add();
    // book.add();
    // book.search();

    while (1){
        std::cout << "> " ;
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            book.add();
        else if (cmd == "SEARCH")
            book.search();
        else if (cmd == "EXIT")
            exit(0);
        else
            std::cout << std::endl << "Wrong input!" << std::endl;
        cmd = "";
        
        // std::cin.good();

        // std::cout << "> " ;
        // std::getline(std::cin, cmd);
        // exit(0);
    }
    std::cout << std::endl;
    return 0;
}
