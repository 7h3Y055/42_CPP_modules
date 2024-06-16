#include "harl.hpp"

int main()
{
    Harl test;

    test.complain("INFO");
    test.complain("ERROR");
    test.complain("DEBUG");
    test.complain("WARNING");
    test.complain("walo");
    return 0;
}
