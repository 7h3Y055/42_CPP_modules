#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>


void test1(){
    std::vector<int> vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try
    {
        int f = easyfind(vec, 3);
        std::cout << "Number: " << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test2(){
    std::deque<int> vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try
    {
        int f = easyfind(vec, 3);
        std::cout << "Number: " << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test3(){
    std::list<int> vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try
    {
        int f = easyfind(vec, 3);
        std::cout << "Number: " << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}