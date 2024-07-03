#include "Fixed.hpp"

Fixed::Fixed():fixed_point(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n):fixed_point(n << this->fractional_bits){
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n):fixed_point(roundf(n * (1 << this->fractional_bits))){
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs ) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

float Fixed::toFloat( void ) const{
    return this->fixed_point / (float)(1 << this->fractional_bits);
}

int Fixed::toInt( void ) const{
    return this->fixed_point >> this->fractional_bits;
}

Fixed& Fixed::operator=( const Fixed &rhs ) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        fixed_point = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    return fixed_point;
}

void    Fixed::setRawBits( int const raw ) {
    fixed_point = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}








bool Fixed::operator<( const Fixed &r ){
    if (this->fixed_point < r.fixed_point) return true;
    else return false;
}

bool Fixed::operator>( const Fixed &r ){
    if (this->fixed_point > r.fixed_point) return true;
    else return false;
}

bool Fixed::operator>=( const Fixed &r ){
    if (this->fixed_point >= r.fixed_point) return true;
    else return false;
}

bool Fixed::operator<=( const Fixed &r ){
    if (this->fixed_point <= r.fixed_point) return true;
    else return false;
}

bool Fixed::operator==( const Fixed &r ){
    if (this->fixed_point == r.fixed_point) return true;
    else return false;
}

bool Fixed::operator!=( const Fixed &r ){
    if (this->fixed_point != r.fixed_point) return true;
    else return false;
}

float Fixed::operator+( const Fixed &r){
    return this->toFloat() + r.toFloat();
}

float Fixed::operator-( const Fixed &r){
    return this->toFloat() - r.toFloat();
}

float Fixed::operator*( const Fixed &r){
    return this->toFloat() * r.toFloat();
}

float Fixed::operator/( const Fixed &r){
    return this->toFloat() / r.toFloat();
}

Fixed &Fixed::operator++(){
    this->fixed_point++;
    return (*this);
}

Fixed &Fixed::operator--(){
    this->fixed_point--;
    return (*this);
}


Fixed Fixed::operator++(int v){
    Fixed tmp;
    tmp = *this;
    this->fixed_point++;
    return (tmp);
}



Fixed Fixed::operator--(int v){
    Fixed tmp;
    tmp = *this;
    this->fixed_point--;
    return (tmp);
}

static Fixed &min(Fixed &l, Fixed &r);
static Fixed &min(Fixed const &l, Fixed const &r);
static Fixed &max(Fixed &l, Fixed &r);
static Fixed &max(Fixed const &l, Fixed const &r);



