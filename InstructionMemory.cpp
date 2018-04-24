#ifndef __INSTRUCTIONMEMORY_CPP__
#define __INSTRUCTIONMEMORY_CPP__


#include "InstructionMemory.h"


InstructionMemory::InstructionMemory()  {}
InstructionMemory::InstructionMemory(string filename) {
	Parser *parser;

    parser = new Parser(filename);
  
    if(parser->isFormatCorrect() == false){
        cerr << "Format of program input file is incorrect " << endl;
        exit(1);
    }

    Instruction i;

    i = parser->getNextInstruction();
    
    int instructionCounter = 0;

	string input;
    string address= "4000000"; //virtual address
    while( i.getOpcode() != UNDEFINED && instructionCounter <= 100){
        //Puts values into array, prints them for testing purposes.
        cout << i.getString() << endl;
        instructions[address]=i;
        int x = hextoint(address);
     	  x=x+4;
      	address=inttohex(x);
        //cout << i.getEncoding() << endl;
        i = parser->getNextInstruction();
        instructionCounter++;
    }
    
    delete parser;


     
  
      // std::cout<<address<<std::endl;
      // infile2 >> input;
    
     // std::cout<<input<<std::endl;
      //puts address in
      // instructions[numOfInstrucs][0] = address;
     
      //puts instruction in
     // instructions[numOfInstrucs][1] = input;
      //increments number of instructions
      // numOfInstrucs++;
     

}

InstructionMemory::~InstructionMemory() {}

Instruction InstructionMemory::getInstruction(std::string   theAddress){
	// std::string Instruction = thearray[10][1];
	// for(int i=0;i<100;i++){
	// 	Instruction = thearray[i][1];
	// 	if(thearray[i][0]==theAddress)
	// 		Instruction = thearray[i][1];
	// }
 		return instructions[theAddress];
}
int InstructionMemory::hextoint(std::string s ){
  stringstream ss (s);
  int x;
   ss>>hex>>x;
   return x;
}
string InstructionMemory::inttohex(int x){
  stringstream ss ;
  ss<<hex<<x;
  std::string s = ss.str();
  return s;
}

 
 
 #endif
