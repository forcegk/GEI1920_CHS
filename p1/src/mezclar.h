#ifndef MEZCLAR_H
#define MEZCLAR_H

#include "systemc.h"
#include "fifo.h"


SC_MODULE (mezclar) {
public:
sc_port<read_if_T<sc_int<16>>>  audio_in1, audio_in2;
sc_port<write_if_T<sc_int<16>>>  audio_out;


  SC_CTOR(mezclar) {
	  cout<<"mezclar: "<<name()<<endl;

    SC_THREAD(procesar);
  }

private:
void procesar();
}; 

#endif