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
    std::ifstream file2("data.csv");
    if (!file2)
        throw std::invalid_argument("File Not Found");
    if (!std::getline(file2, line))
        throw std::runtime_error("Input file (error reading first line)");
    while (std::getline(file2, line))
    {
        strs = split_string_with_multiple_delemetres(line, " \t,");
        if (strs.size() != 2)
            throw std::runtime_error("Input file (error reading line)");
        database[strs[0]] = std::atof(strs[1].c_str());
    }

    return database;
}



std::vector<int>    check_input_data(std::string line){

    int i = 0;
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
    
    std::vector <std::string> strs = split_string_with_multiple_delemetres(line, " \t|");
    if (strs.size() != 2)
        throw std::invalid_argument("bad input");
    double value = std::atof(strs[1].c_str());
    if (value > 1000)
        throw std::runtime_error("too large a number");
    else if (value < 0)
        throw std::runtime_error("not a positive number");

    std::vector<std::string> input_date_splited_str = split_string_with_multiple_delemetres(strs[0], "-");


    if (input_date_splited_str.size() != 3 || input_date_splited_str[0].size() != 4 || input_date_splited_str[1].size() != 2 || input_date_splited_str[2].size() != 2)
        throw std::invalid_argument("bad input");


    std::vector<int> input_date_splited_int;
    input_date_splited_int.push_back(std::atoi(input_date_splited_str[0].c_str()));
    input_date_splited_int.push_back(std::atoi(input_date_splited_str[1].c_str()));
    input_date_splited_int.push_back(std::atoi(input_date_splited_str[2].c_str()));

    // std::cout << input_date_splited_int[0] << " " << input_date_splited_int[1] << " " << input_date_splited_int[2] << std::endl;

    return input_date_splited_int;
}

