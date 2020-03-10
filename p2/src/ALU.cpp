#include "ALU.h"

void ALU::registro() {

	if (reset.read()) 
		salidaALU.write(0);
	else 
		//salidaALU.write(aluRes.read());
		               // resultado
		salidaALU.write(resultado);
		
		//La alu saca 2 resultados: uno directo; y el otro pasa por el registro salida de la ALU
}

void ALU::calcular(){

	switch (aluOp.read()) {
		case 0: resultado = aluA.read() +  aluB.read(); break; // suma
		case 1: resultado = aluA.read() -  aluB.read(); break; // resta
		case 2: resultado = aluA.read() &  aluB.read(); break; // and
		case 3: resultado = aluA.read() |  aluB.read(); break; // or
		case 4: resultado = aluA.read() <  aluB.read(); break; // slt
		
		default: cerr << "Error, aluOp ilegal" << endl; sc_stop();
	};

	zero.write(resultado == 0);

	aluRes.write(resultado); // piensa que valor se emite por la salida NO registrada
}