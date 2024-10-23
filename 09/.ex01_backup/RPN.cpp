#include "RPN.hpp"


void    check_rpn_syntax(std::string str){
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!(std::isdigit(str[i]) || std::isspace(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'))
            throw std::invalid_argument("ERROR");
    }    
}


bool valid_num_op(std::string str, int i){
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

int ft_is_digit(char c){
    return std::isdigit(c);
}

std::stack<int>  parse_rpn_numbers(std::string str){
    std::stack<int> stack;
    int n = std::count_if(str.begin(), str.end(), ft_is_digit);
    int *array = new int[n];
    size_t j = 0;
    
    size_t i;
    for (i = 0; i < str.size() && std::isspace(str[i]); i++){}
    for (; i < str.size() && j < n; i++)
    {
        if (!valid_num_op(str, i))
            throw std::invalid_argument("ERROR");
        if (!std::isspace(str[i]) && str[i] != '-' && str[i] != '+' && str[i] != '/' && str[i] != '*')
        {
            if (i > 0 && (str[i - 1] == '-' || str[i - 1] == '+'))
                array[j] = std::atoi(str.substr(i - 1, 2).c_str());
            else
                array[j] = std::atoi(str.substr(i , 1).c_str());
            j++;
        }
    }
    for (int k = n - 1; k >= 0; k--) {
        stack.push(array[k]);
    }
    delete[] array;
    return stack;
}

std::string parse_rpn_operators(std::string str){
    std::string ops;

    
    for (size_t i = 0; i < str.size(); i++)
    {
        if ((str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/') && !std::isdigit(str[i + 1]))
        {
            ops += str[i];
        }
    }

    return ops;
}

void        execute_rpn(std::stack<int> &rpn, std::string &operators){

    int a;
    int b;
    size_t i = 0;
    while (rpn.size() > 1 && operators[i]){
        a = rpn.top();
        rpn.pop();
        b = rpn.top();
        rpn.pop();

        std::cout << "[OPERATION] a: " << a << " b: " << b << " op: '" << operators[i] << "'" << std::endl;
        if (operators[i] == '+'){
            rpn.push(a + b);
        }
        else if (operators[i] == '-'){
            rpn.push(a - b);
        }
        else if (operators[i] == '/'){
            rpn.push(a / b);
        }
        else if (operators[i] == '*'){
            rpn.push(a * b);
        }
        i++;
    }
    std::cout << "[PRE RESULT] " << rpn.size() << " | " << operators.size() << " " << i << std::endl << std::endl;
    if (rpn.size() > 1 || operators[i])
        throw std::invalid_argument("ERROR");
    // std::cout << "[!]" << rpn.top() << std::endl;
    // rpn.pop();
    // std::cout << "[!]" << rpn.top() << std::endl;
    std::cout << "Result: " << rpn.top() << std::endl;

}

