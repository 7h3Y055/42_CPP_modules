#pragma once

#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>




void    check_input_file(char const *file_path);
void    BitcoinExchange(char const *file_path);
std::vector<std::string> split_string_with_multiple_delemetres();

