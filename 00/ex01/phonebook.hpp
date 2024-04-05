#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <cstdio>
# include "contact.hpp"


class phonebook{
    private:
        contact contacts[8];
        int     index;
    public:
        phonebook();
        ~phonebook();

        void    add();
        void    search();
};

std::string string_process(std::string a);
std::string ft_input(std::string str);
std::string ft_input_number(std::string str);
std::string replace_whitespaces(std::string str);
void    view_contact(contact con, int index);
int    ft_is_valid(std::string input);
void    print_specific_contac();



#endif