#include "Zombie.hpp"

void test(){

    Zombie zombie1("[Stack Zombie]");
    zombie1.announce();


    Zombie *z = newZombie("[Heap Zombie]");
    z->announce();
    delete z;
    

    randomChump("[RandomChump Zombie]");

}

int main()
{
    std::cout << "[START]" << std::endl;
    test();
    std::cout << "[END]" << std::endl;
    return 0;
}
