#ifndef OR_H
#define OR_H
#include <systemc.h>

SC_MODULE(OR)
{
	sc_in<bool>	A, B;
	sc_out<bool>	S;

	void COMPORTEMENT();

	SC_CTOR(OR)
	{
		SC_METHOD(COMPORTEMENT);
		sensitive << A << B;
	}
};

#endif
