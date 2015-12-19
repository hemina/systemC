#ifndef FFT_H
#define FFT_H
#include <systemc.h>

SC_MODULE(FFT)
    {
        sc_in_clk clk;
        sc_fifo_in<float> in;     
        sc_fifo_out<float> out;             

        void COMPORTEMENT();

         SC_CTOR(FFT)
                {
                  SC_THREAD(COMPORTEMENT);
                  sensitive << clk.pos();
                }
  
    };      
#endif

