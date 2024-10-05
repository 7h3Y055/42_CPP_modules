#include "Array.hpp"


int main(){

    Array<int> a(3);

    try
    {
        a[0] = 1337;
        a[1] = 42;
        a[2] = -42;
        // a[3] = 404;

        for (int i = 0; i < 3; i++){
            std::cout << a[i] << std::endl;
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}