
// COS30008, Tutorial 11, 2020

#pragma once

#include <stdexcept>

#include "TreeVisitor.h"

#include "Stages.h"

#include "Queue.h"

template<class T, int N>
class NTree
{
private:
    T fKey;                   		// T() for empty NTree
    NTree<T, N>* fNodes[N];          // N subtrees of degree N

    NTree() : fKey(T())                        // sentinel constructor
    {
        for (int i = 0; i < N; i++)
        {
            fNodes[i] = &NIL;
        }
    }

public:
    static NTree<T, N> NIL;          // sentinel

    NTree(const T& aKey) : fKey(aKey)         // a simple NTree with key and N subtrees
    {
        for (int i = 0; i < N; i++)
        {
            fNodes[i] = &NIL;
        }
    }

    virtual ~NTree()                               // destructor
    {
        for (int i = 0; i < N; i++)
        {
            if (fNodes[i] != &NIL)
            {
                delete fNodes[i];
            }
        }
    }


    NTree(const NTree& aOtherNTree)              // copy constructor
    {
        if (&aOtherNTree == &NIL)
        {
            throw std::domain_error("Copy of NIL requested.");
        }

        fKey = aOtherNTree.fKey;

        for (int i = 0; i < N; i++)
        {
            fNodes[i] = aOtherNTree.fNodes[i]->clone();
        }
    }

    NTree& operator=(const NTree& aOtherNTree)   // assignment operator
    {
        if (&aOtherNTree == &NIL)
        {
            throw std::domain_error("Copy of NIL requested.");
        }

        if (this != &aOtherNTree)
        {
            fKey = aOtherNTree.fKey;

            for (int i = 0; i < N; i++)
            {
                if (fNodes[i] != &NIL)
                {
                    delete fNodes[i];
                }

                fNodes[i] = aOtherNTree.fNodes[i]->clone();
            }
        }

        return *this;
    }

    virtual NTree* clone()                         // clone a tree
    {
        if (!isEmpty())
        {
            return new NTree(*this);
        }
        else
        {
            return this;
        }
    }

    bool isEmpty() const       // is tree empty
    {
        return this == &NIL;
    }

    const T& key() const       // get key (node value)
    {
        return fKey;
    }

    // indexer (allow for result modification by client - no const in result)
    NTree& operator[](size_t aIndex) const
    {
        if (isEmpty())
        {
            throw std::domain_error("NIL encountered.");
        }

        if (aIndex < N)
        {
            return *fNodes[aIndex];
        }
        else
        {
            throw std::out_of_range("aIndex out-of-bounds.");
        }
    }

    // tree manipulators (using constant references)
    void attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree)
    {
        if (isEmpty())
        {
            throw std::domain_error("NIL encountered.");
        }

        if (aIndex < N)
        {
            if (fNodes[aIndex] == &NIL)
            {
                fNodes[aIndex] = (NTree*)&aNTree;
            }
            else
            {
                throw std::domain_error("Non-empty slot encountered.");
            }
        }
        else
        {
            throw std::out_of_range("aIndex out-of-bounds.");
        }
    }

    const NTree& detachNTree(unsigned int aIndex)
    {
        if (isEmpty())
        {
            throw std::domain_error("NIL encountered.");
        }

        if (aIndex < N)
        {
            if (fNodes[aIndex] != &NIL)
            {
                const NTree& lNTree = *fNodes[aIndex];

                fNodes[aIndex] = &NIL;

                return lNTree;
            }
            else
            {
                throw std::domain_error("Non-empty slot encountered.");
            }
        }
        else
        {
            throw std::out_of_range("aIndex out-of-bounds.");
        }
    }

#if P>=2
    // depth-first traversal
    void traverseDepthFirst(const TreeVisitor<T>& aVisitor) const
    {
        //only execute when this node is not NIL
        if (!isEmpty())
        {
            aVisitor.preVisit(key());       //pre-visit the node

            //Using recursive to achieve Depth First Traversal
            for (int i = 0; i < N; i++)
            {
                fNodes[i]->traverseDepthFirst(aVisitor);
            }

            aVisitor.postVisit(key());      //post-visit the node
        }
    }
#endif

#if P>=3
    // breadth-first traversal
    void traverseBreadthFirst(const TreeVisitor<T>& aVisitor) const
    {
        Queue<const NTree<T,N>*> lQueue;    //A queue containing all of the unvisited nodes

        if (isEmpty())
        {
            throw std::domain_error("NIL encountered.");
        }
        else
        {
            lQueue.enqueue(this);           //Add this node to the queue to active the while loop
            while (!lQueue.isEmpty())       //Bread First Traversal stops when there are no more unvisited nodes
            {
                const NTree<T, N>& top = *lQueue.top();     //Getting the first element of the queue
                //Start visiting the node
                aVisitor.preVisit(top.key());   //pre-visit
                aVisitor.visit(top.key());      //visit
                for (int i = 0; i < N; ++i)
                {
                    if (!top.fNodes[i]->isEmpty())     //if this child node is not NIL => enqueue it
                    {
                        lQueue.enqueue(top.fNodes[i]);
                    }
                }
                aVisitor.postVisit(top.key()); //post-visit
                lQueue.dequeue();         //Dequeue the current node because we have just finished visiting it
            }
        }
    }
#endif
};

template<class T, int N>
NTree<T, N> NTree<T, N>::NIL;
