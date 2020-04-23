# INFORME CHS P7 :: 2019-20
## Alonso Rodríguez Iglesias

### Explicación de Resultados y TestBench Parte 1
    Bueno primero que nada me he dado cuenta de que me olvidé de hacer este
    apartado, así que creo poder afirmar que los resultados están bien, porque
    en testbench de la parte 2 está correcto.
    Los resultados son correctos principalmente porque si visualizamos las
    ondas en GTKWave vemos que se comporta como debería:
    Tras los dos primeros ciclos, en los que tenemos reset activo, ponemos la
    señal intro a 1, y al siguiente ciclo, el registro a se actualiza con el
    valor de intro, (basicamente realiza el comportamiento de un shift register)
    y en los ciclos subsecuentes se va actualizando el valor de b con el de a, 
    el de c con el de b, y el de d, que coincide con output, y debido a que en
    esta parte de la practica no es necesario tratar output como una señal, he
    decidido omitir la declaración de la señal, pero está comentada. 
     
    El testbench, tras realizar NUM_CICLOS con intro = i (1 a NUM_CICLOS),
    hacemos un assert false y un wait. El simulador, al ver que nada hace nada,
    ya que también se para el reloj, para la simulación.

### Explicación TB_filtro2.vhd
    Lo que hacemos en el testbench es leer de un fichero stimuli linea por linea
    y lo guardamos en la variable 'entrada', la cual asignamos a intro (entrada
    al filtro).
    Hacemos lo mismo con la salida, y la comparamos con la línea leida del
    fichero stimulo. En caso de detectar que el resultado no es el esperado,
    reportamos un error con severity error. 
     
    Para terminar, cuando detectamos que hemos llegado al final del fichero
    stimuli, reportamos un error con severity failure, que nos hace salir de la
    simulación (esto es un problema a la hora de scriptear el proceso ya que
    devuelve un codigo de error distinto de 0).
     
    Destacar que las ultimas dos salidas del filtro no se miden debido a que
    nada más llegar al final del archivo de entrada, se sale.
    Para poder comprobar los ultimos dos resultados (que viendo que todo está
    bien, ya sería raro que esos no, pero no se puede dar nada por hecho), he
    añadido un 'wait for 2 ns' en la línea 77 y así poder ver las dos últimas
    salidas, las cuales, en efecto, son las correctas.