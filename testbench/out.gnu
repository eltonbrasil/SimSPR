# Elton B. Costa, March 28, 2018
# A fairly simple GNU plot script

reset                                   # reset
set size ratio 0.5                      # set relative size of plots
set xlabel 'Incidence Angle (degrees)'  
set ylabel 'Reflectance'
set grid xtics ytics                    # grid: enable both x and y lines
set grid lt 1 lc rgb '#cccccc' lw 1     # grid: thin gray lines

set yrange [0:1]                   		# set plot range

plot 'reflectance.dat' using 1:2 with lines lt 1 lw 2 lc rgb '#999999' notitle