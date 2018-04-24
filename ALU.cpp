#include "ALU.h"

#include <bitset>
#include <math.h>

ALU::ALU() { }

void ALU::performOperation() {

	// Add : add, addi
	if (operation.compare("add") == 0) {
		result = add(input_1, input_2);
	}

	// Subtract : sub
	else if (operation.compare("sub") == 0) {
		result = subtract(input_1, input_2);
	}

	// Compare : beq
	else if (operation.compare("compare") == 0) {
		result = compare(input_1, input_2); 
	}

	// TODO : calculate address function for sw/lw?

}

string ALU::add(string input1, string input2) {
	
	double input1_dec = binaryToDecimal(input1);
	double input2_dec = binaryToDecimal(input2);

	double sum_dec = input1_dec + input2_dec;

	string sum_bin = decimalToBinary(sum_dec);

	return sum_bin;
}

string ALU::subtract(string input1, string input2) {

	double input1_dec = binaryToDecimal(input1);
	double input2_dec = binaryToDecimal(input2);

	double diff_dec = input1_dec - input2_dec;

	string diff_bin = decimalToBinary(diff_dec);

	return diff_bin;
}

string ALU::compare(string input1, string input2) {
	double input1_dec = binaryToDecimal(input1);
	double input2_dec = binaryToDecimal(input2);

	bool equals = (input1_dec == input2_dec);

	if (equals) {
		return "equal";
	}
	return "not_equal";
}

double ALU::binaryToDecimal(string input) {

	double decimal = 0.0;
	int power = 0;

	// For each char in the given 32-bit input
	for(int i = input.length() - 1; i >= 0; i--) {
		
		if (input.at(i) == '1') {
			decimal += pow(2.0, power);
		}
		power++;
	}

	return decimal;
}

string ALU::decimalToBinary(double value) { 
	bitset<32> bits = value;
	return bits.to_string();
}
