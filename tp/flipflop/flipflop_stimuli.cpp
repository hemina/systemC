#include <systemc.h>
#include "flipflop_stimuli.h"

void STIMULI::STIM()
{
	s2 = 1;
	wait();
	s1 = 1;
	wait();
	s2 = 0;
	wait();
	wait();
	s1 = 0;
	wait();
	wait();
	s1 = 1;
	wait();
	wait();
	s1 = 0;
	s2 = 1;
	wait();
	s2 = 0;
	wait(8);
}

