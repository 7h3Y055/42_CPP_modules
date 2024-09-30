#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        const int gradeToSign;
        bool isSigned;
    public:
        Form();
        Form(std::string name, int gradeToSign);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        std::string getName() const;
        int getGradeToSign() const;
        bool    getIsSigned() const;

        int beSigned(const Bureaucrat &);
};

std::ostream &operator<<(std::ostream &out, const Form &r);



