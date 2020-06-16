
// COS30008, Problem Set 6, 2020

#pragma once

#include "List.h"
#include <stdexcept>

template<class T>
class Stack
{
private:
    List<T> fElements;

public:

    typedef typename List<T>::Iterator Iterator;

    bool isEmpty() const
    {
        //return if the List is empty
        return fElements.isEmpty();
    }
    int size() const
    {
        //return size of the List
        return fElements.size();
    }
    void push(const T& aItem)
    {
        //add item on the top of the stack
        fElements.push_front(aItem);    
    }
    void pop()
    {
        if (isEmpty())      //checking for underflow exception
            throw std::underflow_error("Stack empty.");
        else
            fElements.remove(top());    //remove the item on the top of the stack
    }
    const T& top() const
    {
        if (isEmpty())      //checking for underflow exception
            throw std::underflow_error("Stack empty.");
        else
            return fElements[0];    //return the first element in stack
    }

    // stack indexer
    const T& operator[](size_t aIndex) const
    {
        return fElements[aIndex];
    }

    // stack iterators
    Iterator begin() const
    {
        return fElements.begin();
    }
    Iterator end() const
    {
        return fElements.end();
    }
    Iterator rbegin() const
    {
        return fElements.rbegin();
    }
    Iterator rend() const
    {
        return fElements.rend();
    }
};

