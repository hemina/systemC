#ifndef FLIPFLOP_H
#define FLIPFLOP_H
#include <systemc.h>
#include <latch.h>
#include <not.h>

SC_MODULE(FLIPFLOP)
{
	sc_in<bool>	CK, D, RST;
	sc_out<bool>	Q, QB;
	sc_signal<bool> a, b, c;
	LATCH l1, l2;
	NOT n1;

	void COMPORTEMENT();

	SC_CTOR(FLIPFLOP) : l1("latch1"), l2("latch2"), n1("not1")
	{
		SC_METHOD(COMPORTEMENT);

		n1.A(CK);
		n1.S(b);

		l1.D(D);
		l1.E(b);
		l1.Q(a);
		l1.RST(RST);
		l1.QB(c);

		l2.D(a);
		l2.Q(Q);
		l2.QB(QB);
		l2.RST(RST);
		l2.E(CK);

		sensitive << CK << D << RST;
	}
};

#endif
