# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset

set xlabel "Angulo de Incidencia" font "palatino,14"
set ylabel "Reflectância" font "palatino,20"

set key left bottom

set style data lines

set grid back ls 80

set style line 1 lt 1 lc rgb "#A00001" lw 3 pt 2 ps 1   # red line

set style line 2 lt 1 lc rgb "#000000" lw 3 pt 4 ps 1   # black square

set style line 3 lt 1 lc rgb "#5060D0" lw 3 pt 8 ps 1   # Blue triangle

set style line 4 lt 1 lc rgb "#A00000" lw 3 pt 6 ps 1   # Red circle

plot "au_670nm_AIM.txt"  w l lt 1 lw 4 lc rgb 'red' t "Sim-SPR (Prisma/Au/Agua)" 

#plot [10:50]  "curva_ref_ouro670nm.txt"  w l lt 1 lw 4 lc rgb 'blue' t "COMSOL (Au)", "curva_ref_ouro670nm.txt" w l lt 0 lw 4 lc rgb 'red' t "Sim-SPR (Au)" 

#plot [30:70]  "curva_ref_prata670nm.txt" w l lt 1 lw 4 lc rgb 'blue' t "COMSOL (Ag)", "curva_ref_prata670nm.txt" w l lt 0 lw 4 lc rgb 'red' t "Sim-SPR (Ag)"  

#plot [10:50]   "curva_ref_cobre670nm.txt" w l lt 1 lw 4 lc rgb 'blue' t "COMSOL (Cu)", "curva_ref_cobre670nm.txt" w l lt 0 lw 4 lc rgb 'red' t "Sim-SPR (Cu)" 
