#ifndef XOR_H
#define XOR_H
#include <systemc.h>
#include <nand.h>

SC_MODULE(XOR)
{
	sc_in<bool>	C, D;
	sc_out<bool>	O;
	sc_signal<bool>	c, d, e, f;
	NAND 		n1, n2, n3, n4;

	void COMPORTEMENT();

	SC_CTOR(XOR) : n1("nand1"), n2("nand2"), n3("nand3"), n4("nand4")
	{
		SC_METHOD(COMPORTEMENT);

		n1.A(C);
		n1.B(D);
		n1.S(c);

		n2.A(C);
		n2.B(c);
		n2.S(e);

		n3.A(c);
		n3.B(D);
		n3.S(d);

		n4.A(e);
		n4.B(d);
		n4.S(O);

		sensitive << C << D;
	}
};

#endif
