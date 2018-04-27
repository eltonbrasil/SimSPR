# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset

set title "Curva SPR na configuração de Kretschmann" font "palatino,20" 
set xlabel "Ângulo de Incidência (graus)" font "palatino,14"
set ylabel "Reflectância" font "palatino,20"

set key left bottom

set style data lines

set grid back ls 80

set style line 2 lt 1 lc rgb "#000000" lw 1 pt 4 ps 1   # black square

set style line 3 lt 1 lc rgb "#5060D0" lw 1 pt 8 ps 1   # Blue triangle

set style line 4 lt 1 lc rgb "#A00000" lw 1 pt 6 ps 1   # Red circle

#plot [10:50]  "curva_ref_ouro670nm.txt"  title "COMSOL (Au)" with lines lc rgb 'black', "curva_ref_ouro670nm.txt"  w lp ls 2 t "Sim-SPR (Au)" 
#plot [30:70] "curva_ref_prata670nm.txt" title "COMSOL (Ag)" with lines lc rgb 'blue', "curva_ref_prata670nm.txt" w lp ls 3 t "Sim-SPR (Ag)" 
plot [10:50]  "curva_ref_cobre670nm.txt" title "COMSOL (Cu)" with lines lc rgb 'red', "curva_ref_cobre670nm.txt" w lp ls 4 t "Sim-SPR (Cu)"