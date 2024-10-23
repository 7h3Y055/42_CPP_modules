#pragma once


#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iomanip>

void        check_rpn_syntax(std::string str);
void        execute_rpn(std::string str);
