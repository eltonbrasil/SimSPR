# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset

set xlabel "Angle of Incidence (degrees)"
set ylabel "Reflectance"

plot "reflectance.txt" with lines
