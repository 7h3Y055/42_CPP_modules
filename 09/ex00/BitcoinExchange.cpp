#include "BitcoinExchange.hpp"


std::string get_closer_date(std::map<std::string, double> database, std::string date){
    // std::vector <std::string> strs = split_string_with_multiple_delemetres(date, " \t|");
    // if (strs.size() != 2)
    //     throw std::runtime_error("bad input");
    // std::cout << strs[0]  << std::endl;
    // std::map<std::string, double>::iterator it = database.begin();
    // for (; it != database.end(); it++)
    // {
        // for (size_t i = 0; date[i]; i++)
        // {
        //     if (date[i] == it->first[i])
        //         continue;
            
        // }
        
    // }
    return "";
}

void    BitcoinExchange(char const *file_path){
    std::map<std::string, double>  database = read_db_check_infile(file_path);

    std::string line;
    std::ifstream file(file_path);
    if (!file)
        throw std::invalid_argument("File Not Found");
    std::getline(file, line);
    while (std::getline(file, line))
    {
        try
        {
            std::vector<int> date = check_input_data(line);
            std::cout << line << " => 3 = 0.9" << std::endl;
            // std::string date = get_closer_date(database, line);
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "Error: "  << e.what() << " => " << line <<std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: "  << e.what() << "." <<std::endl;
        }
        
    }
        
}

