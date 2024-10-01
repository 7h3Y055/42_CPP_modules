#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(std::string str){
    ScalarConverter::print_char(str);
    ScalarConverter::print_int(str);
    ScalarConverter::print_float(str);
    ScalarConverter::print_double(str);
}

int ScalarConverter::get_type(std::string str){
    if (is_int(str)) return INT;
    else if (is_char(str)) return CHAR;
    else if (is_float(str)) return FLOAT;
    else if (is_double(str)) return DOUBLE;
    return INVALID;
}

char ScalarConverter::convert2char( std::string str){
    if (get_type(str) == CHAR)
        return str[0];
    else if (get_type(str) == INT)
        return static_cast<char>(std::atoi(str.c_str()));
    else if (get_type(str) == FLOAT)
        return static_cast<char>(std::atof(str.c_str()));
    else if (get_type(str) == DOUBLE)
        return static_cast<char>(std::atof(str.c_str()));

    return 0;
}

int ScalarConverter::convert2int( std::string str){
    
    return 0;
}

float ScalarConverter::convert2float( std::string str){
    
    return 0;
}

double ScalarConverter::convert2double( std::string str){
    
    return 0;
}


void ScalarConverter::print_char(std::string str){
    if (std::isprint(convert2char(str) ))
        std::cout << "char: '" << convert2char(str)  << "'" << std::endl;
    else if (static_cast<int>(convert2char(str) ) >= 0 && static_cast<int>(convert2char(str) ) <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::print_int(std::string str){
    // std::cout << "int: " << i << std::endl;
}

void ScalarConverter::print_float(std::string str){
    // std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::print_double(std::string str){
    // std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool ScalarConverter::is_int(std::string str){
    size_t i = 0;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    if ((str[0] == '+' || str[0] == '-') && i == 1 || i == 0)
        return false;
    return true;
}

bool ScalarConverter::is_float(std::string str){
    size_t i = 0;
    size_t temp = 0;
    
    if (str.find('.') == std::string::npos || str.find('f') == std::string::npos)
        return false;
    if (str[i] == '+' || str[i] == '-') i++;

    while (i < str.length() && isdigit(str[i])){
        i++;
        temp++;
    }

    if (str[i] == '.') i++;
    else return false;
    
    while (i < str.length() && isdigit(str[i])){
        i++;
        temp++;
    }
    
    if (str[i] == 'f') i++;
    else return false;
    if (i != str.length() || temp < 2)
        return false;
    return true;
}

bool ScalarConverter::is_double(std::string str){
    size_t i = 0;
    size_t temp = 0;
    
    if (str.find('.') == std::string::npos)
        return false;
    if (str[i] == '+' || str[i] == '-') i++;
    while (i < str.length() && isdigit(str[i])){
        i++;
        temp++;
    }
    if (str[i] == '.') i++;
    else return false;
    while (i < str.length() && isdigit(str[i])){
        i++;
        temp++;
    }
    if (i != str.length() || temp < 2)
        return false;
    return true;
}

bool ScalarConverter::is_char(std::string str){
    if (str.length() == 1 && static_cast<int>(str[0]) >= 0 && static_cast<int>(str[0]) <= 127)
        return true;
    return false;
}





ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){
}