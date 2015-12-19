#ifndef ADDD1B_H
#define ADDD1B_H
#include <systemc.h>
#include <nand.h>
#include <not.h>
#include <xor.h>
#include <or.h>

SC_MODULE(ADDD1B)
{
	sc_in<bool>	A, B, CIN;
	sc_out<bool>	S, COUT;
	sc_signal<bool> a, b, c, d, e;
	XOR xor1, xor2;
	NAND nand1, nand2;
	NOT n1, n2;
	OR or1;

	void COMPORTEMENT();

	SC_CTOR(ADDD1B) : xor1("xor1"), xor2("xor2"), nand1("nand1"), nand2("nand2"), n1("n1"), n2("n2"), or1("or1")
	{
		SC_METHOD(COMPORTEMENT);

		xor1.C(A);
		xor1.D(B);
		xor1.O(a);

		xor2.C(a);
		xor2.D(CIN);
		xor2.O(S);

		nand1.A(A);
		nand1.B(B);
		nand1.S(b);

		n1.A(b);
		n1.S(c);

		nand2.A(a);
		nand2.B(CIN);
		nand2.S(d);

		n2.A(d);
		n2.S(e);

		or1.A(c);
		or1.B(e);
		or1.S(COUT);

		sensitive << A << B << CIN;
	}
};

#endif
