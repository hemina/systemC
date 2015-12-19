#include <systemc.h>
#include <stimuli.h>
#include <top.h>

int sc_main(int argc, char *argv[])
{
	STIMULI stim("stim");
	TOP mainTop("top");

	sc_clock clk("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
	stim.CLK(clk);
	mainTop.CLK(clk);

	sc_trace_file *tf = sc_create_vcd_trace_file("trace");
	tf->set_time_unit(1, SC_NS);

	//mainTop.fifo_FFT_output.trace(tf);
	
	sc_trace(tf, clk, "clk");

	mainTop.fifo_in.trace(tf);
	mainTop.fifo_out.trace(tf);

	sc_start(5000, SC_NS);

	cout << "Finished at " << sc_time_stamp << "\n";
	sc_close_vcd_trace_file(tf);

	return 0;
}

