/*
	This "h file" sets up the guidelines for the RegisterFile 

*/

#ifndef __REGISTERFILE_H__
#define __REGISTERFILE_H__

#include <string>

using namespace std;

// Listing of all supported MIPS instructions
// Used to store information regarding desired registers by the user

typedef int Register;
const int NumRegisters = 32;

struct RegisterEntry{
	std::string 	name;
	Register 	   number;
	std::string		value;
};

class RegisterFile{
public:
	RegisterFile();
	~RegisterFile(){}


 Register getNum(string reg);
/*Given a string representing a MIPS register operand, returns the value associated
with said register. If the string is not a valid register, returns the number of registers
*/
	std::string 	readReg(string reg);

/*Given a string representing a MIPS register operand and a specified value, stores the value within
said register.
*/
	std::string		writeReg(string reg, string value);


private:
	RegisterEntry myRegisters[64];

};

#endif