#ifndef __MULTIPLEXOR_CPP__
#define __MULTIPLEXOR_CPP__

#include <iostream>
#include "Multiplexor.h"

Multiplexor::Multiplexor(){}

Multiplexor::~Multiplexor(){}

//will be used by the Control Unit, which sends true or false based 
//on whether or not the mux is needed.
void Multiplexor::setFlow(int flow)
{
    this->flow = flow;
    
}
//Returns signal for testing 
int Multiplexor::getFlow()
{
    return flow;
}

//Set's input at point that coincides with 0 on the picture
std::string Multiplexor::setFirstInput(std::string firstInput)
{
	this->firstInput = firstInput;
	return this->firstInput;
}

//Sets input at 1 that coincides with 1 on picture
std::string Multiplexor::setSecondInput(std::string secondInput)
{
	this->secondInput = secondInput;
	return this->secondInput;
}


//calls mux
std::string Multiplexor::mux()
{
	if(this->flow == 0)
	{
		return this->firstInput;
	}
	else
	{
		return this->secondInput;
	}

}


#endif // MULTIPLEXOR_CPP_
