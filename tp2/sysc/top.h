#ifndef TOP_H
#define TOP_H
#include <systemc.h>
#include <input.h>
#include <output.h>
#include <fft.h>

using namespace std;

SC_MODULE(TOP)
{
	sc_fifo<float>	O;
	sc_in<bool>	CLK;

	sc_signal<bool>	clk;
	sc_fifo<float> fifo_in, fifo_out;
	INPUT in;
	OUTPUT out;
	FFT fft;

	void COMPORTEMENT();

	SC_CTOR(TOP) : in("input"), out("output"), fft("fft"), fifo_in("fifo_in", 16), fifo_out("fifo_out", 16)
	{
		in.CLK(CLK);
		out.CLK(CLK);
		fft.CLK(CLK);

		in.O(fifo_in);
		fft.I(fifo_in);

		fft.O(fifo_out);
		out.I(fifo_out);

		SC_METHOD(COMPORTEMENT);
		sensitive << CLK;
	}
};

#endif
