#include "phonebook.hpp"

int main()
{
    phonebook book;
    std::string cmd;
    // book.add();
    // book.add();
    // book.add();
    // book.add();
    // book.add();
    // book.add();
    // book.search();
    // book.search();
    // book.search();
    // book.search();
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
