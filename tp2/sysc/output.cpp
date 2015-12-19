#include <systemc.h>
#include "output.h"

void OUTPUT::COMPORTEMENT()
{
	ofstream file("output.txt");

	float data;
  	if (file.is_open())
 	{
		while(true)
		{
			data = I.read();
			file << data << endl;
      			cout << data << '\n';
			wait();
		}
  	}

	file.close();
	wait();
}

