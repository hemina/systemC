#include <systemc.h>
#include "xor_stimuli.h"

void STIMULI::STIM()
{
	wait();
	s1 = 1;
	wait();
	s2 = 1;
	wait();
	s1 = 0;
	wait();
	s2 = 0;
	wait();
	s1 = 1;
	s2 = 1;
	wait();
	s2 = 0;
	wait();
	s1 = 0;
	wait(8);
}

