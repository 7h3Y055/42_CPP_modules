#include "Zombie.hpp"


int main()
{
    std::string name = "TEST";
    int 	   N = 1;

    Zombie *zombies = zombieHorde(N, name);

    int i = 0;
    while (i < N){
        zombies[i].announce();
        i++;
    }

    delete[] zombies;

    return 0;
}
