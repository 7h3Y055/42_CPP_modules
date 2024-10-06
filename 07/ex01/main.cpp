#include "iter.hpp"

void incrment(int &n){
    n++;
}

void printupper(char c){
    if (c >= 'a' && c <= 'z')
        std::cout << static_cast<char>(c-' ');
    else
        std::cout << c;
}


void ft_round(double &d){
    d = round(d);
}

int main(void)
{
    int arr[5] = {1, 1, 1, 1, 1};
    char const str[] = "hello world!\n";
    double arr2[] = {0.999, 5.2, 1.9876};
    


    iter(arr, 5, incrment);
    for (size_t i = 0; i < 5; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    


    iter(str, 13, printupper);
    

    iter(arr2, 3, ft_round);
    for (size_t i = 0; i < 3; i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
