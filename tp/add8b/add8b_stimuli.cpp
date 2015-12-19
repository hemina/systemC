#include <systemc.h>
#include "add8b_stimuli.h"

void STIMULI::STIM()
{
	s2 = 1;
	wait();
	s1 = 1;
	wait();
	s2 = 0;
	wait();
	s3 = 1;
	wait();
	s1 = 0;
	wait();
	s2 = 1;
	wait();
	s1 = 1;
	wait();
	s3 = 0;
	wait();
	s1 = 0;
	wait();
	s2 = 0;
	wait(8);
}

