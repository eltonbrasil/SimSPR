# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset

set title "Interface Prism BK7 - Single layer Kretschmann configuration"
set xlabel "Angle of Incidence (degrees)"
set ylabel "Intensity"

plot "rp.txt" title "Reflectivity" with lines, "tp.txt" title "Transmissivity" with lines