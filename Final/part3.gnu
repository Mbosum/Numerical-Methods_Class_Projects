reset
set multiplot layout 1,2 title "v(t) vs y(t) Part3 y(0) = 1.2, v(0) = 0"

set title "0<t<50"
unset key
plot "part3a.dat" u 1:2  w p pt 7 ps .2,\

set title "100<t<150"
unset key
plot "part3b.dat" u 1:2 w p pt 7 ps .2
