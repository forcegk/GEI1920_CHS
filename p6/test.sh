#!/bin/sh

set -e # exit on error

# Test programs
if ![ -x "$(command -v ghdl)" ]; then
    echo 'Error: ghdl is not installed.' >&2
    exit 1
fi
if ![ -x "$(command -v gtkwave)" ]; then
    echo 'Error: gtkwave is not installed.' >&2
    exit 1
fi

ghdl -a practica1.vhd
ghdl -a tb_practica1.vhd

ghdl -e practica1
ghdl -e tb_practica1

ghdl -r tb_practica1 --vcd=tb_practica1_wave.vcd


gtkwave tb_practica1_wave.vcd

echo '<ENTER> para eliminar los archivos'
read

# Eliminamos (de forma muy poco elegante) los elementos del gitignore
rm *.o
rm *.cf

rm tb_practica1
rm practica1
rm tb_practica1_wave.vcd