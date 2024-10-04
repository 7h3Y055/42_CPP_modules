#include "ScalarConverter.hpp"
#include "Type.hpp"

void ScalarConverter::convert(std::string str){
    Type type(str);

    type.convert();
    type.print_conversion();
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