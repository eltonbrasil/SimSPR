# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset

set title "Interface Prism BK7 - Cu metal layer"
set xlabel "Angle of Incidence (degrees)"
set ylabel "Intensity reflectivity"

plot "rp_1.txt" title "30 nm" with lines, "rp_2.txt" title "40 nm" with lines, "rp_3.txt" title "50 nm" with lines, "rp_4.txt" title "60 nm" with lines, "rp_5.txt" title "70 nm" with lines, "rp_6.txt" title "80 nm" with lines