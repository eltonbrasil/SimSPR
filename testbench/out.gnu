# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset

set title "Interface Prism - Gold"
set xlabel "Angle of Incidence (degrees)"
set ylabel "Intensity reflectivity"

plot [0:360] "rp.txt" with lines