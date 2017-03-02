#ifndef TJLDATASTRUCTURES_BITSET_H
#define TJLDATASTRUCTURES_BITSET_H

#include <iostream>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>

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
    bitset(const char *str, Endian endian = Endian::LittleEndian) :
        m_numberOfBits{N},
        m_underlyingValue{0},
        m_endian{endian}
    {
        for (size_t i = 0; i < strlen(str); i++) {
            if ((str[i] != '0') && (str[i] != '1')) {
                //throw std::runtime_error();
            } else {
                if (str[i] == '1') {
                    this->set(i);
                }
            }
        }
    }

    bitset(size_t initialValue, Endian endian = Endian::LittleEndian) :
        m_numberOfBits{N},
        m_underlyingValue{0},
        m_endian{endian}
    {
        this->setMultiple(initialValue);
    }

    bitset(Endian endian = Endian::LittleEndian) :
        m_numberOfBits{N},
        m_underlyingValue{0},
        m_endian{endian}
    {

    }
    
    //Set all bits
    bitset<N> &set()
    {
        for (size_t i = 0; i < this->m_numberOfBits; i++) {
            this->setBit(i);
        }
        return *this;
    }

    //Set single bit, range checked, throws std::out_of_range
    bitset<N> &set(size_t whichOne)
    {
        if (whichOne >= this->m_numberOfBits) {
            char temp[255];
            snprintf(temp, 255, "bitset<%zu>::set(%zu): whichOne must be less than number of bits (%zu >= %zu)", this->m_numberOfBits, whichOne, whichOne, this->m_numberOfBits);
            throw std::out_of_range(temp);
        } else if (this->m_endian == Endian::LittleEndian) {
            this->m_underlyingValue |= 1 << (this->m_numberOfBits - whichOne - 1);
        } else {
            this->m_underlyingValue |= 1 << whichOne;
        }
        return *this;
    }

    //Sets multiple bits, from a passed in integer, nothrow (if byte is too large, it is truncated to fit)
    bitset<N> &setMultiple(size_t whatByte)
    {
        //TODO: Mask out unused bits
        for (int i = 0; i < this->m_numberOfBits; i++) {
            ((whatByte >> i) & 1) ? this->setBit(i) : this->resetBit(i);
        }
        return *this;
    }
    
    //Reset all bits
    bitset<N> &reset()
    {
        this->m_underlyingValue = 0;
        return *this;
    }

    //Reset single bit, range checked, throws std::out_of_range
    bitset<N> &reset(size_t whichOne)
    {
        if (whichOne > this->m_numberOfBits) {
            char temp[255];
            snprintf(temp, 255, "bitset<%zu>::reset(%zu): whichOne must be less than number of bits (%zu >= %zu)", this->m_numberOfBits, whichOne, whichOne, this->m_numberOfBits);
            throw std::out_of_range(temp);
        } else if (this->m_endian == Endian::LittleEndian) {
            this->m_underlyingValue &= ~(1 << (this->m_numberOfBits - whichOne - 1));
        } else {
            this->m_underlyingValue &= ~(1 << whichOne);
        }
        return *this;
    }
    
    bitset<N> &flip() //Flip all bits
    {
        for (size_t i = 0; i < this->m_numberOfBits; i++) {
            this->test(i) ? this->reset(i) : this->set(i);
        }
        return *this;
    }
    
    //Flip single bit, range checked throws std::out_of_range
    bitset<N> &flip(size_t whichOne)
    {
        if (whichOne > this->m_numberOfBits) {
            char temp[255];
            snprintf(temp, 255, "bitset<%zu>::flip(%zu): whichOne must be less than number of bits (%zu >= %zu)", this->m_numberOfBits, whichOne, whichOne, this->m_numberOfBits);
            throw std::out_of_range(temp);
        }
        this->test(whichOne) ? this->reset(whichOne) : this->set(whichOne);
        return *this;
    }

    //Check if any bit is set
    bool any() const
    {
        for (size_t i = 0; i < this->m_numberOfBits; i++) {
            if (this->test(i)) {
                return true;
            }
        }
        return false;
    }
    
    //Check if no bits are set
    bool none() const
    {
        for (size_t i = 0; i < this->m_numberOfBits; i++) {
            if (this->test(i)) {
                return false;
            }
        }
        return true;
    }
    
    //Check if all bits are set
    bool all() const
    {
        for (size_t i = 0; i < this->m_numberOfBits; i++) {
            if (!this->test(i)) {
                return false;
            }
        }
        return true;
    }

    //Check single bit, range checked, throws std::out_of_range
    bool test(size_t whichOne) const
    {
        if (whichOne > this->m_numberOfBits) {
            char temp[255];
            snprintf(temp, 255, "bitset<%zu>::test(%zu): whichOne must be less than number of bits (%zu >= %zu)", this->m_numberOfBits, whichOne, whichOne, this->m_numberOfBits);
            throw std::out_of_range(temp);
        } else if (this->m_endian == Endian::LittleEndian) {
            return static_cast<bool>((this->m_underlyingValue >> (this->m_numberOfBits - whichOne - 1)) & 1);
        } else {
            return static_cast<bool>((this->m_underlyingValue >> whichOne) & 1);
        }
    }
    
    //Check single bit, non range checked
    bool operator[](size_t whichOne)
    {
        if (this->m_endian == Endian::LittleEndian) {
            return static_cast<bool>((this->m_underlyingValue >> (this->m_numberOfBits - whichOne - 1)) & 1);
        } else {
            return static_cast<bool>((this->m_underlyingValue >> whichOne) & 1);
        }
    }

    //Number of set bits
    size_t count() const
    {
        size_t returnCount{0};
        for (size_t i = 0; i < this->m_numberOfBits; i++) {
            if (this->test(i)) {
                returnCount++;
            }
        }
        return returnCount;
    }
    
    //Total number of bits
    size_t size() const
    {
        return this->m_numberOfBits;
    }

    //Endianness of bitset
    Endian endian() const
    {
        return this->m_endian;
    }

    //String representation
    size_t toString(char *out, uint8_t spacing = 0)
    {
        char temp[2];
        size_t maximumSize = this->m_numberOfBits  + (spacing * (this->m_numberOfBits - 1)) + 1;
        if (this->m_endian == Endian::LittleEndian) {
            for (size_t i = this->m_numberOfBits - 1; i >= 0; i--) {
                snprintf(temp, 2, "%i", this->operator[](i));
                if (i == (this->m_numberOfBits - 1)) {
                    strncpy(out, temp, maximumSize);
                } else {
                    strncat(out, temp, maximumSize);
                }
                if ((i - 1) >= 0) {
                    for (uint8_t spaceCount = 0; spaceCount < spacing; spaceCount++) {
                        strncat(out, " ", maximumSize);
                    }
                }
                if (i == 0) {
                    break;
                }
            }
        } else if (this->m_endian == Endian::BigEndian) {
            for (size_t i = 0; i < this->m_numberOfBits; i++) {
                snprintf(temp, 2, "%i", this->operator[](i));
                if (i == 0) {
                    strncpy(out, temp, maximumSize);
                } else {
                    strncat(out, temp, maximumSize);
                } 
                if ((i + 1) != this->m_numberOfBits) {
                    for (uint8_t spaceCount = 0; spaceCount < spacing; spaceCount++) {
                        strncat(out, " ", maximumSize);
                    }
                }
            }
        } else {

        }
        return strlen(out);
    }

    friend bool operator==(const bitset<N> &lhs, const bitset<N> &rhs)
    {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        for (size_t i = 0; i < lhs.sie(); i++) {
            if (lhs.test(i) != rhs.test(i)) {
                return false;
            }
        }
        return true;
    }

private:
    size_t m_numberOfBits;
    size_t m_underlyingValue;
    Endian m_endian;

};

} //TJLDataStructures

#endif //ARDUINOPC_BITSET_H
