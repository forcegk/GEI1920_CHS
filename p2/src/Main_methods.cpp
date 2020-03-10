#include "systemc.h"

#include "productor.h"
#include "consumidor.h"
#include "ALU.h"
#include "bancoRegistros.h"


class top : public sc_module
{
public:
	sc_in < bool > clk, rst;

productor *datosEntrada;
consumidor *salidaResultados;
ALU *instALU;
bancoRegistros *instBancoRegistros;

sc_signal<sc_int<32>> datoEscr, regA, regB, res, regRes;
sc_signal<bool> escrReg, zero;
sc_signal<sc_uint<5>>	regLect1, regLect2, regEscr;
sc_signal<sc_uint<3>> aluOp;


	SC_CTOR(top){
	
		int i;

		datosEntrada = new productor("datosEntrada", "doc/practicaCA_in.txt");
		salidaResultados = new consumidor("salidaResultados", "doc/practicaCA_out.txt");

		instALU = new ALU("ALU");
		instBancoRegistros = new bancoRegistros("bancoRegistros");

		datosEntrada->escrReg(escrReg);
		datosEntrada->datoEscr(datoEscr);
		datosEntrada->regLect1(regLect1);
		datosEntrada->regLect2(regLect2);
		datosEntrada->regEscr(regEscr);
		datosEntrada->aluOp(aluOp);
		datosEntrada->clock( clk );
		datosEntrada->rst( rst );

		instBancoRegistros->	escrReg(escrReg);
		instBancoRegistros->	datoEscr(datoEscr);
		instBancoRegistros->	regLect1(regLect1);
		instBancoRegistros->	regLect2(regLect2);
		instBancoRegistros->	regEscr(regEscr);
		instBancoRegistros->	reg1(regA);
		instBancoRegistros->	reg2(regB);
		instBancoRegistros->	reset( rst );
		instBancoRegistros->	clock( clk );

		instALU->	aluA(regA);
		instALU->	aluB(regB);
		instALU->	aluOp(aluOp);
		instALU->	zero(zero);
		instALU->	aluRes(res);
		instALU->	salidaALU(regRes);
		instALU->	reset(rst);
		instALU->	clock(clk);

		salidaResultados->zero(zero);
		salidaResultados->res( res );
		salidaResultados->regRes(regRes);	
		salidaResultados->clock( clk );
		salidaResultados->rst( rst );


	}

};

int sc_main(int nargs, char* vargs[]){

	sc_clock clk ("clk", 1, SC_NS);
	sc_signal <bool> rst;

	top principal("top");
	principal.clk( clk );
	principal.rst( rst );


	rst.write(true);
	sc_start(2, SC_NS);				

	rst.write(false);
	sc_start();

	return 0;

}
