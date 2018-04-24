#ifndef __SIGNEXTEND_H__
#define __SIGNEXTEND_H__

#include <bitset>
#include <string>
#include <iostream>


class SignExtend
{
	public:
		SignExtend(){}
		~SignExtend(){}

	static std::string Extend(std::bitset<16> sign_extend_val);
	
	
};
#endif