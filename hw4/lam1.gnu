reset
set multiplot layout 2,3 title "First three Energy Eigenfunctions lambda = 1" 


set title "Psi0(x)"
unset key
plot "groundStatelam1.dat" u 1:2 w l

set title "Psi1(x)"
unset key
plot "firstExcitedStatelam1.dat" u 1:2 w l

set title "Psi2(x)"
unset key
plot "secondExcitedStatelam1.dat" u 1:2 w l

unset title

set title "[Psi0(x)]^2"
plot "groundStatelam1.dat" u 1:($2*$2) w l

set title "[Psi1(x)]^2"
plot "firstExcitedStatelam1.dat" u 1:($2*$2) w l

set title "[Psi2(x)]^2"
plot "secondExcitedStatelam1.dat" u 1:($2*$2) w l
unset multiplot
