#ifndef OUTPUT_H
#define OUTPUT_H
#include <systemc.h>

using namespace std;

SC_MODULE(OUTPUT)
{
	sc_fifo_in<float>	I;
	sc_in<bool>		CLK;

	void COMPORTEMENT();

	SC_CTOR(OUTPUT)
	{
		SC_THREAD(COMPORTEMENT);
		sensitive << CLK.pos();
	}
};

#endif
