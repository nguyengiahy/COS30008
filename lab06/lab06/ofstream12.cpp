#include "ofstream12.h"
using namespace std;

void ofstream12::init()
{
	for (size_t i = 0; i < fBufferSize; i++)
		fBuffer[i] = 0;
	fByteIndex = 0;
	fBitIndex = 7;
}

void ofstream12::completeWriteBit()
{
	fBitIndex--;
	if (fBitIndex < 0)
	{
		fByteIndex++;
		fBitIndex = 7;

		if (fByteIndex == fBufferSize)
			flush();
	}
}

void ofstream12::writeBit0()
{
	completeWriteBit();
}

void ofstream12::writeBit1()
{
	fBuffer[fByteIndex] += 1 << fBitIndex;
	completeWriteBit();
}

ofstream12::ofstream12(const char* aFileName, size_t aBufferSize)
{
	fBufferSize = aBufferSize;
	fBuffer = new unsigned char[fBufferSize];
	init();
	open(aFileName);
}

ofstream12::~ofstream12()
{
	close();
	delete[] fBuffer;
}

void ofstream12::open(const char* aFilename)
{
	if (aFilename)
		fOStream.open(aFilename, ofstream::binary);
}

bool ofstream12::good() const
{
	return fOStream.good();
}

bool ofstream12::isOpen() const
{
	return fOStream.is_open();
}

void ofstream12::close()
{
	flush();
	fOStream.close();
}

void ofstream12::flush()
{
	fOStream.write((char*)fBuffer, fByteIndex + (fBitIndex % 7 ? 1 : 0));
	init();
}

ofstream12& ofstream12::operator<<(size_t aValue)
{
	for (size_t i = 0; i < 12; i++)
	{
		if (aValue & 0x1)
			writeBit1();
		else
			writeBit0();
		aValue >>= 1;
		return *this;
	}
}