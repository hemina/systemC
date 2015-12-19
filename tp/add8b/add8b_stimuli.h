#ifndef ADD8B_STIMULI_H
#define ADD8B_STIMULI_H
#include <systemc.h>

SC_MODULE(STIMULI)
{
	sc_in_clk	clk;
	sc_out<bool>	s1, s2, s3;

	void STIM();

	SC_CTOR(STIMULI)
	{
		SC_THREAD(STIM);
		sensitive << clk.pos();
	}
};

#endif
