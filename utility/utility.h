#ifndef TJLDATASTRUCTURES_UTILITY_H
#define TJLDATASTRUCTURES_UTILITY_H

namespace TJLDataStructures {

     

template<typename T>
struct identity {
    typedef T type;
};
template<typename T>
T&& forward(typename identity<T>::type&& param) { 
    return static_cast<typename identity<T>::type&&>(param); 
}



}

#endif //TJLDATASTRUCTURES_UTILITY_H
