#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    return 0;
}









// class Base{};
// class Derived: public Base{
//     public:
//         long long a;
//         long long b;
//         long long c;
//         long long d;
//         long long e;
// };


// int main()
// {
//     Base b = Base();
//     Derived *ptr = static_cast<Derived*>(&b);

//     ptr->e = 1;
// }
