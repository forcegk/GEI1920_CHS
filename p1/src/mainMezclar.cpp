#include "systemc.h"

#include "fifo.h"
#include "mezclar.h"
#include "consumidor.h"
#include "productor.h"




class top : public sc_module
{
	public:

	fifo_T<sc_int<16>> *Qdin1, *Qdin2, *Qout;

	productor *datosEntrada;
	consumidor *salidaResultados;
	mezclar *instMezclar; 

	SC_CTOR(top) // the module constructor
	{

		datosEntrada = new productor("datosEntrada");
		salidaResultados  = new consumidor("salidaResultados", "doc/resultados.txt");
		instMezclar = new mezclar("mezclar"); 

		Qdin1 = new fifo_T<sc_int<16>>("Qdin1", 1); 
		Qdin2 = new fifo_T<sc_int<16>>("Qdin2", 1);
		Qout = new fifo_T<sc_int<16>>("Qout", 1);

		datosEntrada->din1( *Qdin1 );
		datosEntrada->din2( *Qdin2 );

		salidaResultados->audio_in( *Qout ); 

		// Conectamos el mezclador
		instMezclar->audio_in1(*Qdin1);
		instMezclar->audio_in2(*Qdin2);
		instMezclar->audio_out(*Qout);

	}

};


int sc_main(int nargs, char* vargs[]){

	top principal("top");
	sc_start(20, SC_NS);

	return 0;
}
