# INFORME CHS P7 :: 2019-20
## Alonso Rodríguez Iglesias

### Explicación TB_filtro2.vhd
    Lo que hacemos en el testbench es leer de un fichero stimuli linea por linea
    y lo guardamos en la variable 'entrada', la cual asignamos a intro (entrada
    al filtro).
    Hacemos lo mismo con la salida, y la comparamos con la línea leida del
    fichero stimulo. En caso de detectar que el resultado no es el esperado,
    reportamos un error con severity error. 
     
    Para terminar, cuando detectamos que hemos llegao al final del fichero
    stimuli, reportamos un error con severity failure, que nos hace salir de la
    simulación (esto es un problema a la hora de scriptear el proceso ya que
    devuelve un codigo de error distinto de 0).
     
    Como anotación, las ultimas dos salidas del filtro no se miden, debido a que
    nada más llegar al final del archivo de entrada, se sale. Para poder
    comprobar los ultimos dos resultados (que viendo que todo está bien ya
    sería raro que esos no, pero no se puede dar nada por hecho), he añadido un
    'wait for 2 ns' en la línea 77 y así poder ver las dos últimas salidas, las
    cuales, en efecto, son las correctas.