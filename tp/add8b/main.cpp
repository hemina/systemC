//  main.cpp 
// Testbench pour FFT avec données en flottant

#include <systemc.h>
#include "add8b.h"
#include "add8b_stimuli.h"


int sc_main(int argc, char *argv[])
{
	sc_trace_file *tf;
	
	sc_signal<bool> in1, in2, in3, out1, out2;

	ADD8B add8b1("add8b1");
	STIMULI stimuli1("stim");

	sc_clock clk("ID", 10, SC_NS, 0.5, 10, SC_NS, true);

	add8b1.A(in1);
	add8b1.B(in2);
	add8b1.CIN(in3);
	add8b1.S(out1);
	add8b1.COUT(out2);
	
	stimuli1.clk(clk);
	stimuli1.s1(in1);
	stimuli1.s2(in2);
	stimuli1.s3(in3);

	tf = sc_create_vcd_trace_file("waves");
	tf->set_time_unit(1, SC_NS);

	sc_trace(tf, clk, "clk");
	sc_trace(tf, in1, "A");
	sc_trace(tf, in2, "B");
	sc_trace(tf, in3, "Cin");
	sc_trace(tf, out1, "S");
	sc_trace(tf, out2, "Cout");

	sc_start(500, SC_NS);
	sc_close_vcd_trace_file(tf);

	return 0;
}
