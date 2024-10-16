#pragma once

#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>




void    BitcoinExchange(char const *file_path);
std::map<std::string, double>    read_db_check_infile(char const *file_path);
std::vector<std::string> split_string_with_multiple_delemetres(std::string &str, std::string delimiters);
std::string get_closer_date(std::map<std::string, double> database, std::string date);
std::vector<int>    check_input_data(std::string line);




