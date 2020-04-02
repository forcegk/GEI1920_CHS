#include "mcd.h"

void mcd::FSM() {

	sc_int<16> tmp;
	int miraA, miraB;

	// // DEBUG
	// miraA = A.read();
	// miraB = B.read();
	// cout << "A: " << miraA << "  B: " << miraB << endl;

	listo.write(false);

	if (reset.read()) {
		estado = ini;
		A.write(0);
		B.write(0);
	}
	else {
		switch (estado) {
		case ini:
			if(valIn.read()){
				estado = restar;
				A.write(entA.read().to_int());
				B.write(entB.read().to_int());
			}
			//Si no es true, nos quedamos en el estado inicial
			break;

		case restar:
			// decisión de signo
			estado = signo ? aMenor : aMayor;

			// En cualquier caso de los anteriores, si es cero, vamos a fin
			if(cero){
				estado = fin;
			}

			break;

		case aMayor:
			estado = restar;
			A.write(resta);
			// b permanece el mismo
			break;

		case aMenor:
			estado = restar;
			tmp_swap_var = A.read();
			A.write(B.read());
			B.write(tmp_swap_var);

			break;

		case fin:
			if(!valIn.read()){
				estado = ini;
			}

			resultado.write(A.read().to_uint());
			listo.write(true);
			
			break;

		default:
			cerr << "Error, estado inexisente: " << estado << endl;

		};
	}
}


void mcd::calcular() {	// no tocar

	resta = A.read() - B.read();
	signo = resta.bit(15);
	cero = (resta == 0);
}
