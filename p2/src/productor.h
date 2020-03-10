#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include "systemc.h"
#include <stdio.h>


SC_MODULE (productor) {

	sc_out<bool>		escrReg;
	sc_out<sc_int<32>>	datoEscr;
	sc_out<sc_uint<5>>	regLect1, regLect2, regEscr;
	sc_out<sc_uint<3>>	aluOp;
	sc_in_clk			clock, rst;

SC_HAS_PROCESS(productor);

  void producir(){

	  int r1, r2, r3, dato, escr, op;
	  if(rst.read())
		  return;

	  if (contador < 20) {
		  fscanf(fichero, "%d %d %d %d %d %d", &r1, &r2, &r3, &dato, &escr, &op);
		  ++contador;
	  }else
		  r1 = r2 = r3 = dato = escr = op = 0;

	  escrReg.write(escr);
	  datoEscr.write(dato);
	  regLect1.write(r1); 
	  regLect2.write(r2); 
	  regEscr.write(r3);
	  aluOp.write(op);
  }

productor(sc_module_name name_, char *fileName) : sc_module(name_){

	cout<<"productor: " << name() << "  " << fileName << endl;
	fichero = fopen(fileName, "rt");
	if( !fichero ){
		cerr << "No se puede abrir el fichero de entrada: " << fileName << endl;
		return;
	}

	contador = 0; 

	SC_METHOD(producir);
        sensitive << clock.pos();
    
}

private:
	FILE *fichero;	
	int contador; 
}; 


#endif