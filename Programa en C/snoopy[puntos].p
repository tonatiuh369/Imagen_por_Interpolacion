#########################################
# SCRIPT para GNUPLOT, Archivo llamado "snoopy[completo 1.1][FINAL].p" para unir todas las partes de la imagen

# Para activar este postscript escribir en la terminal: gnuplot snoopy[completo 1.1][FINAL].p (despues de tener todos los archivos .dat )
##########################################

reset # poniendo en ceros los sets

set grid
set xlabel "X" # poner etiqueta al eje x
set ylabel "Y" # poner etiqueta al eje y
set title "Imagen realizada por medio de InterpolaciOn de Trazadores CUbicos" # poner titulo a la grafica

set xrange [-6.5:0] # poner rango eje x [a:b]
set yrange [0:5] # poner rango eje y [a:b]
set xtics 1 # poner graduacion eje x aumentando 1 unidad
set mxtics 10 # poner 10 pequeñas graduaciones entre cada stic
set ytics 1 # poner graduacion eje y aumentando en 1 unidad
set mytics 10 # poner 10 graduaciones entre cada stic

unset key #-0.5,0.5 # posicion del identificador gráfico
#set key box # poner el identificador en un cuadro

set style line 1 lt -1 lw 4       #Se definen los estilos de línea a utilizar
set style line 2 lt 1 pt 7 ps 1 

# DIBUJANDO LA GRAFICA
# plot archivo usando las columnas 1 y 2 con titulo y con lineas
plot "snoopy[1.1].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.2].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.3].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.4].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.5].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.6].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.7].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.8].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.9].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.0].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.1].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.2].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.3].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.4].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.5].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.6].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.7].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.8].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[2.9].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[3.0].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[3.1].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[3.2].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[3.3].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[3.4].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[3.5][FINAL].dat" index 0:0 using 1:2 title "S(x)" with lines linestyle 1, \
     "snoopy[1.1].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.2].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.3].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.4].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.5].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.6].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.7].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.8].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[1.9].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.0].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.1].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.2].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.3].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.4].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.5].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.6].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.7].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.8].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[2.9].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[3.0].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[3.1].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[3.2].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[3.3].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[3.4].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2, \
     "snoopy[3.5][FINAL].dat" index 1:1 using 1:2 title "(x,y)" with points linestyle 2
    

# CREANDO UN GRAFICO EN POSTSCRIPT
set terminal png large size 840,697 # gnuplot realiza los ajustes de la salida al tipo png antes de salir
set output "snoopy[completo 1.1][FINAL].png" # La salida al fichero.png
replot # volver a graficar

set output # Marca la salida al fichero actual
set terminal pop # pop: es equivalente a “salvar terminal” y “cargar terminal” pero sin tener acceso al sistema de ficheros
pause -1 # mantiene la grafica en pantalla hasta que se presione ‘enter’ en la terminal

reset # Regresando los sets a default

quit

# FIN DEL SCRIPT PARA GNUPLOT
