#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>


Base *generate(void){
    int n = std::time(0) % 3;

    if (n == 0)
        return new A;
    else if (n == 1)
        return new B;
    else if (n == 2)
        return new C;

    return NULL;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "[+] Type is: 'A'" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "[+] Type is: 'B'" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "[+] Type is: 'C'" << std::endl;
    else
        std::cout << "[!] Undefined type" << std::endl;
}

void identify(Base& p){
    Base ref;

    try
    {
        ref = dynamic_cast<A&>(p);
        std::cout << "[+] Type is: 'A'" << std::endl;
    }
    catch(const std::exception& e){
        try
        {
            ref = dynamic_cast<B&>(p);
            std::cout << "[+] Type is: 'B'" << std::endl;
        }
        catch(const std::exception& e){
            try
            {
                ref = dynamic_cast<C&>(p);
                std::cout << "[+] Type is: 'C'" << std::endl;
            }
            catch(const std::exception& e){
                std::cout << "[!] Undefined type" << std::endl;
            }
        }
    }
}


