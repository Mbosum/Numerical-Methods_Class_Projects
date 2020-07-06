reset
set multiplot layout 1,2 title "v(t) vs y(t) Part2 y(0) = 1.2, v(0) = .2"

set title "undamped damping (b=0)"
unset key
plot "part1a.dat" u 1:2  w p pt 7 ps .2,\

set title "damping b = .1"
unset key
plot "part2.dat" u 1:2 w p pt 7 ps .2
