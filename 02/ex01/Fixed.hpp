#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int  fractional_bits = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &obj);
        Fixed& operator=( const Fixed &rhs );
        // std::ostream &operator<<( std::ostream &out, const Fixed &rhs );
        
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);