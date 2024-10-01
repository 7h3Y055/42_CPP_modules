#pragma once

#include <iostream>
#include <cstdlib>

enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static int get_type(std::string str);
        static bool is_int(std::string str);
        static bool is_float(std::string str);
        static bool is_double(std::string str);
        static bool is_char(std::string str);
        static void print_char( std::string str);
        static void print_int( std::string str);
        static void print_float( std::string str);
        static void print_double( std::string str);
        static char convert2char( std::string str);
        static int convert2int( std::string str);
        static float convert2float( std::string str);
        static double convert2double( std::string str);
    public:
        static void convert(std::string str);

};



