#pragma once


#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>

void        check_rpn_syntax(std::string str);
std::stack<int>  parse_rpn_numbers(std::string str);
std::string parse_rpn_operators(std::string str);
void        execute_rpn(std::stack<int> &rpn, std::string &operators);
