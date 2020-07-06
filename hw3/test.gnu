reset
set multiplot layout 1,2
set key off
#set datafile separator ","
set xlabel "m"
set ylabel "m/s"

tp = 2.0*3.14
tmod(x) = x - (floor(x/tp)*tp)
mod(x) = tmod(x)< 3.14 ? tmod(x) : tmod(x) - tp
set size square
set title "Nonlinear SHO (x0,v0) = (.2,0)"
set xr [*:*]
   
plot "new.dat" u 1:2 w p pt 7 ps .5, \
     "new.dat" u (mod($1)):2 w p pt 7 ps .5      

set size square
set title "Nonlinear Damped Driven (x0,v0) = (.2,0)"


plot "newer.dat" u 1:2 w p pt 7 ps .5, \
     "newer.dat" u  (mod($1)):2 w p pt 7 ps .5     

unset multiplot
