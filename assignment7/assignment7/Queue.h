
// COS30008, Problem Set 7, 2020

#pragma once

#include "List.h"
#include <stdexcept>

template<class T>
class Queue
{
private:
    List<T> fElements;

public:
    typedef typename List<T>::Iterator Iterator;

    //Return if this queue is empty, make use of isEmpty() from List.h
    bool isEmpty() const
    {
        return fElements.isEmpty();
    }

    //Return size of this queue, make use of size() from List.h
    int size() const
    {
        return fElements.size();
    }

    //we need to use push_back() when adding element to the queue in order to maintain the FIFO style
    void enqueue(const T& aElement)
    {
        fElements.push_back(aElement);
    }

    //remove the first element from the queue
    void dequeue()
    {
        if (isEmpty())
            throw std::underflow_error("Queue is empty!");
        else
            fElements.remove(fElements[0]);
    }

    //return the first element of the queue
    const T& top() const
    {
        if (isEmpty())
            throw std::underflow_error("Queue is empty!");
        else
            return fElements[0];
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
