# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset

set title "Interface Prism BK7 - Single layer Kretschmann configuration"
set xlabel "Angle of Incidence (degrees)"
set ylabel "Intensity"

plot "rp.txt" title "Gold" with lines, "rp_cu.txt" title "Copper" with lines, "rp_ag.txt" title "Silver" with lines