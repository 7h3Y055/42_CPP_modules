#include "BitcoinExchange.hpp"


std::vector<std::string> split_string_with_multiple_delemetres(std::string &str, std::string delimiters){
    std::vector<std::string> strs;
    size_t start_pos = 0;
    size_t end_pos = 0;

    while (end_pos != std::string::npos && start_pos < str.size())
    {
        end_pos = str.find_first_of(delimiters, start_pos);
        if (start_pos != end_pos)
            strs.push_back(str.substr(start_pos, end_pos - start_pos));
        start_pos = end_pos + 1;
    }
    return strs;
}

std::map<std::string, double>    read_db_check_infile(char const *file_path){
    std::ifstream file(file_path);
    if (!file)
        throw std::invalid_argument("File Not Found");

    // Check the first line
    std::string line;
    std::vector<std::string> strs;
    if (!std::getline(file, line))
        throw std::runtime_error("Input file (error reading first line)");
    strs = split_string_with_multiple_delemetres(line, " \t");
    if (strs.size() != 3 || strs[0].compare("date")  || strs[1].compare("|") || strs[2].compare("value"))
        throw std::runtime_error("Input file (need to  start with 'date | value')");
    file.close();

    // Read the database
    std::map<std::string, double> database;
    std::ifstream file2(DATABASE_PATH);
    if (!file2)
        throw std::invalid_argument("File Not Found.");
    if (!std::getline(file2, line))
        throw std::runtime_error("Input file (error reading first line)");
    while (std::getline(file2, line))
    {
        strs = split_string_with_multiple_delemetres(line, ",");
        std::for_each(strs.begin(), strs.end(), trim);
        if (strs.size() != 2)
            throw std::runtime_error("Input file (error reading line)");
        database[strs[0]] = std::atof(strs[1].c_str());
    }

    return database;
}

void isValidDate(std::vector<double> date) {
    std::tm time_in = {};
    time_in.tm_year = date[0] - 1900;
    time_in.tm_mon = date[1] - 1;
    time_in.tm_mday = date[2];

    std::time_t t = std::mktime(&time_in);

    if (t == -1)
        throw std::invalid_argument("invalid date");

    if (time_in.tm_year + 1900 != date[0] || time_in.tm_mon + 1 != date[1] || time_in.tm_mday != date[2])
        throw std::invalid_argument("invalid date");
}


std::vector<double> string2date(std::string str){
    std::vector<std::string> input_date_splited_str = split_string_with_multiple_delemetres(str, "-");

    if (input_date_splited_str.size() != 3 || input_date_splited_str[0].size() != 4 || input_date_splited_str[1].size() != 2 || input_date_splited_str[2].size() != 2)
        throw std::invalid_argument("bad input");

    std::vector<double> input_date_splited_int;
    input_date_splited_int.push_back(std::atoi(input_date_splited_str[0].c_str()));
    input_date_splited_int.push_back(std::atoi(input_date_splited_str[1].c_str()));
    input_date_splited_int.push_back(std::atoi(input_date_splited_str[2].c_str()));
    return input_date_splited_int;
}


std::vector<double>    check_input_data(std::string line){

    size_t i = 0;
    while (line[i])
    {
        while (line[i] && std::isspace(line[i])) i++;
        while (line[i] && std::isdigit(line[i])) i++;
        if (line[i] == '-')i++;
        else throw std::invalid_argument("bad input");
        while (line[i] && std::isdigit(line[i])) i++;
        if (line[i] == '-')i++;
        else throw std::invalid_argument("bad input");
        while (line[i] && std::isdigit(line[i])) i++;
        while (line[i] && std::isspace(line[i])) i++;
        if (line[i] == '|')i++;
        else throw std::invalid_argument("bad input");
        while (line[i] && std::isspace(line[i])) i++;
        if (line[i] == '-' || line[i] == '+')i++;
        while (line[i] && std::isdigit(line[i])) i++;
        if (line[i] == '.')i++;
        while (line[i] && std::isdigit(line[i])) i++;
        while (line[i] && std::isspace(line[i])) i++;
        if (i != line.size()) throw std::invalid_argument("bad input");
    }
    
    std::vector <std::string> strs = split_string_with_multiple_delemetres(line, "|");
    std::for_each(strs.begin(), strs.end(), trim);
    if (strs.size() != 2 || strs[0].empty() || strs[1].empty())
        throw std::invalid_argument("bad input");
    double value = std::atof(strs[1].c_str());
    if (value > 1000)
        throw std::runtime_error("too large a number");
    else if (value < 0)
        throw std::runtime_error("not a positive number");

    std::vector<double> date = string2date(strs[0]);
    isValidDate(date);
    date.push_back(value);
    return date;
}

void    trim(std::string& str){
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    if (first == std::string::npos || last == std::string::npos)
        str = "";
    else
        str = str.substr(first, (last - first + 1));
}