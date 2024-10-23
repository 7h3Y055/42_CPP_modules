#include "RPN.hpp"



int main(int argc, char const *argv[])
{
    if (argc == 2){
        try
        {
            check_rpn_syntax(argv[1]);
            execute_rpn(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}


