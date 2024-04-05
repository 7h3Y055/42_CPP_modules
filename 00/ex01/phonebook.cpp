#include "phonebook.hpp"



void    phonebook::add(){
    contacts[index].Fname = ft_input("First name\t: ");
    contacts[index].Lname = ft_input("Last name\t: ");
    contacts[index].Nname = ft_input("Nackname\t: ");
    contacts[index].Pnumber = ft_input("Phone number\t: ");
    contacts[index].Dsecret = ft_input("Dark secret\t: ");
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
        view_contact(contacts[i], i);
    }
    if (contacts[0].Fname.empty()){
        std::cout << "\t+-------------------------------------------+" << std::endl;
        std::cout << "\t|                                      empty|" << std::endl;
        std::cout << "\t---------------------------------------------" << std::endl;
        return ;
    }
    std::cout << "\t---------------------------------------------" << std::endl;
    print_specific_contac();
}

void    print_specific_contac(){
    std::string input;

    while (1){
        std::cout << "SEARCH> " ;
        while (getline(std::cin, input)){

            std::cout << "RETRY SEARCH> " ;
        }
    }
}

std::string ft_input(std::string str){
    std::string input;

    std::cout << str;
    while (std::getline(std::cin, input)){
        if (input.empty()){
            std::cout << std::endl << "Wrong input!" << std::endl;
        }
        else
            break;
        std::cout << std::endl << "Retry " << str;
    }
    return (input);
}

void    view_contact(contact con, int index){
    std::cout << "\t+----------+----------+----------+----------+" << std::endl;
    std::cout << "\t|         " << index + 1 << "|";
    std::cout << string_process(con.Fname) << "|";
    std::cout << string_process(con.Lname) << "|";
    std::cout << string_process(con.Nname) << "|" << std::endl;
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