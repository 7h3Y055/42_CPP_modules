#pragma once

#include <iostream>
#include <stdexcept>


class Bureaucrat
{
    private:
        std::string name;
        int         grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &);
        Bureaucrat &operator=(const Bureaucrat &);
        ~Bureaucrat();


        class GradeTooHighException  : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException  : public std::exception{
            public:
                char const *what() const throw();
        };
        
        std::string getName() const;
        int         getGrade() const;
        void        increment();
        void        decrement();
};

