#pragma once
#include <stdexcept>
#include <iostream>
template<class T>
class Handle
{
private:
	T* fPointer;
	int* fCount;
	void addRef()
	{
		++* fCount;
		// debug message        
		std::cout << "Add reference for " << std::hex << fPointer << ": " << *fCount << std::endl;
	}
	void releaseRef()
	{
		--* fCount;
		std::cout << "Release reference for " << std::hex << fPointer << ": " << *fCount << std::endl;

		if (*fCount == 0)
		{
			std::cout << "Destroy handle for " << std::hex << fPointer << ": " << *fCount << std::endl;
			delete fPointer;
			delete fCount;
		}
	}
public:
	Handle(T* aPointer = (T*)0)
	{
		fPointer = aPointer;
		fCount = new int;
		*fCount = 0;
		addRef();
	}

	~Handle()
	{
		releaseRef();
	}

	Handle(const Handle<T>& aOtherHandle)
	{
		fPointer = aOtherHandle.fPointer;
		fCount = aOtherHandle.fCount;
		addRef();
	}

	Handle& operator=(Handle<T>& aOtherHandle)
	{
		if (&aOtherHandle != this)
		{
			aOtherHandle.addRef();
			releaseRef();
			fPointer = aOtherHandle.fPointer;
			fCount = aOtherHandle.fCount;
		}
		return *this;
	}

	T& operator*()
	{
		if (fPointer)
			return *fPointer;
		else    
			throw std::runtime_error("Dereference of unbound handle!");
	}

	T* operator->()
	{
		if (fPointer)
			return fPointer;
		else    
			throw std::runtime_error("Access through unbound handle!");
	}
};
