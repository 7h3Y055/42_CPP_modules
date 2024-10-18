#include "RPN.hpp"


int main(int argc, char const *argv[])
{
    if (argc == 2){
        try
        {
            check_rpn_syntax(argv[1]);
            std::stack<int> rpn = parse_rpn_numbers(argv[1]);
            std::string operators = parse_rpn_operators(argv[1]);
            execute_rpn(rpn, operators);


            
            // std::cout << operators << std::endl;
            // while (!rpn.empty()) {
            //     std::cout << "|" << rpn.top() << "|\n";
            //     rpn.pop();
            // }
            // std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }
    return 0;
}


