#pragma once

#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <limits>
#include <cmath>


#define DATABASE_PATH "data.csv"


void    BitcoinExchange(char const *file_path);
std::map<std::string, double>    read_db_check_infile(char const *file_path);
std::vector<std::string> split_string_with_multiple_delemetres(std::string &str, std::string delimiters);
double get_closer_lower_date(std::map<std::string, double> database, std::vector<double> date);
std::vector<double>    check_input_data(std::string line);
std::vector<double> string2date(std::string str);
void isValidDate(std::vector<double> date);
void    trim(std::string& str);


