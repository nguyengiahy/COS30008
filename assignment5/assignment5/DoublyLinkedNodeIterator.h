#pragma once

#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedNodeIterator
{
private:
    enum IteratorStates { BEFORE, DATA, AFTER };

    IteratorStates fState;

    typedef DoublyLinkedNode<DataType> Node;

    const Node* fLeftmost;
    const Node* fRightmost;
    const Node* fCurrent;

public:
    typedef DoublyLinkedNodeIterator<DataType> Iterator;

    DoublyLinkedNodeIterator(const Node& aList)
    {
        //Find the first node of aList
        fLeftmost = &aList;
        while (&fLeftmost->getPrevious() != &Node::NIL)
            fLeftmost = &fLeftmost->getPrevious();

        //Initialise current iterator
        fCurrent = fLeftmost;

        //Find the last node of aList
        fRightmost = &aList;
        while (&fRightmost->getNext() != &Node::NIL)
            fRightmost = &fRightmost->getNext();

        //Set state for current iterator
        if (fCurrent != &Node::NIL)     //if not an empty list
            fState = DATA;
        else                            //if this is an empty list
            fState = AFTER;
    }

    const DataType& operator*() const      // dereference
    {
        return fCurrent->getValue();
    }
    Iterator& operator++()                 // prefix increment
    {
        switch (fState)
        {
            case BEFORE:    //if this iterator is before the first node, set it to the first node
                fCurrent = fLeftmost;
                break;
            case DATA:      //if this iterator is inside the list, advance to the next node
                fCurrent = &fCurrent->getNext();
                break;
            case AFTER:     //if this iterator is after the last node, we cannot increment it anymore -> do nothing
                break;
        }

        //after incrementing, if current node is nil => we are after the list
        if (fCurrent == &Node::NIL)
            fState = AFTER;
        //otherwise we are still inside the list
        else
            fState = DATA;

        return *this;
    }
    Iterator operator++(int)               // postfix increment
    {
        Iterator temp = *this;
        ++*this;
        return temp;
    }
    Iterator& operator--()                 // prefix decrement
    {
        switch (fState)
        {
            case BEFORE:    //if this iterator is before the first node, we cannot decrement it anymore -> do nothing
                break;
            case DATA:      //if this iterator is inside the list, decrement it to the previous node
                fCurrent = &fCurrent->getPrevious();
                break;
            case AFTER:     //if this iterator is after the last node, we set it to be the last node
                fCurrent = fRightmost;
                break;
        }

        //after decrementing, if current node is nil => we are before the list
        if (fCurrent == &Node::NIL)
            fState = BEFORE;
        //otherwise we are still inside the list
        else
            fState = DATA;

        return *this;
    }
    Iterator operator--(int)               // postfix decrement
    {
        Iterator temp = *this;
        --* this;
        return temp;
    }

    bool operator==(const Iterator& aOtherIter) const
    {
        return (fState == aOtherIter.fState && 
                fLeftmost == aOtherIter.fLeftmost && 
                fRightmost == aOtherIter.fRightmost && 
                fCurrent == aOtherIter.fCurrent);
    }
    bool operator!=(const Iterator& aOtherIter) const
    {
        return !(*this == aOtherIter);
    }

    //positioned at first element
    Iterator begin() const
    {
        Iterator temp = rend();     //rend is the node before the first node
        ++temp;                     //increment rend to be the first node of the list
        return temp;
    }

    //positioned after the last element
    Iterator end() const
    {
        Iterator temp = *this;
        temp.fCurrent = &Node::NIL;     //set temp to nil because it is positioned after the last element
        temp.fState = AFTER;            //set state to be AFTER
        return temp;
    }

    //positioned at the last element
    Iterator rbegin() const
    {
        Iterator temp = end();          //rbegin is the node after the last node
        --temp;                         //decrement rbegin to be the last node of the list
        return temp;
    }

    //positioned before the first element
    Iterator rend() const
    {
        Iterator temp = *this;
        temp.fCurrent = &Node::NIL;      //set temp to nil because it is positioned before the first element
        temp.fState = BEFORE;            //set state to be BEFORE
        return temp;
    }
};
