
#ifndef __ControlUnit_H__
#define __ControlUnit_H__

#include <string> 

class ControlUnit
{
	protected:
		bool regDest;
		bool jump;
		bool branch;
		bool memRead;
		bool memToReg;
		bool aluOp0;
        bool aluOp1;
		bool memWrite;
		bool aluSrc;
		bool regWrite;

    

    public:
        ControlUnit();

        ~ControlUnit();

        void setValues(std::string opcode);

        void setToZero();

        int getRegDest();

        int getJump();

        int getBranch();

        int getMemRead();

        int getmemToReg();

        // std::string getAluOp();

        int getMemWrite();

        int getAluSrc();

        int getRegWrite();

        int getAluOp0();

        int getAluOp1();

        
};
#endif
