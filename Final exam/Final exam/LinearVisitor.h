#pragma once
#include <iostream>
#include "TreeVisitor.h"

template<class T>
class LinearVisitor : public TreeVisitor<T>
{
public:
	// override pre-order behavior
	void preVisit(const T& aKey) const override
	{
		std::cout << " [";
		this->visit(aKey); 	// invoke default behavior
	}

	// override post-order behavior
	void postVisit(const T& aKey) const override
	{
		std::cout << " ]";
	}
};