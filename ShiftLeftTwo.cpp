#ifndef __SHIFTLEFTTWO_CPP__
#define __SHIFTLEFTTWO_CPP__

#include "ShiftLeftTwo.h"



// shifts the offset field to the left by two bits, making it a word offset

 static std::string Shift(std::string offsetField)
{
	std::bitset<32> shiftedOffSet(offsetField);
	shiftedOffSet  <<= 2;
	std::string s =shiftedOffSet.to_string();
	return s;
};

#endif