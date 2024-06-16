#include <iostream>

class Fixed
{
private:
    int fixed_point;
    static const int  fractional_bits = 8;
public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed& operator=( const Fixed &rhs );
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
