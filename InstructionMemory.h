#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__
//Get an address then release out data from memory that corresponds to that instruction

#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include "Instruction.h"
#include "Parser.h"
using namespace std;
class InstructionMemory{

private :
 std::map<string,Instruction> instructions;

public : 
 InstructionMemory();
 InstructionMemory(std::string filename);
 ~InstructionMemory();

Instruction getInstruction(std::string address);
int hextoint(std::string s );
std::string inttohex(int x);


};

#endif
