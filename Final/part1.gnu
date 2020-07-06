reset
set multiplot layout 1,2 title "v(t) vs y(t) Part 1"

set title "initial conditions y(0)=1.2, v(0)= .2"
unset key
plot "part1a.dat" u 1:2  w p pt 7 ps .2,\

set title "intial conditions y(0)=1.2, v(0)= .8"
unset key
plot "part1b.dat" u 1:2 w p pt 7 ps .2
