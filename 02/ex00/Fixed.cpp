#include "Fixed.hpp"



Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed( const Fixed &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(rhs.getRawBits());
}

Fixed& Fixed::operator=( const Fixed &rhs ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        fixed_point = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void    Fixed::setRawBits( int const raw ) {
    fixed_point = raw;
}
