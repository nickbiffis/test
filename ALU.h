#ifndef __ALU_H__
#define __ALU_H__

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <stdexcept>

using namespace std;

class ALU {

	public:

		// Default constructor
		ALU();

		// Sets the first input to the ALU
		// @pararm 	in_1 	32-bit binary string input
		inline void setInput_1(string in_1) { input_1 = in_1; }

		// Sets the second input to the ALU
		// @pararm 	in_2 	32-bit binary string input
		inline void setInput_2(string in_2) { input_2 = in_2; }

		// Sets the operation to be performed on the inputs
		// @pararm 	op 	string operation to be performed: "add", "sub", or "compare"
		inline void setOperation(string op) { operation = op; }

		// Performs appropriate operation on the ALU inputs
		void performOperation();

		// Returns the output of the operation performed on the given inputs
		// @return 	32-bit binary string result of operation
		inline string getResult() { return result; }

	private:

		string operation;	// Operation needed to perform: "add", "sub", or "compare"

		string input_1;		// First input to ALU
		string input_2;		// Second input to ALU

		string result; 		// Result of the given operation on the inputs

		// Subtracts input2 from input1 (binary numbers represented as strings) and returns the result
		// @param 	input1 	input to subtract from
		// @param	input2 	input subtracted from input1
		// @return 	string representation of input1 - input2
		string subtract(string input1, string input2);

		// Adds input1 and input2 (binary numbers represented as strings) and returns the result
		// @param 	input1 	one of two operands being summed
		// @param	input2 	one of two operands being summed
		// @return 	string representation of input1 + input2
		string add(string input1, string input2);

		// Returns "equal" if input1 and input2 are equivalent, "not_equal" otherwise
		// @param 	input1 	one of two operands being tested for equivalency 
		// @param	input2 	one of two operands being tested for equivalency 
		// @return 	"equal" if input1 and input2 are equivalent, "not_equal" if not
		string compare(string input1, string input2);


		// Helper functions

		// Converts 32-bit binary string input to its decimal value
		// @param 	input 	32-bit binary string input to convert
		// @return 	double decimal representation of given input
		double binaryToDecimal(string input);

		// Converts decimal input to its 32-bit binary string 
		// @param 	input 	decimal input to convert
		// @return 	string 32-bit binary representation of given input
		string decimalToBinary(double calculatedValue);

		// Computes the twos complement of a given binary string
		// @param 	bin 	32-bit binary string to convert
		// @return 	32-bit binary string representation of given input
		string computeTwosComplement(string bin);

};

#endif