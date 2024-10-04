#include "Serializer.hpp"



#include <bitset>
#include <climits>


// void show_binrep(int n)
// {
//     uint32_t* ptr = reinterpret_cast<uint32_t*>(&n);

//     std::bitset<32> bits(*ptr);
//     std::cout << bits << std::endl;
// }

// void show_binrep(double d)
// {
//     uint64_t* ptr = reinterpret_cast<uint64_t*>(&d);

//     std::bitset<64> bits(*ptr);
//     std::cout << bits << std::endl;
// }


// int main () {
//     int i = 1337;
//     double *d = reinterpret_cast<double *>(&i);
//     std::cout << "binary of " << i << " =>\t\t\t\t\t\t"; show_binrep(i);
//     std::cout << "binary of " << *d << " =>\t"; show_binrep(*d);
//     return 0;
// }



int main()
{
    Data* data = new Data();
    data->name = "John";
    data->age = 25;
    data->a = 3.14;

    uintptr_t serialized = Serializer::serialize(data);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "A: " << deserialized->a << std::endl;
    return 0;
}
