#include <systemc.h>
#include "nand.h"

void NAND::COMPORTEMENT()
{
	S = !(A&&B);
}

