#pragma once

#include <stdexcept>

#include "Stages.h"

template<class T, int N>
class NTree
{
private:
    T fKey;                   		// T() for empty NTree
    NTree<T, N>* fNodes[N];          // N subtrees of degree N

#if S>=1
    NTree() : fKey(T())                        // sentinel constructor
    {
        for (int i = 0; i < N; i++)
        {
            fNodes[i] = &NIL;
        }
    }
#endif

public:
    static NTree<T, N> NIL;          // sentinel

#if S>=1
    NTree(const T& aKey)         // a simple NTree with key and N subtrees
    {
        fKey = aKey;
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
               delete fNodes[i];
        }
    }
#endif

#if S>=3
    NTree(const NTree& aOtherNTree)              // copy constructor
    {
        if (aOtherNTree.isEmpty())
        {
            throw std::domain_error("Cannot copy an empty tree");
        }

        fKey = aOtherNTree.fKey;        //copy value for fKey
        //set the nodes
        for (int i = 0; i < N; i++)
        {
            fNodes[i] = aOtherNTree.fNodes[i]->clone();
        }
    }
    NTree& operator=(const NTree& aOtherNTree)   // assignment operator
    {
        if (aOtherNTree.isEmpty())
        {
            throw std::domain_error("Cannot assign an empty tree");
        }

        //guard
        if (this != &aOtherNTree)
        {
            //free the memory
            for (int i = 0; i < N; i++)
            {
                if (fNodes[i] != &NIL);
                    delete fNodes[i];
            }

            //assignment
            fKey = aOtherNTree.fKey;
            

            for (int i = 0; i < N; i++)
            {
                fNodes[i] = aOtherNTree.fNodes[i]->clone();
            }
        }

        return *this;
    }

    virtual NTree* clone()                         // clone a tree
    {
        if (isEmpty())
        {
            return this;
        }
        else
        {
            return new NTree(*this);
        }
    }
#endif

#if S>=1
    bool isEmpty() const       // is tree empty
    {
        return (this == &NIL);
    }
    const T& key() const       // get key (node value)
    {
        if (!isEmpty())
            return fKey;
        else
            throw std::domain_error("Empty NTree.");
    }

    // indexer (allow for result modification by client - no const in result)
    NTree& operator[](unsigned int aIndex) const
    {
        if (isEmpty())
            throw std::domain_error("Empty NTree!");

        if (aIndex >= N || aIndex < 0)
            throw std::out_of_range("Illegal subtree index!");
        else
            return *fNodes[aIndex];
    }

    // tree manipulators (using constant references)
    void attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree)
    {
        if (isEmpty())
            throw std::domain_error("Empty NTree!");

        if (aIndex >= N || aIndex < 0)
            throw std::out_of_range("Illegal subtree index!");
        else {
            if (fNodes[aIndex] != &NIL)
                throw std::domain_error("Non-empty subtree present!");
            else
                fNodes[aIndex] = (NTree<T,N>*)&aNTree;
        }
    }
    const NTree& detachNTree(unsigned int aIndex)
    {
        if (isEmpty())
            throw std::domain_error("Empty NTree!");

        if (aIndex >= N || aIndex < 0)
            throw std::out_of_range("Illegal subtree index!");
        else {
            if (fNodes[aIndex] != &NIL)
            {
                NTree<T, N>* result = fNodes[aIndex];
                fNodes[aIndex] = &NIL;
                return *result;
            }
            else
                throw std::domain_error("Non-empty slot encountered.");
        }
    }
#endif
};

template<class T, int N>
NTree<T, N>  NTree<T, N>::NIL;