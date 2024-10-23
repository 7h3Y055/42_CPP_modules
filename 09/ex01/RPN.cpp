#include "RPN.hpp"

bool valid_num_op(std::string str, double i){
    if ((!std::isspace(str[i]) &&
            (i == 0 || str[i - 1] == '-' || str[i - 1] == '+' || std::isspace(str[i - 1])) && 
            (i == str.size() - 1 || std::isspace(str[i + 1]))) || 
    std::isspace(str[i]))
        return true;
    else if ((str[i] == '-' || str[i] == '+') && std::isdigit(str[i + 1]))
        return true;
    else
        return false;
}

void    check_rpn_syntax(std::string str){
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!(std::isdigit(str[i]) || std::isspace(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'))
            throw std::invalid_argument("ERROR");
    }

    int d = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!valid_num_op(str, i))
            throw std::invalid_argument("ERROR");
        if (std::isdigit(str[i]))
            d++;
        else if (!std::isspace(str[i]))
            d--;
    }
    if (d != 1)
        throw std::invalid_argument("ERROR");
}

void        execute_rpn(std::string input){
    std::stack<double> rpn;
    std::istringstream iss(input);
    std::string str;
    while (iss >> str)
    {
        if (rpn.size() >= 2 && (str == "+" || str == "-" || str == "*" || str == "/"))
        {
            double b = rpn.top();
            rpn.pop();
            double a = rpn.top();
            rpn.pop();
            if (str == "+")
                rpn.push(a + b);
            else if (str == "-")
                rpn.push(a - b);
            else if (str == "*")
                rpn.push(a * b);
            else if (str == "/" && b != 0)
                rpn.push(a / b);
            else if (b == 0){
                throw std::invalid_argument("[!] division by zero");
            }
            else
                throw std::invalid_argument("ERROR");
        }
        else 
            rpn.push(std::atoi(str.c_str()));
    }
    if (rpn.size() != 1)
        throw std::invalid_argument("ERROR");
    std::cout << std::fixed << std::setprecision(0) << rpn.top() << std::endl;
}

