#ifndef INPUT_H
#define INPUT_H
#include <systemc.h>

using namespace std;

SC_MODULE(INPUT)
{
	sc_fifo_out<float>	O;
	sc_in<bool>		CLK;

	void COMPORTEMENT();

	SC_CTOR(INPUT)
	{
		SC_THREAD(COMPORTEMENT);
		sensitive << CLK.pos();
	}
};

#endif
