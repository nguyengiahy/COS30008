#include "ifstream12.h"
#include <iostream>
using namespace std;

void ifstream12::init()
{
	for (size_t i = 0; i < fBufferSize; i++)
		fBuffer[i] = 0;
	fBytesAvailable = 0;
	fByteIndex = 0;
	fBitIndex = 7;
}

void ifstream12::reload()
{
	init();
	
	//fetch data from underlying stream
	fIStream.read((char*)fBuffer, fBufferSize);

	//get the number of bytes read in the last input operation
	fBytesAvailable = fIStream.gcount();
}

int ifstream12::readBit()
{
	if (fBytesAvailable == 0)
		reload();
	if (eof())
		return -1;

	//value of the next bit
	int result = (fBuffer[fByteIndex] & (1 << fBitIndex)) != 0;

	//advance to next position
	fBitIndex--;
	if (fBitIndex < 0)
	{
		fBytesAvailable--;
		fByteIndex++;
		fBitIndex = 7;
	}

	return result;
}

ifstream12::ifstream12(const char* aFileName, size_t aBufferSize)
{
	fBufferSize = aBufferSize;
	fBuffer = new unsigned char[fBufferSize];
	init();
	open(aFileName);
}

ifstream12::~ifstream12()
{
	close();
	delete[] fBuffer;
}

void ifstream12::open(const char* aFileName)
{
	if (aFileName)
		fIStream.open(aFileName, ifstream::binary);
}

void ifstream12::close()
{
	fIStream.close();
}

bool ifstream12::isOpen() const
{
	return fIStream.is_open();
}

bool ifstream12::good() const
{
	return fIStream.good();
}

bool ifstream12::eof() const
{
	return (fBytesAvailable == 0 && fIStream.eof());
}

ifstream12& ifstream12::operator>>(size_t& a12BitValue)
{
	a12BitValue = 0;   
	for (int i = 0; i < 12; i++) 
	{ 
		int bit = readBit();      
		if (bit == -1)
			break;
		else if (bit == 1) 
		{ 
			a12BitValue += (bit << i);
		} 
	}    
	return *this;
}