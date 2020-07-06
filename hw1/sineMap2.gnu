f(x) = .85*sin(3.1415926*(.85*sin(3.1415926*x)))

g(x) = x

set xr [0:1]
set yr [0:1]

plot  f(x), g(x), "traject2.dat" u 1:2 w l
