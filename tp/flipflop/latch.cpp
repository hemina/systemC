#include <systemc.h>
#include "latch.h"

void LATCH::COMPORTEMENT()
{
	if (RST)
	{
		Q = 0;
		QB = 1;
	}
	if (E)
	{
		Q = D;
		QB = !D;
	}
}

