
// COS30008, Tutorial 7, 2020

#pragma once

template<class DataType>
class DoublyLinkedNode
{
public:
    typedef DoublyLinkedNode<DataType> Node;	// nominal equivalence

private:
    DataType fValue;    // stored datum
    Node* fNext;        // forward pointer to next element
    Node* fPrevious;    // backward pointer to previous element

    // private default constructor for sentinel (not used elsewhere)
    DoublyLinkedNode()
    {
        fValue = DataType();        // initialize variable with DataType default
        fNext = &NIL;               // set forward pointer to Nil
        fPrevious = &NIL;           // set backwards pointer to Nil
    }

public:
    static Node NIL;                            // sentinel declaration

    DoublyLinkedNode(const DataType& aValue)  // constructor (unlinked node)
    {
        fValue = aValue;
        fNext = &NIL;
        fPrevious = &NIL;
    }

    void push_front(Node& aNode)              // aNode becomes previous node of this
    {
        aNode.fNext = this;                     // make this the forward pointer of aNode

        if (fPrevious != &NIL)                // make this's backward pointer aNode's
        {
            aNode.fPrevious = fPrevious;
            fPrevious->fNext = &aNode;          // tie back to Node
        }

        fPrevious = &aNode;                     // this' backward pointer becomes aNode
    }

    void push_back(Node& aNode)               // aNode becomes next node of this
    {
        aNode.fPrevious = this;                 // make this the backwards pointer of aNode

        if (fNext != &NIL)                    // make this's forward pointer aNode's
        {
            aNode.fNext = fNext;
            fNext->fPrevious = &aNode;          // tie back to Node
        }

        fNext = &aNode;
    }

    void remove()                               // remove this node
    {
        if (fPrevious != &NIL)                // unlink previous
        {
            fPrevious->fNext = fNext;
        }

        if (fNext != &NIL)                    // unlink next
        {
            fNext->fPrevious = fPrevious;
        }

        fPrevious = &NIL;                       // isolate this node
        fNext = &NIL;
    }

    // getter functions
    const DataType& getValue() const            // return constant reference to datum
    {
        return fValue;
    }

    const Node& getNext() const                 // return constant reference to next node
    {
        return *fNext;
    }

    const Node& getPrevious() const             // return constant reference to previous node
    {
        return *fPrevious;
    }
};

// sentinel implementation
template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;
