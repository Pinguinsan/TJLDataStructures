#ifndef TJLDATASTRUCTURES_PAIR_H
#define TJLDATASTRUCTURES_PAIR_H

#include "../utility/utility.h"

namespace TJLDataStructures {

template <typename First, typename Second>
class pair
{
public:
    pair<First, Second>() :
        first{},
        second{}
    {

    }

    pair<First, Second>(First &&f, Second &&s) :
        first{forward<First>(f)},
        second{forward<Second>(s)}
    {

    }

    pair<First, Second>(const pair<First, Second> &other) :
        first{other.first},
        second{other.second}
    {

    }

    pair<First, Second>(pair<First, Second> &&other) :
        pair<First, Second>{forward<pair<First, Second>>(other)}
    {

    }

    pair<First, Second> &operator=(const pair<First, Second> &other) {
        this->first = other.first;
        this->second = other.second;
    }

    pair<First, Second> &operator=(pair<First, Second> &&other) {
        this->first = other.first;
        this->second = other.second;
    }
public:
    First first;
    Second second;
};

    template <typename First, typename Second>
pair<First, Second> make_pair(First &&first, Second &&second)
{
    return pair<First, Second>{forward<First>(first), forward<Second>(second)};

}

}



#endif //TJLDATASTRUCTURES_PAIR_H
