#ifndef TJLDATASTRUCTURES_BITSET_H
#define TJLDATASTRUCTURES_BITSET_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

namespace TJLDataStructures {

enum Endian
{ 
    LittleEndian, 
    BigEndian
};

template <size_t N>
class bitset
{
public:
    bitset(const char *str, Endian endian = Endian::LittleEndian);
    bitset(size_t initialValue, Endian endian = Endian::LittleEndian);
    bitset(Endian endian = Endian::LittleEndian);
    
    bitset<N> &set(); //Set all bits
    bitset<N> &set(size_t whichOne); //Set single bit, range checked, throws std::out_of_range
    bitset<N> &setMultiple(size_t whatByte); //Sets multiple bits, from a passed in integer, throws std::runtime_exception
    
    bitset<N> &reset(); //Reset all bits
    bitset<N> &reset(size_t whichOne); //Reset single bit, range checked, throws std::out_of_range
    
    bitset<N> &flip(); //Flip all bits
    bitset<N> &flip(size_t whichOne); //Flip single bit, throws std::out_of_range

    bool any() const; //Check if any bit is set
    bool none() const; //Check if no bits are set
    bool all() const; //Check if all bits are set

    bool test(size_t whichOne) const; //Check single bit, range checked, throws std::out_of_range
    bool operator[](size_t whichOne); //Check single bit, non range checked

    size_t count() const; //Number of set bits
    size_t size() const; //Total number of bits

    Endian endian() const; //Endianness of bitset
    size_t toString(char *out, uint8_t spacing = 0); //String representation

private:
    size_t m_numberOfBits;
    size_t m_underlyingValue;
    Endian m_endian;

};

} //TJLDataStructures

#endif //ARDUINOPC_BITSET_H
