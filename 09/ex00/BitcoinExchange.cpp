#include "BitcoinExchange.hpp"


double get_closer_lower_date(std::map<std::string, double> database, std::vector<double> date){
    std::map<std::string, double>::iterator it = database.begin();
    std::map<std::string, double>::iterator lower_price;
    std::tm db_tm;
    std::tm in_tm = {};
    in_tm.tm_year = date[0] - 1900;
    in_tm.tm_mon = date[1] - 1;
    in_tm.tm_mday = date[2];

    std::time_t in_tm_ = std::mktime(&in_tm);

    double min = std::numeric_limits<double>::max();
    for (;it != database.end(); it++)
    {
        std::vector<double> db_date = string2date(it->first);
        db_tm.tm_year = db_date[0] - 1900;
        db_tm.tm_mon = db_date[1] - 1;
        db_tm.tm_mday = db_date[2];
        std::time_t db_tm_ = std::mktime(&db_tm);
        
        if (min > std::abs(std::difftime(in_tm_, db_tm_)))
        {
            lower_price = it;
            min = std::abs(std::difftime(in_tm_, db_tm_));
        }
    
    }
    if (string2date(lower_price->first)[0] == date[0] && string2date(lower_price->first)[1] == date[1] && string2date(lower_price->first)[2] == date[2])
        return database[lower_price->first];
    if (database.begin() != lower_price)
        lower_price--;
    return database[(lower_price)->first];
}

void    BitcoinExchange(char const *file_path){
    std::map<std::string, double>  database = read_db_check_infile(file_path);

    std::string line;
    std::ifstream file(file_path);
    if (!file)
        throw std::invalid_argument("File Not Found.");
    std::getline(file, line);
    while (std::getline(file, line))
    {
        try
        {
            std::vector<double> date = check_input_data(line);
            double price = get_closer_lower_date(database, date);
            std::vector<std::string> input = split_string_with_multiple_delemetres(line, "|");
            std::for_each(input.begin(), input.end(), trim);
            std::cout << input.front() << " => " << input.back() << " = ";
            double exchange_price = price * date.back();
            std::cout << exchange_price << std::endl;
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

