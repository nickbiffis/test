#ifndef __DATAMEMORY_CPP__
#define __DATAMEMORY_CPP__


#include "DataMemory.h"


DataMemory::DataMemory()  {}
DataMemory::DataMemory(string filename) {

ifstream infile;
  infile.open(filename);
    if (!infile.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  // Loop should run until eof().
  while(infile.good())
  {
    
     // mem[numOfMemcells] = vector<string>(2);
      //creates string and saves each line to input
      string input;
      infile >> input;
      int delimiter =input.find(":");
      //puts address in
      // mem[numOfMemcells][0] = input.substr(0,delimiter);
      string s1 =input.substr(0,delimiter);
       
       string s2 = input.substr(delimiter+1,input.length()-1);
       mem[s1]=s2;
      //puts instruction in
     // mem[numOfMemcells][1] = input.substr(delimiter+1,input.length()-1);
      //increments number of instructions
   }

  infile.close();
	
     
  
}

DataMemory::~DataMemory() {}

std::string DataMemory::getdata(std::string   theAddress){
	
 		return mem[theAddress];
}

void DataMemory::dmemPrint()
{

  map<string,string>::iterator it = mem.begin();
  it++;
  while(it != mem.end())
  {
    std::cout<< it->first << ":" << it->second <<endl;
    it++;
  }
}

void DataMemory::dmemPrintFinal(string memOutputFile)
{
  ofstream outputFile;
  outputFile.open(memOutputFile);
  map<string,string>::iterator it = mem.begin();
  it++;
  while(it != mem.end())
  {
    outputFile<< it->first << ":" << it->second <<endl;
    it++;
  }
  outputFile.close();
}
 
 
 #endif
