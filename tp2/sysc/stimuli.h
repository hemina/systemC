#ifndef NAND_STIMULI_H
#define NAND_STIMULI_H
#include <systemc.h>

SC_MODULE(STIMULI)
{
	sc_in_clk	CLK;

	void STIM();

	SC_CTOR(STIMULI)
	{
		SC_THREAD(STIM);
		sensitive << CLK.pos();
	}
};

#endif
