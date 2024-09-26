#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        const int gradeToSign;
        bool isSigned;
    public:
        AForm();
        AForm(std::string name, int gradeToSign);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        ~AForm();

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
        void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &r);



#endif