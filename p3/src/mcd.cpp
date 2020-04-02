#include "mcd.h"

void mcd::FSM() {

	sc_int<16> tmp;
	int miraA, miraB;

	miraA = A.read();		// utilizad estas variables para depurar
	miraB = B.read();

	listo.write(false);

	if (reset.read()) {
		estado = ini;
		A.write(0);
		B.write(0);
	}
	else {
		switch (estado) {
		case ini:


			break;
		case restar:


			break;
		case aMayor:


			break;
		case aMenor:


			break;
		case fin:


			break;
		default:
			cerr << "Error, estado inexisente: " << estado << endl;

		};
	}
	resultado.write(A.read().to_uint());
}


void mcd::calcular() {	// no tocar

	resta = A.read() - B.read();
	signo = resta.bit(15);
	cero = (resta == 0);
}
