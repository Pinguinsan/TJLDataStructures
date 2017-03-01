#include <iostream>
#include "../tjlds_bitset.h"

int main()
{
    TJLDataStructures::bitset<8> bits{};
    char temp[255];
    bits.toString(temp);
    std::cout << temp << std::endl;
    return 0;
}
