CS301 Programming Assignment:

Classes:
This class will store the current address.  Classes that need access methods in this class are Instruction Memory and Multiplexor5.
ProgramCounter
	
	Constructors:
	ProgramCounter()
	ProgramCounter(string address)

	variables:
	string currentAddress

	methods:
	moveAddressTo(string address)
	-returns void
	getCurrentAddress()
	-returns the current address

Multiplexor Class:
This class defines a few methods that are needed for all multiplexors. Can create a Multiplexor object with input 1-5, each represents the different classes.  Instruction Memory, ALU, Control Unit, Register File, Shift Left, DataMemory, all have access to one of the five Multiplexor objects.  

	Constructors:
	Multiplexor(int num)

	Variables:
	int muxNumber
	int muxSignal
	string muxResult

	Method:
	//This method is set by control unit for each multiplexor, based on the opcode.
	setControl(int num)
	//Choses the result to pass on based on the signal and sets value
	//of the result.
	std::string mux();
	//Sends input to mux
    std::string setFirstInput(std::string firstInput);
    //Sends input to mux
    std::string setSecondInput(std::string secondInput);
    //Sets which part of mux is need
    void setSignal(bool signal);

    std::string getResult()
    
    bool getSignal();





