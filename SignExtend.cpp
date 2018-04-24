#ifndef __SIGNEXTEND_CPP__
#define __SIGNEXTEND_CPP__
#include "SignExtend.h"
#include <iostream>

std::string Extend(std::bitset<16> sign_extend_val){
std::string s ;

	if(sign_extend_val[15]==0){
		std::bitset<16> extended ;
		s=extended.to_string();
		s+=sign_extend_val.to_string();
	}
	else 
	{
		std::bitset<16> extended2 ;
		extended2.set();
		s=extended2.to_string();
		s+=sign_extend_val.to_string();
	}
	return s;
}
#endif
//This for testing purposes. 
// int main () {
// 	std::bitset<16> num;
// 	num.set(15,1);
// 	std::cout<<num.to_string()<<std::endl;
// 	std::string l =  Extend(num);
// 	std::cout<<l<<std::endl;
// };
