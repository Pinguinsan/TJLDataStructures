#ifndef TJLDATASTRUCTURES_LIST_H
#define TJLDATASTRUCTURES_LIST_H

#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>

namespace TJLDataStructures {

#ifdef SMALL_BUFFER_SIZE
    #undef SMALL_BUFFER_SIZE
#endif
    #define SMALL_BUFFER_SIZE 255



template <typename T>
class ListNode
{
    ListNode<T>(ListNode<T> *previous = nullptr) :
        m_data{T{}},
        m_previous
    {

    }

    ListNode<T>(const T &data, ListNode<T> *previous = nullptr) :
        m_data{data},
        m_previous
    {

    }

    void setPrevious(ListNode<T> *previous)
    {
        this->m_previous = previous;
    }

    void setNext(ListNode<T> *next)
    {
        this->m_next = next;
    }

    ListNode<T> *previous()
    {
        return this->m_previous;
    }

    ListNode<T> *next()
    {
        return this->m_next;
    }

    void setData(const T &data)
    {
        this->m_data = data;
    }

    T data() 
    {
        return this->m_data;
    }

private:
    ListNode<T> *m_previous;
    ListNode<T> *m_next;
    T m_data;
}

template <typename T>
class list
{
public:
    list<T>() :
        m_head{nullptr},
        m_size{0}
    list<T>(size_t numberOfElements);
    list<T>(const list<T> &other);

    list<T> &operator=(const list<T> &rhs)
    {

    }

    ~list<T>()
    {
        ListNode<T> *currentNode{this->m_head};
        ListNode<T> *nextNode{nullptr};
        if (currentNode != nullptr) {
            while (nextNode != nullptr) {
                nextNode = currentNode->next();
                delete currentNode;
                currentNode = nullptr;
            }
        }
    }

    bool empty() const
    {
        return this->m_head == nullptr;
    }

    size_t size() const
    {
        return this->m_size;
    }

    size_t max_size() const
    {
        if (sizeof(this->m_size) == 1) {
            return UCHAR_MAX;
        } else if (sizeof(this->m_size) == 2) {
            return USHRT_MAX;
        } else if (sizeof(this->m_size) == 4) {
            return UINT_MAX;
        } else if (sizeof(this->m_size) == 8) {
            return ULONG_MAX;
        } 
    }

    T front() 
    {
        if (this->m_head == nullptr) {
            //throw
        } else {
            return this->m_head->data();
        }
    }

    T back()
    {
        if (this->m_head == nullptr) {
            //throw
        } else {
            ListNode<T> *currentNode{this->m_head};
            while (currentNode->next() != nullptr) {
                currentNode = currentNode->next();
            }
            return currentNode->data();
        }
    }

    void push_front(const T &item)
    {
        ListNode<T> *newNode{new ListNode<T>{item}};
        ListNode<T> tempNodec
    }





private:
    ListNode<T> *m_head;
    size_t m_size;

/*
Iterators:
begin
    Return iterator to beginning (public member function )
end
    Return iterator to end (public member function )
rbegin
    Return reverse iterator to reverse beginning (public member function )
rend
    Return reverse iterator to reverse end (public member function )
cbegin
    Return const_iterator to beginning (public member funtion )
cend
    Return const_iterator to end (public member function )
crbegin
    Return const_reverse_iterator to reverse beginning (public member function )
crend
    Return const_reverse_iterator to reverse end (public member function )
*/

Modifiers:

assign
    Assign new content to container (public member function )

emplace_front
    Construct and insert element at beginning (public member function )

push_front
    Insert element at beginning (public member function )

pop_front
    Delete first element (public member function )

emplace_back
    Construct and insert element at the end (public member function )

push_back
    Add element at the end (public member function )

pop_back
    Delete last element (public member function )

emplace
    Construct and insert element (public member function )

insert
    Insert elements (public member function )

erase
    Erase elements (public member function )

swap
    Swap content (public member function )

resize
    Change size (public member function )

clear
    Clear content (public member function )


Operations:

splice
    Transfer elements from list to list (public member function )

remove
    Remove elements with specific value (public member function )

remove_if
    Remove elements fulfilling condition (public member function template )

unique
    Remove duplicate values (public member function )

merge
    Merge sorted lists (public member function )

sort
    Sort elements in container (public member function )

reverse
    Reverse the order of elements (public member function )



};

} //TJLDataStructures

#endif //TJLDATASTRUCTURES_LIST_H