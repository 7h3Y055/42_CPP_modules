#include "Span.hpp"

int main()
{
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // std::vector<int> vec;
        // vec.push_back(100);
        // vec.push_back(-99);
        // vec.push_back(-100);
        // sp.addNumber(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception const &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}


// #define MAX_NUM 10000

// int main()
// {
//     try
//     {
//         Span sp = Span(MAX_NUM);
//         std::cout << "[Start] Generate numbers." << std::endl;
//         for (unsigned int i = 0; i < MAX_NUM; i++){
//             sp.addNumber(rand());
//         }
//         std::cout << "[Done] Generate numbers." << std::endl << std::endl;

//         std::cout << "[+] Start testing 0" << std::endl;
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
        
//         Span copy = sp;
//         std::cout << "[+] Start testing 1" << std::endl;
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
        
//         Span copy2(copy);
//         std::cout << "[+] Start testing 2" << std::endl;
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return 0;
// }

