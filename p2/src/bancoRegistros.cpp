#include "bancoRegistros.h"

void bancoRegistros::gestion(){

	sc_uint<5> r1, r2, r3; // puedes usar estas variables para los registros que se leen y escriben

	if (reset.read()) {
		for (int i = 0; i < 32; ++i) REGS[i] = i;	// solo para simular, así tenemos valores variados
		r1 = r2 = 0; 
		A = B = 0;
	}
	else {
		//aquí debes poner el código que escribe en un registro (si se escribe)
		
		// Escribimos en el registro
		if(escrReg.read()){
			REGS[regEscr.read()] = datoEscr.read();
		}

		reg1.write(A);
		reg2.write(B);

		// A y B son los registros que hay justo antes de la ALU
		A = REGS[regLect1.read()];
		B = REGS[regLect2.read()];
	}	
}