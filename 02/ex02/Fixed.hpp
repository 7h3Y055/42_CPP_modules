#include <iostream>
#include <cmath>

// >
// <
// >=
// <=
// ==
// !=
// +
// -
// *
// /
// a++
// ++a
// a--
// --a

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
        Fixed& operator=( const Fixed& );


        bool operator<( const Fixed& );
        bool operator>( const Fixed& );
        bool operator>=( const Fixed& );
        bool operator<=( const Fixed& );
        bool operator==( const Fixed& );
        bool operator!=( const Fixed& );
        float operator+( const Fixed& );
        float operator-( const Fixed& );
        float operator*( const Fixed& );
        float operator/( const Fixed& );
        // Fixed& operator++();
        // Fixed& operator++();
        // Fixed& operator++(int);
        // Fixed& operator++(int);


        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);