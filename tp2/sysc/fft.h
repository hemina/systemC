#ifndef FFT_H
#define FFT_H
#include <systemc.h>

#define W {\
        {1, 0}, \
        {0.7071067812, -0.7071067812}, \
        {0, -1}, \
        {-0.7071067812, -0.7071067812}\
}

using namespace std;

typedef struct complex_s complex_t;

struct complex_s {
        float real;
        float imag;
};

SC_MODULE(FFT)
{
	sc_fifo_out<float>	O;
	sc_fifo_in<float>	I;
	sc_in<bool>		CLK;

	void COMPORTEMENT();
	void fft(complex_t in[8], complex_t out[8]);

	SC_CTOR(FFT)
	{
		SC_THREAD(COMPORTEMENT);
		sensitive << CLK.pos();
	}
};

#endif
