/* fichier sink.cpp */
#include "sink.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

void SINK::COMPORTEMENT()
{  
  std::ofstream realStream("out_real.txt");
  std::ofstream imagStream("out_imag.txt");
        
  int i;
  if(!realStream||!imagStream)
    cout<<"Un des fichiers d'entree n'est pas ouvert"<<endl;
	
  wait();

  while(true)
    { 
      if (in.num_available()==16)
	{
	  cout << endl << "Lecture des 16 échantillons par le bloc SINK..." << endl;
	  for (i = 0; i < 8; i++)
	    { 
	      realStream<<in.read()<<endl;
	      wait();
	      imagStream<<in.read()<<endl;
	      wait();
	    } 
	}
      else   
	{
	  wait(); 
	} 
    }  
}
