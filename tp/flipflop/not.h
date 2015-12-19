#ifndef NOT_H
#define NOT_H
#include <systemc.h>

SC_MODULE(NOT)
{
	sc_in<bool>	A;
	sc_out<bool>	S;

	void COMPORTEMENT();

	SC_CTOR(NOT)
	{
		SC_METHOD(COMPORTEMENT);
		sensitive << A;
	}
};

#endif
