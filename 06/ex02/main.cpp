#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *ptr;

    ptr = generate();
    identify(*ptr);
    identify(ptr);
    delete ptr;
    return 0;
}
