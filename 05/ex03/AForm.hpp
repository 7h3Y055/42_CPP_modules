#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include <ctime>

class Form
{
    private:
        const std::string name;
        const int gradeToSign;
        const int gradeToExec;
        bool isSigned;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        virtual ~Form();

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
        int getGradeToExec() const;
        bool    getIsSigned() const;

        int beSigned(const Bureaucrat &);
        virtual int execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const Form &r);



