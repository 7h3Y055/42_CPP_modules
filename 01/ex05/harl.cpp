#include "harl.hpp"

void Harl::complain( std::string level ){
    const char arr[4][8] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void    (Harl::*functions[4])(void);
    Harl obj;

    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;

    int i = 0;
    while (i < 4 && level.compare(arr[i]) != 0){
        i++;
    }
    
    if (i < 4){
        (obj.*functions[i])();
        return;
    }

    std::cout << "this level does not exist!" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


Harl::Harl()
{
}

Harl::~Harl()
{
}