#include "BitcoinExchange.hpp"


std::vector<std::string> split_string_with_multiple_delemetres(std::string &str, std::string delimiters){
    std::vector<std::string> strs;

    size_t start_pos = 0;
    size_t end_pos = 0;

    while (end_pos != std::string::npos)
    {
        end_pos = str.find_first_of(delimiters, start_pos);
        if (start_pos != end_pos && str.substr(start_pos, end_pos - start_pos).length() > 0)
            // strs.push_back(str.substr(start_pos, end_pos - start_pos));
            std::cout << str.substr(start_pos, end_pos - start_pos) << "\n";
        start_pos = end_pos + 1;
    }
    std::cout << std::endl;
    return strs;
}

//             strs.push_back(str.substr(start_pos, end_pos - start_pos));

void    check_input_file(char const *file_path){
    std::ifstream file(file_path);
    if (!file)
        throw std::invalid_argument("File Not Found");

    std::string line;
    std::vector<std::string> strs;
    while (true){
        if (!std::getline(file, line))
            break;
        strs = split_string_with_multiple_delemetres(line, " \t");
        if (strs.front().empty())
            continue;
        // if (strs.size() != 3 || strs[0].compare("date")  || strs[1].compare("|") || strs[2].compare("value"))
            // throw std::runtime_error("Input file");
        break;
    }
    std::cout << strs.size() << std::endl;
    std::cout << strs[0].compare("date") << std::endl;
    std::cout << strs[1].compare("|") << std::endl;
    std::cout << strs[2].compare("value") << std::endl;
    std::cout << strs[3] << std::endl;
    std::cout << "DONE\n";
}

