//
//  ProgramCounter.cpp
//  
//
//  Created by Will Saada on 3/15/18.
//
//
#ifndef __PROGRAM_COUNTER_CPP__
#define __PROGRAM_COUNTER_CPP__

#include "ProgramCounter.h"
#include <string>

// This creates the program counter object

ProgramCounter::ProgramCounter(){}

ProgramCounter::ProgramCounter(std::string address)
{
    this->currentAddress = address;
}
    

    
ProgramCounter::~ProgramCounter(){}
    
    
        // getCurrentAddress will return the current address of the program
        // counter as a string
std::string    ProgramCounter::getCurrentAddress()
        {
            return currentAddress;
        }
    
        //moveAddressTo will move the address in the PC to a given point, will
        //will be used for j type and branch instructions
std::string    ProgramCounter::moveAddressTo(std::string newAddress)
    {
            this->currentAddress = newAddress;
            return currentAddress;
    }
    
        //Increments the current address by one.  Not implementated because
        //ALU is supposed to achieve that.  Should be able to use 
        //moveAddressTo() func to send incremented address.
/*std::string ProgramCounter::incrementAddress()
        {
            
            return currentAddress;
        }
    */

#endif
#include <stdio.h>
