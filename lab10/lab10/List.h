
// COS30008, Tutorial 10, 2020

#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

#include "Stages.h"

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

#ifdef A
    List()							        // default constructor - creates empty list
    {
        fTop = &Node::NIL;
        fLast = &Node::NIL;
        fCount = 0;
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
        Node* lNewElement = new Node(aElement);    // create a new node

        if (fTop == &Node::NIL)                    // Is this the first node?
        {
            fTop = lNewElement;                        // make lNewNode first node
            fLast = lNewElement;                    // make lNewNode last node as well
        }
        else
        {
            fTop->push_front(*lNewElement);       // make lNewElement previous of top
            fTop = lNewElement;                        // make lNewNode first node
        }

        fCount++;                                    // increment count
    }

#ifdef B
    void push_back(const T& aElement)	// adds a node initialized with aElement at back
    {
        Node* lNewElement = new Node(aElement);
        if (fTop == &Node::NIL)
        {
            fTop = lNewElement;
            fLast = lNewElement;
        }
        else
        {
            fLast->push_back(*lNewElement);
            fLast = lNewElement;
        }
        fCount++;
    }
#endif

#ifdef C
    void remove(const T& aElement)	    // remove node that matches aElement from list
    {
        Node* lNode = fTop;
        while (lNode != &Node::NIL) {
            if (lNode->getValue() == aElement)
                break;
            lNode = (Node*)&lNode->getNext();       //(Node*) is needed to convert const Node* to Node* ( because &lNode->getNext() return a const Node* )
        }
        if (lNode != &Node::NIL)
        {
            if (lNode == fTop)
            {
                fTop = (Node*)&fTop->getNext();     //(Node*) is needed to convert const Node* to Node* ( because &fTop->getNext() return a const Node* )
            }
            if (lNode == fLast)
            {
                fLast = (Node*)&fLast->getPrevious();   //(Node*) is needed to convert const Node* to Node* ( because &fLast->getPrevious() return a const Node* )
            }
            lNode.remove();
            delete lNode;
            fCount--;
        }
    }
#endif

#ifdef D
    const T& operator[](size_t aIndex) const	// list indexer
    {
        if (aIndex >= fCount || aIndex < 0)
        {
            throw std::range_error("Index out of bounds.");
        }
        else
        {
            Node* lNode = fTop;
            for (int i = 0; i < aIndex; i++)
                lNode = (Node*)&lNode->getNext();

            return lNode->getValue();
        }
    }
#endif

#ifdef A
    Iterator begin() const                 // return a forward iterator
    {
        return Iterator(*fTop);
    }
    Iterator end() const                   // return a forward end iterator
    {
        return begin().end();
    }
    Iterator rbegin() const                // return a backwards iterator
    {
        return begin().rbegin();
    }
    Iterator rend() const                  // return a backwards end iterator
    {
        return begin().rend();
    }
#endif
};

