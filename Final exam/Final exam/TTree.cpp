#include "TTree.h"
#include "TreeVisitor.h"
using namespace std;

template<class T>
void TTree<T>::removeSubTree(TTree<T>** aBranch)
{
	if (*aBranch == &NIL)
	{
		throw domain_error("Empty TTree encountered.");
	}
	*aBranch = &NIL;
}

template<class T>
TTree<T>::TTree(const T& aKey)
{
	fKey = aKey;
	fLeft = &NIL;       
	fMiddle = &NIL;     
	fRight = &NIL;
}

template<class T>
TTree<T>::~TTree()
{
	if (isEmpty())
	{
		throw domain_error("Empty TTree encountered.");
	}
	delete fLeft;
	delete fMiddle;
	delete fRight;
}

template<class T>
TTree<T>::TTree(const TTree<T>& aOtherTTree)
{
	if (&aOtherTTree == &NIL)
	{
		throw domain_error("Empty TTree encountered.");
	}

	fKey = aOtherTTree.fKey;
	fLeft = aOtherTTree.fLeft->clone();
	fMiddle = aOtherTTree.fMiddle->clone();
	fRight = aOtherTTree.fRight->clone();
}

template<class T>
TTree<T>& TTree<T>::operator=(const TTree<T>& aOtherTTree)
{
	if (&aOtherTTree == &NIL)
	{
		throw domain_error("Empty TTree encountered.");
	}

	if (this != &aOtherTTree)
	{
		~TTree();
		fKey = aOtherTTree.fKey;
		fLeft = aOtherTTree.fLeft->clone();
		fMiddle = aOtherTTree.fMiddle->clone();
		fRight = aOtherTTree.fRight->clone();
	}
	return *this;
}

template<class T>
TTree<T>* TTree<T>::clone() const
{
	if (!isEmpty())
	{
		return new TTree(*this);
	}
	else
	{
		return this;
	}
}

template<class T>
const T& TTree<T>::getKey() const
{
	if (isEmpty())
	{
		throw domain_error("Empty TTree encountered.");
	}
	return fKey;
}

template<class T>
bool TTree<T>::isEmpty() const
{
	return this == &NIL;
}

