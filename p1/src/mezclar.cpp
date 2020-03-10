#include"mezclar.h"

void mezclar::procesar(){

	int i;
	sc_uint<9> factor1, factor2;	
	sc_int<16> din1, din2;
	sc_int<26> mult1, mult2, suma;

	//... será necesario descartar algunos datos 
	for (size_t i = 0; i < 256; i++){
		// A la basura
		audio_in1->read(din1);
	}
	
	// Valores iniciales, al llegar al 9 hacemos chanchullo del desborde
	//  y volvemos a empezar
	factor1 = 0;	factor2 = 511; 

	while(true){
		// Leemos de las colas de entrada
		audio_in1->read(din1);
		audio_in2->read(din2);

		// Realizamos la suma
		suma = ((din1*factor1) + (din2*factor2)) / 512;

		// Mandamos los 16 lsb de suma a la cola de salida
		audio_out->write(suma(15,0));
		
		// Cambiamos los valores de los factores
		factor1++;
		factor2--;
	}
}
