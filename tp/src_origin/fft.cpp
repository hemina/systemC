/* fichier fft.cpp */
#include <systemc.h>
#include "fft.h"

using std::cout;
using std::endl;


void papillon(  float Wr, float Wi, 
                float ar, float ai,
                float br, float bi,
                float *new_ar, float *new_ai,
                float *new_br, float *new_bi)
{
        
  *new_ar = (ar + ((br * Wr) - (bi * Wi)));
  *new_ai = (ai + ((br * Wi) + (bi * Wr)));
  *new_br = (ar - ((br * Wr) - (bi * Wi)));
  *new_bi = (ai - ((br * Wi) + (bi * Wr)));
                      
}

void FFT::COMPORTEMENT()
{
  int i;
  int index_lecture, index_ecriture;
  float sample_real[8], sample_real_modif[8];
  float sample_imag[8], sample_imag_modif[8];
  float W[4][2];
        
  W[0][0] = 1;
  W[0][1] = 0;
  W[1][0] = 0.7071067812;
  W[1][1] = -0.7071067812;     
  W[2][0] = 0;
  W[2][1] = -1;
  W[3][0] = -0.7071067812; 
  W[3][1] = -0.7071067812;         
       
  wait();
       
  while (true)
    {                  
      if (in.num_available()==16)
	{
	  cout << endl << "Lecture des 16 échantillons..." << endl;     
	  for (index_lecture  = 0; index_lecture  < 8; index_lecture ++)
	    {
	      sample_real[index_lecture] = in.read();
	      cout << "lecture partie réelle : " << int(sample_real[index_lecture]) << endl;
	      wait();
	      sample_imag[index_lecture] = in.read();
	      cout << "lecture partie imaginaire : " << int(sample_imag[index_lecture]) << endl;
	      wait();
	    }
                           
	  cout << "Calcul de la FFT..." << endl;
                
	  // Etape 1
                
	  papillon (W[0][0], W[0][1], 
		    sample_real[0], sample_imag[0], sample_real[4], sample_imag[4],
		    &sample_real_modif[0], &sample_imag_modif[0], &sample_real_modif[1], &sample_imag_modif[1]);
            
	  papillon (W[0][0], W[0][1], 
		    sample_real[2], sample_imag[2], sample_real[6], sample_imag[6],
		    &sample_real_modif[2], &sample_imag_modif[2], &sample_real_modif[3], &sample_imag_modif[3]);
                          
	  papillon (W[0][0], W[0][1], 
		    sample_real[1], sample_imag[1], sample_real[5], sample_imag[5],
		    &sample_real_modif[4], &sample_imag_modif[4], &sample_real_modif[5], &sample_imag_modif[5]);
                          
	  papillon (W[0][0], W[0][1], 
		    sample_real[3], sample_imag[3], sample_real[7], sample_imag[7],
		    &sample_real_modif[6], &sample_imag_modif[6], &sample_real_modif[7], &sample_imag_modif[7]);                         

                         
	  cout<<sample_real_modif[0]<<" "<<sample_imag_modif[0]<<" "<<sample_real_modif[1]<<" "<<sample_imag_modif[1]<<endl;

	  for (i = 0; i < 8; i++)
	    {   
	      sample_real[i] =  sample_real_modif[i];
	      sample_imag[i] =  sample_imag_modif[i];
	    }
                             
	  // Etape 2


                
	  papillon (W[0][0], W[0][1], 
		    sample_real[0], sample_imag[0], sample_real[2], sample_imag[2],
		    &sample_real_modif[0], &sample_imag_modif[0], &sample_real_modif[2], &sample_imag_modif[2]);
            
	  papillon (W[2][0], W[2][1], 
		    sample_real[1], sample_imag[1], sample_real[3], sample_imag[3],
		    &sample_real_modif[1], &sample_imag_modif[1], &sample_real_modif[3], &sample_imag_modif[3]);
                          
	  papillon (W[0][0], W[0][1], 
		    sample_real[4], sample_imag[4], sample_real[6], sample_imag[6],
		    &sample_real_modif[4], &sample_imag_modif[4], &sample_real_modif[6], &sample_imag_modif[6]);
                          
	  papillon (W[2][0], W[2][1], 
		    sample_real[5], sample_imag[5], sample_real[7], sample_imag[7],
		    &sample_real_modif[5], &sample_imag_modif[5], &sample_real_modif[7], &sample_imag_modif[7]);                         

	  for (i = 0; i < 8; i++)
	    {   
	      sample_real[i] =  sample_real_modif[i];
	      sample_imag[i] =  sample_imag_modif[i];
	    }
                             
	  // Etape 3
                
	  papillon (W[0][0], W[0][1], 
		    sample_real[0], sample_imag[0], sample_real[4], sample_imag[4],
		    &sample_real_modif[0], &sample_imag_modif[0], &sample_real_modif[4], &sample_imag_modif[4]);
            
	  papillon (W[1][0], W[1][1], 
		    sample_real[1], sample_imag[1], sample_real[5], sample_imag[5],
		    &sample_real_modif[1], &sample_imag_modif[1], &sample_real_modif[5], &sample_imag_modif[5]);
                          
	  papillon (W[2][0], W[2][1], 
		    sample_real[2], sample_imag[2], sample_real[6], sample_imag[6],
		    &sample_real_modif[2], &sample_imag_modif[2], &sample_real_modif[6], &sample_imag_modif[6]);
                          
	  papillon (W[3][0], W[3][1], 
		    sample_real[3], sample_imag[3], sample_real[7], sample_imag[7],
		    &sample_real_modif[3], &sample_imag_modif[3], &sample_real_modif[7], &sample_imag_modif[7]);                         

	  for (i = 0; i < 8; i++)
	    {   
	      sample_real[i] =  sample_real_modif[i];
	      sample_imag[i] =  sample_imag_modif[i];
	    }    
                             
	  cout << "Ecriture des valeurs de la transformee..." << endl;
	  for (index_ecriture = 0; index_ecriture < 8; index_ecriture++)
	    {
	      cout << "Ecriture partie réelle : " << int(sample_real[index_ecriture]) << endl;  
	      out.write(sample_real[index_ecriture]);
	      wait();
	      cout << "Ecriture partie imaginaire : " << int(sample_imag[index_ecriture]) << endl;  
	      out.write(sample_imag[index_ecriture]);
	      wait();
	    }

	  cout << "Traitement terminé..." << endl;
	}
      wait();
    }
}
