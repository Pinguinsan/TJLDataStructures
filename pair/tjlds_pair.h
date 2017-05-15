#ifndef TJLDATASTRUCTURES_PAIR_H
#define TJLDATASTRUCTURES_PAIR_H

namespace TJLDataStructures {

template <typename First, typename Second>
class pair
{
    public pair<First, Second>() :
        first{},
        second{}
    {

    }

    public pair<First, Second>(First f, Second s) :
        m_first{new First{f}},
        m_second{new Second{s}}
    {

    }
public:
    First &first;
    Second &second;

private:
    First *m_first;
    Second *m_second;
};

/*
template <typename First, typename Second>
pair<First, Second> make_pair(First &&first, Second &&second)
{
    return std::pair<First, Second>{std::forward<First>(first), std::forward<Second>(second)};

}
*/

#endif //TJLDATASTRUCTURES_PAIR_H
