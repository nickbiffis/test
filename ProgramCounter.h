#ifndef __PROGRAM_COUNTER_H__
#define __PROGRAM_COUNTER_H__

#include <string>
//This h creates the guidlines for the program counter


// forward declarations needed can go below


class ProgramCounter
{
   private:
      std::string            currentAddress;

   public:
      ProgramCounter();
      ProgramCounter(std::string address);
      ~ProgramCounter();

      // getCurrentAddress will return the current address of the program 
      // counter as a string
      std::string    getCurrentAddress();
    
      //moveAddressTo will move the address in the PC to a given point, will
      //will be used for j type and branch instructions.  This method will
      //be called by control??
      std::string    moveAddressTo(std::string newAddress);

      //Increments the current address by 1 (4 bits)
      //std::string    incrementAddress();
     
     // Note: string is returned for the two methods above for testing purposes
};

#endif
