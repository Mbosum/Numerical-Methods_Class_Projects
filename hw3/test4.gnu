set multiplot layout 1,2
set key off
set xlabel "m"
set ylabel "m/s"

set size square
set title "Nonlinear SHO (x0,v0) = (.2,2)"
plot "new3.dat" u 1:2 w p pt 7 ps .5 
      
set size square
set title "Nonlinear Damped Driven (x0,v0) = (.2,2)" 
plot "newer3.dat" u 1:2 w p pt 7 ps .5  
     

unset multiplot
