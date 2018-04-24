#ifndef __ControlUnit_CPP__
#define __ControlUnit_CPP__

#include "ControlUnit.h"

ControlUnit::ControlUnit(){}

ControlUnit::~ControlUnit(){}

void ControlUnit::setValues(std::string opcode)
{	
	//Jump instruction
	if(opcode == "000010")
	{
		this->jump = true;
	}

	//R-Type
	if(opcode == "000000")
	{
		regDest = true;
		regWrite = true;
		/// 10 so true, false
		aluOp0 = false;
		aluOp1 = true;
	}

	//I-Type
	//Addi
	if(opcode == "001000")
	{
		aluSrc = true;
		// I think? this means add
		aluOp0 = false;
		aluOp1 = false;
	}

	//LW
	if(opcode == "100011")
	{
		aluSrc = true;
		memToReg = true;
		regWrite = true;
		memRead = true;
		aluOp0 = false;
		aluOp1 = false;
	}

	//SW
	if(opcode == "101011")
	{
		aluSrc = true;
		memWrite = true;
		aluOp0 = false;
		aluOp1 = false;
	}

	//BEQ
	if(opcode == "000100")
	{
		branch = true;
		//Represents 01
		aluOp0 = true;
		aluOp1 = false;
	}
}

int ControlUnit::getRegDest()
{
	if(regDest)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getJump()
{
	if(jump)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getBranch()
{
	if(branch)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getMemRead()
{
	if(memRead)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getmemToReg()
{
	if(memToReg)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


// std::string ControlUnit::getAluOp()
// {

// 		return aluOp;
// }

int ControlUnit::getMemWrite()
{
	if(memWrite)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getAluSrc()
{
	if(aluSrc)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getRegWrite()
{
	if(regWrite)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getAluOp0()
{
	if(aluOp0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getAluOp1()
{
	if(aluOp1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void ControlUnit::setToZero()
{
	this->regDest = false;
	this->jump = false;
	this->branch = false;
	this->memRead = false;
	this->memToReg = false;
	this->aluOp0 = false;
	this->aluOp1 = false;
	this->memWrite = false;
	this->aluSrc = false;
	this->regWrite = false;
}

#endif    