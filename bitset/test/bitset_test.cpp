#include <iostream>
#include "../tjlds_bitset.h"

#define SMALL_BUFFER_SIZE 255
#define BITSET_SIZE 16

using namespace TJLDataStructures;

int main()
{
    std::cout << "**SMALL ENDIAN TEST**" << std::endl;
    bitset<BITSET_SIZE> bits{};
    std::cout << bits << std::endl;

    for (int8_t i = 0; i < BITSET_SIZE; i++) {
        bits.set(i);
        std::cout << bits << std::endl;
    }
    
    for (int8_t i = BITSET_SIZE - 1; i >= 0; i--) {
        bits.reset(i);
        std::cout << bits << std::endl;
    }

    std::cout << std::endl << std::endl;
    std::cout << "***BIG ENDIAN TEST***" << std::endl;

    bits = bitset<BITSET_SIZE>{Endian::BigEndian};
    std::cout << bits << std::endl;
    for (int8_t i = 0; i < BITSET_SIZE; i++) {
        bits.set(i);
        std::cout << bits << std::endl;
    }

    for (int8_t i = BITSET_SIZE - 1; i >= 0; i--) {
        bits.reset(i);
        std::cout << bits << std::endl;
    }

    return 0;
}
