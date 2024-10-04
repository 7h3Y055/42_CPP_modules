#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>

enum e_Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    LITERAL,
    INVALID
};

class Type
{
    private:
        std::string str;
        int type;
        char c;
        int i;
        float f;
        double d;

        bool is_int();
        bool is_float();
        bool is_double();
        bool is_char();
        bool is_literal();
        void print_char();
        void print_int();
        void print_float();
        void print_double();
        void print_literal();
        void invalid_conversion();
    public:
        Type();
        Type(std::string str);
        ~Type();
        Type(const Type& other);
        Type& operator=(const Type& other);

        int Get_Type();
        void print_conversion();
        void convert();
};

