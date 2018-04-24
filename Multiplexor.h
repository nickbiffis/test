
#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

#include <string> 

class Multiplexor
{
	protected:
    std::string firstInput;
    std::string secondInput;
    //0 or 1, based on value in the picture of the processor.
    int flow;

    public:
        Multiplexor();

        ~Multiplexor();

        std::string setFirstInput(std::string firstInput);

        std::string setSecondInput(std::string secondInput);

        std::string mux();

        void setFlow(int flow);

        int getFlow();
        
};

#endif
