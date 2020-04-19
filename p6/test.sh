#!/bin/sh

set -e # exit on error

# Absolute path to this script, e.g. /home/user/bin/foo.sh
SCRIPT=$(readlink -f "$0")
# Absolute path this script is in, thus /home/user/bin
SCRIPTPATH=$(dirname "$SCRIPT")

# Test programs
if ! [ -x "$(command -v ghdl)" ]; then
    echo 'Error: ghdl is not installed.' >&2
    exit 1
fi
if ! [ -x "$(command -v gtkwave)" ]; then
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
read -r

# Eliminamos (de forma muy poco elegante) los elementos del gitignore
rm "$SCRIPTPATH"/*.o
rm "$SCRIPTPATH"/*.cf

rm "$SCRIPTPATH"/tb_practica1
rm "$SCRIPTPATH"/practica1
rm "$SCRIPTPATH"/tb_practica1_wave.vcd