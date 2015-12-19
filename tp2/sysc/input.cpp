#include <systemc.h>
#include "input.h"

void INPUT::COMPORTEMENT()
{
	ifstream file("input_samples.txt");

	float data;
  	if (file.is_open())
	{
 		while(file >> data)
 		{
			O.write(data);
      			//cout << data << '\n';
			wait();
   		}

    		file.close();
	}
}

