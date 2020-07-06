reset
set multiplot layout 2,3 title "First three Energy Eigenfunctions lambda = 2.5" 


set title "Psi0(x)"
unset key
plot "groundStatelam2point5.dat" u 1:2 w l

set title "Psi1(x)"
unset key
plot "firstExcitedStatelam2point5.dat" u 1:2 w l

set title "Psi2(x)"
unset key
plot "secondExcitedStatelam2point5.dat" u 1:2 w l

unset title

set title "[Psi0(x)]^2"
plot "groundStatelam2point5.dat" u 1:($2*$2) w l

set title "[Psi1(x)]^2"
plot "firstExcitedStatelam2point5.dat" u 1:($2*$2) w l

set title "[Psi2(x)]^2"
plot "secondExcitedStatelam2point5.dat" u 1:($2*$2) w l
unset multiplot
