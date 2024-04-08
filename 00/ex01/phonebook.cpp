#include "phonebook.hpp"



void    phonebook::add(){
    contacts[index].Fname = ft_input("First name\t: ", 0);
    contacts[index].Lname = ft_input("Last name\t: ", 0);
    contacts[index].Nname = ft_input("Nackname\t: ", 0);
    contacts[index].Pnumber = ft_input_number("Phone number\t: ");
    contacts[index].Dsecret = ft_input("Dark secret\t: ", 1);
    if (index == 7)
        index = 0;
    else
        index++;
}

void    phonebook::search(){
    std::cout << "\t---------------------------------------------" << std::endl;
    std::cout << "\t|----------------|CONTACTS☎|----------------|" << std::endl;
    std::cout << "\t+-------------------------------------------+" << std::endl;
    std::cout << "\t|     INDEX|FIRST NAME| LAST NAME|  NACKNAME|" << std::endl;
    for (int i = 0; i < 8 && !contacts[i].Fname.empty(); i++){
        view_contact(contacts, i);
    }
    if (contacts[0].Fname.empty()){
        std::cout << "\t+-------------------------------------------+" << std::endl;
        std::cout << "\t|                                      empty|" << std::endl;
        std::cout << "\t---------------------------------------------" << std::endl;
        return ;
    }
    std::cout << "\t---------------------------------------------" << std::endl;
    print_specific_contac(contacts);
}

int is_all_digit(std::string str)
{
    int i = 0;

    if (!str.length())
        return 0;
    while (str[i]){
        if (!std::isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

void    print_specific_contac(contact *contacts){
    std::string input;
    int index;

    std::cout << "SEARCH> " ;
    while (getline(std::cin, input)){
        if (is_all_digit(input)){
            index = std::atoi((const char*)input.c_str()) - 1;
            if (index > 7){
                std::cout << "The index is out of range!" << std::endl;
            }else{
                if (!contacts[index].Fname.length()){
                    std::cout << "The index is not in the scope!" << std::endl;
                }
                else{
                    view_contact_all(contacts[index]);
                return ;
                }
            }
        }else{
            std::cout << "Wrong input!" << std::endl;
        }
        std::cout << "SEARCH> " ;
    }
}

size_t get_larger_string(contact con){
    size_t large = con.Fname.length();

    if (large < con.Lname.length())
        large = con.Lname.length();

    if (large < con.Nname.length())
        large = con.Nname.length();
    
    if (large < con.Dsecret.length())
        large = con.Dsecret.length();
    
    if (large < con.Pnumber.length())
        large = con.Pnumber.length();
    
    return large;
}

void    view_contact_all(contact con)
{
    std::string separator;

    size_t y = get_larger_string(con);

    separator.append(y, '-');

    std::cout << "\t---------------" << separator  << "-" << std::endl;
    std::cout << "\t|   First name|" << string_process_full_contact(con.Fname, y)  << "|" << std::endl;
    std::cout << "\t|-------------+" << separator  << "|" << std::endl;
    std::cout << "\t|    Last name|" << string_process_full_contact(con.Lname, y)  << "|" << std::endl;
    std::cout << "\t|-------------+" << separator  << "|" << std::endl;
    std::cout << "\t|     nackname|" << string_process_full_contact(con.Nname, y)  << "|" << std::endl;
    std::cout << "\t|-------------+" << separator  << "|" << std::endl;
    std::cout << "\t| Phone number|" << string_process_full_contact(con.Pnumber, y)<< "|" << std::endl;
    std::cout << "\t|-------------+" << separator  << "|" << std::endl;
    std::cout << "\t|  Dark secret|" << string_process_full_contact(con.Dsecret, y)<< "|" << std::endl;
    std::cout << "\t---------------" << separator  << "-" << std::endl;
    
}

std::string string_process_full_contact(std::string str, size_t y){
    std::string new_str;

    if (str.length() != y)
        new_str.append(y - str.length(), ' ');
    new_str.append(str);
    return new_str;
}

std::string ft_input(std::string str, bool flag){
    std::string input;
    bool        good;

    good = 0;
    std::cout << str;
    while (!good){
        if (!std::getline(std::cin, input).good()){
            good = 1;
        }
        else{
            if (input.empty()){
                std::cout << "[!] Wrong input!" << std::endl;
            }
            else if (input.length() < 25 || flag)
                break;
            else
                std::cout << "[!] Too long!" << std::endl;
            std::cout << std::endl << str;
        }
    }
    if (good){
        std::cout << std::endl << "Bye" << std::endl;
        exit(0);
    }
    return (input);
}

std::string ft_input_number(std::string str){
    std::string input;
    bool        good;

    good = 0;
    std::cout << str;
    while (!good){
        if (!std::getline(std::cin, input).good()){
            good = 1;
        }
        else{
            if (input.empty() || ft_is_valid(input)){
                std::cout << "[!] Wrong input!" << std::endl;
            }
            else
                break;
            std::cout << std::endl << str;
        }
    }
    if (good){
        std::cout << std::endl << "Bye" << std::endl;
        exit(0);
    }
    return (input);
}

int    ft_is_valid(std::string input)
{
    int i = 0;
    int j = 0;

    if (input[i] == '+'){
        i++;
        j--;
    }
    while (input[i] && j < 3)
    {
        if (!std::isdigit(input[i]))
            break;
        i++;
        j++;
    }
    if (input[i] && std::isspace(input[i])){
        while (input[i] && std::isspace(input[i]))
            i++;
        j = 0;
    }
    while (input[i])
    {
        if (!std::isdigit(input[i]))
            break;
        i++;
        j++;
    }
    while (input[i] && std::isspace(input[i]))
        i++;

    if (input[i] || j < 2){
        return 1;
    }
    return 0;
}

void    view_contact(contact *con, int index){
    std::cout << "\t+----------+----------+----------+----------+" << std::endl;
    std::cout << "\t|         " << index + 1 << "|";
    std::cout << string_process(con[index].Fname) << "|";
    std::cout << string_process(con[index].Lname) << "|";
    std::cout << string_process(con[index].Nname) << "|" << std::endl;
}

std::string string_process(std::string a){
    std::string a_replaced;
    std::string b;

    a_replaced = replace_whitespaces(a);
    if (a_replaced.length() > 10){
        b = a_replaced.substr(0,9).append(".");
    }
    else{
        b.append(10 - a_replaced.length(),' ');
        b.append(a_replaced);
    }
    return b;
}

std::string replace_whitespaces(std::string str){
    size_t i = 0;
    std::string new_str;

    while (i < str.length()){
        if (std::isspace(str[i])){
            while (std::isspace(str[i]))
                i++;
            new_str.push_back(' ');
        }
        if (str[i])
            new_str.push_back(str[i]);
        i++;
    }
    return new_str;
}

phonebook::phonebook(){
    this->index = 0;
}

phonebook::~phonebook(){
    
}