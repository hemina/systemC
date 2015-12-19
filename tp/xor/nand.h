#ifndef NAND_H
#define NAND_H
#include <systemc.h>

SC_MODULE(NAND)
{
	sc_in<bool>	A, B;
	sc_out<bool>	S;

	void COMPORTEMENT();

	SC_CTOR(NAND)
	{
		SC_METHOD(COMPORTEMENT);
		sensitive << A << B;
	}
};

#endif
