#include "ScalarConverter.hpp"

// int main(int argc, char **argv)
// {
//     if (argc == 2)
//         ScalarConverter::convert(argv[1]);
//     return 0;
// }










class Base {
public:
    virtual ~Base() {}  // Ensure Base is polymorphic for dynamic_cast
};

class Derived1 : public Base {
public:
    void show() { std::cout << "Derived1 class\n"; }
};

class Derived2 : public Base {
public:
    void show() { std::cout << "Derived2 class\n"; }
};

int main() {
    Base* basePtr = new Base();  // Points to Derived1, not Derived2

    // static_cast: no runtime check, so this is undefined behavior
    Derived2* staticCastPtr = static_cast<Derived2*>(basePtr);
    staticCastPtr->show();  // May crash or show invalid data, undefined behavior

    // dynamic_cast: checks at runtime and returns nullptr if cast is invalid
    Derived2* dynamicCastPtr = dynamic_cast<Derived2*>(basePtr);
    if (dynamicCastPtr) {
        dynamicCastPtr->show();  // Won't be executed
    } else {
        std::cout << "dynamic_cast failed\n";  // Correct handling of failed cast
    }

    delete basePtr;
    return 0;
}