#include "Type.hpp"


int Type::Get_Type(){
    if (is_int()) return INT;
    else if (is_float()) return FLOAT;
    else if (is_double()) return DOUBLE;
    else if (is_char()) return CHAR;
    else if (is_literal()) return LITERAL;
    return INVALID;
}

void Type::print_conversion(){
    type = Get_Type();

    if (type == CHAR) print_char();
    else if (type == INT) print_int();
    else if (type == FLOAT) print_float();
    else if (type == DOUBLE) print_double();
    else if (type == LITERAL) print_literal();
    else if (type == INVALID) invalid_conversion();
}

void Type::convert(){
    type = Get_Type();


    if (type == CHAR)
        c = str[0];
    else if (type == INT){
        if (atof(str.c_str()) < INT_MIN)
            i = INT_MIN;
        else if (atof(str.c_str()) > INT_MAX)
            i = INT_MAX;
        else
            i = static_cast<int>(atof(str.c_str()));
    }
    else if (type == FLOAT)
        f = atof(str.c_str());
    else if (type == DOUBLE)
        d = atof(str.c_str());
    else if (type == LITERAL)
    {
        if (str.compare("nanf") == 0 || str.compare("nan") == 0)
            f = d = NAN;
        else if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
            f = d = INFINITY;
        else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
            f = d = -INFINITY;
    }
}

void Type::print_char(){
    std::cout << std::setprecision(1) << std::fixed;

    if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << '\'' << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void Type::print_int(){
    std::cout << std::setprecision(1) << std::fixed;

    if (i < 32 || i > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << '\'' << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void Type::print_float(){
    std::cout << std::setprecision(1) << std::fixed;

    if (f < 32 || f > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << '\'' << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void Type::print_double(){
    std::cout << std::setprecision(1) << std::fixed;

    if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << '\'' << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void Type::print_literal(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl; 
}

void Type::invalid_conversion(){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;    
}


bool Type::is_int(){
    unsigned int i = 0;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    if (((str[0] == '+' || str[0] == '-') && i == 1) || i == 0)
        return false;
    return true;
}

bool Type::is_literal(){
    if (str.compare("nanf") == 0 || str.compare("+inff") == 0 || str.compare("-inff") == 0)
        return true;
    if (str.compare("nan") == 0 || str.compare("+inf") == 0 || str.compare("-inf") == 0)
        return true;
    return false;
}

bool Type::is_float(){
    unsigned int i = 0;
    unsigned int temp;
    
    if (str.find('.') == std::string::npos || str.find('f') == std::string::npos)
        return false;
    if (str[i] == '+' || str[i] == '-') i++;

    temp = i;
    while (i < str.length() && isdigit(str[i])) i++;
    if (temp == i)
        return false;

    if (str[i] == '.') i++;
    else return false;
    
    temp = i;
    while (i < str.length() && isdigit(str[i])) i++;
    if (temp == i)
        return false;
    
    if (str[i] == 'f') i++;
    else return false;
    if (i != str.length() || temp < 2)
        return false;
    return true;
}

bool Type::is_double(){
    unsigned int i = 0;
    unsigned int temp = 0;

    if (str.find('.') == std::string::npos)
        return false;
    if (str[i] == '+' || str[i] == '-') i++;
    temp = i;
    while (i < str.length() && isdigit(str[i])) i++;
    if (temp == i)
        return false;
    if (str[i] == '.') i++;
    else return false;
    temp = i;
    while (i < str.length() && isdigit(str[i])) i++;
    if (temp == i)
        return false;
    if (i != str.length() || temp < 2)
        return false;
    return true;
}

bool Type::is_char(){
    if (str.length() == 1)
        return true;
    return false;
}

Type::Type(): str(""), type(INVALID), c(0), i(0), f(0), d(0){
}

Type::Type(std::string str): str(str), type(INVALID), c(0), i(0), f(0), d(0){
}

Type::~Type(){
}

Type::Type(const Type& other){
    *this = other;
}

Type& Type::operator=(const Type& other){
    if (this != &other)
    {
        str = other.str;
        type = other.type;
        c = other.c;
        i = other.i;
        f = other.f;
        d = other.d;
    }
    return *this;
}