#ifndef LATCH_H
#define LATCH_H
#include <systemc.h>
#include <nand.h>

SC_MODULE(LATCH)
{
	sc_in<bool>	E, D;
	sc_out<bool>	Q, QB;

	void COMPORTEMENT();

	SC_CTOR(LATCH)
	{
		SC_METHOD(COMPORTEMENT);

		sensitive << E << D;
	}
};

#endif
