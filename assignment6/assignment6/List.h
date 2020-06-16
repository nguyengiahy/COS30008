
// COS30008, Problem Set 6, 2020

#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

template<class T>
class List
{
private:
    // auxiliary definition to simplify node usage
    typedef DoublyLinkedNode<T> Node;

    Node* fTop;		// the first element in the list
    Node* fLast;	// the last element in the list
    int fCount;		// number of elements in the list

public:
    // auxiliary definition to simplify iterator usage
    typedef DoublyLinkedNodeIterator<T> Iterator;

    List()							        // default constructor - creates empty list
    {
        fTop = &Node::NIL;                  // initialize top
        fLast = &Node::NIL;                 // initialize last
        fCount = 0;                         // initialize count
    }

#ifdef NOT_IMPLEMENTED
    // PS6: copy control features (destructor is given)
    List(const List& aOtherList)                  // copy constructor
    {
        fTop = &Node::NIL;      //clear fTop's value
        fLast = &Node::NIL;     //clear fLast's value
        fCount = 0;             //clear fCount's value

        for (int i = 0; i < aOtherList.fCount; i++)
        {
            push_back(aOtherList[i]);       //add new node to the end of this list
        }
    }
    List& operator=(const List& aOtherList)       // assignment operator
    {
        //prevent self assignment
        if (&aOtherList != this)
        {
            //free the memory of this list
            while (fTop != &Node::NIL)
            {
                Node* temp = (Node*)&fTop->getNext();  // get next node (to become top)
                fTop->remove();                         // move first node
                delete fTop;                            // free node memory
                fTop = temp;                            // make temp the new top
            }

            //implement assignment 
            fCount = 0;
            for (int i = 0; i < aOtherList.fCount; i++)
            {
                push_back(aOtherList[i]);       //add new node to the end of this list
            }
        }
        return *this;
    }
#endif

    ~List() 						        // destructor - frees all nodes
    {
        while (fTop != &Node::NIL)
        {
            Node* temp = (Node*)&fTop->getNext();  // get next node (to become top)
            fTop->remove();                         // move first node
            delete fTop;                            // free node memory
            fTop = temp;                            // make temp the new top
        }
    }

    bool isEmpty() const	                // Is list empty?
    {
        return fTop == &Node::NIL;
    }

    int size() const                		// list size
    {
        return fCount;
    }

    void push_front(const T& aElement)	// adds a node initialized with aElement at front
    {
        Node* lNewElement = new Node(aElement);           // create a new node

        if (fTop == &Node::NIL)                           // Is this the first node?
        {
            fTop = lNewElement;                             // make lNewNode first node
            fLast = lNewElement;                            // make lNewNode last node as well
        }
        else
        {
            fTop->push_front(*lNewElement);               // make lNewElement previous of top
            fTop = lNewElement;                             // make lNewNode first node
        }

        fCount++;                                           // increment count
    }

    void push_back(const T& aElement)     // adds a node initialized with aElement at back
    {
        Node* lNewElement = new Node(aElement);           // create a new node

        if (fTop == &Node::NIL)                           // Is this the first node?
        {
            fTop = lNewElement;                             // make lNewNode first node
            fLast = lNewElement;                            // make lNewNode last node as well
        }
        else
        {
            fLast->push_back(*lNewElement);               // make lNewElement next of last
            fLast = lNewElement;                            // make lNewNode last node
        }

        fCount++;                                           // increment count
    }

    void remove(const T& aElement)	    // remove node that matches aElement from list
    {
        Node* lNode = fTop;                                 // start from the top

        while (lNode != &Node::NIL)                       // Are there still nodes available?
        {
            if (lNode->getValue() == aElement)            // Have we found the node?
                break;                                      // stop the search
            lNode = (Node*)&lNode->getNext();              // move to next node
        }

        // At this point we have either reached the end or found the node.
        if (lNode != &Node::NIL)                          // We have found the node.
        {
            if (lNode == fTop)                            // Was it the first node?
            {
                fTop = (Node*)&lNode->getNext();           // set top to next of node
            }
            if (lNode == fLast)                           // Was it the last node?
            {
                fLast = (Node*)&lNode->getPrevious();      // set last to previous of node
            }

            lNode->remove();                                // isolate node
            delete lNode;                                   // release node's memory
            fCount--;                                       // decrement count
        }
    }

    const T& operator[](size_t aIndex) const	            // list indexer
    {
        if (aIndex < fCount)                                  // Is index within bounds?
        {
            Node* lNode = fTop;                                 // start from the top
            while (aIndex)                                    // Have we reached the index?
            {
                // No
                aIndex--;                                       // decrement index
                lNode = (Node*)&lNode->getNext();               // move to next node
            }
            // Yes
            return lNode->getValue();                           // return node value
        }
        else
        {
            throw std::range_error("Index out of bounds.");    // signal error
        }
    }

    Iterator begin() const                  // return a forward iterator
    {
        return Iterator(*fTop);
    }

    Iterator end() const                    // return a forward end iterator
    {
        return begin().end();
    }

    Iterator rbegin() const                 // return a backwards iterator
    {
        return begin().rbegin();
    }

    Iterator rend() const                   // return a backwards end iterator
    {
        return begin().rend();
    }
};

