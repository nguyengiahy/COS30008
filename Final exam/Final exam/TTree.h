// COS30008, Final Exam, 2020
#pragma once

#include <stdexcept>

#ifdef P3
#include "LinearVisitor.h"
#endif;

template<class T>
class TTree
{
private:

    T fKey;
    TTree<T>* fLeft;
    TTree<T>* fMiddle;
    TTree<T>* fRight;

    TTree() : fKey()        // use default constructor to initialize fKey
    {
        fLeft = &NIL;       // loop-back: The sub-trees of a TTree object with
        fMiddle = &NIL;     //            no children point to NIL.
        fRight = &NIL;
    }

    void addSubTree(TTree<T>** aBranch, const TTree<T>& aTTree)
    {
        if (*aBranch != &NIL)
        {
            delete* aBranch;
        }

        *aBranch = (TTree<T>*) & aTTree;
    }

    void removeSubTree(TTree<T>** aBranch);

public:

    static TTree<T> NIL;    // sentinel

    // TTree constructor (takes one argument)
    TTree(const T& aKey);

    // destructor (free sub-trees, must not free empty TTree)
    ~TTree();

    // copy constructor, must not copy empty TTree
    TTree(const TTree<T>& aOtherTTree);

    // assignment operator, must not copy empty TTree
    TTree<T>& operator=(const TTree<T>& aOtherTTree);

    // clone TTree, must not copy empty TTree
    TTree<T>* clone() const;

    // return key value, may throw domain_error if empty
    const T& getKey() const;

    // returns true if this TTree is empty
    bool isEmpty() const;

    // getters for subtrees
    const TTree<T>& getLeft() const
    {
        return *fLeft;
    }

    const TTree<T>& getMiddle() const
    {
        return *fMiddle;
    }

    const TTree<T>& getRight() const
    {
        return *fRight;
    }

    // add a subtree
    void addLeft(const TTree<T>& aTTree)
    {
        addSubTree(&fLeft, aTTree);
    }

    void addMiddle(const TTree<T>& aTTree)
    {
        addSubTree(&fMiddle, aTTree);
    }

    void addRight(const TTree<T>& aTTree)
    {
        addSubTree(&fRight, aTTree);
    }

    // remove a subtree, may through a domain error
    const TTree<T>& removeLeft()
    {
        return removeSubTree(&fLeft);
    }

    const TTree<T>& removeMiddle()
    {
        return removeSubTree(&fMiddle);
    }

    const TTree<T>& removeRight()
    {
        return removeSubTree(&fRight);
    }

    void traverseDepthFirst(TreeVisitor<T>& aVisitor) const
    {
        //only execute when this node is not NIL
        if (!isEmpty())
        {
            aVisitor.preVisit(getKey());
            fLeft->traverseDepthFirst(aVisitor);
            fMiddle->traverseDepthFirst(aVisitor);
            fRight->traverseDepthFirst(aVisitor);
            aVisitor.postVisit(getKey());
        }
        else
        {
            aVisitor.emitNIL();
        }
    }
};

template<class T>
TTree<T> TTree<T>::NIL;