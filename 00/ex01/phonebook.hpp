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
std::string string_process_full_contact(std::string str, size_t y);
std::string ft_input(std::string str);
std::string ft_input_number(std::string str);
std::string replace_whitespaces(std::string str);
void        view_contact(contact *con, int index);
void        view_contact_all(contact con);
void        print_specific_contac(contact *contacts);
int         ft_is_valid(std::string input);
int         is_all_digit(std::string str);
size_t      get_larger_string(contact con);



#endif