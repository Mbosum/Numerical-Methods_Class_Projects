reset
set multiplot layout 2,3 title "First three Energy Eigenfunctions lambda = 3" 


set title "Psi0(x)"
unset key
plot "groundStatelam3.dat" u 1:2 w l

set title "Psi1(x)"
unset key
plot "firstExcitedStatelam3.dat" u 1:2 w l

set title "Psi2(x)"
unset key
plot "secondExcitedStatelam3.dat" u 1:2 w l

unset title

set title "[Psi0(x)]^2"
plot "groundStatelam3.dat" u 1:($2*$2) w l

set title "[Psi1(x)]^2"
plot "firstExcitedStatelam3.dat" u 1:($2*$2) w l

set title "[Psi2(x)]^2"
plot "secondExcitedStatelam3.dat" u 1:($2*$2) w l
unset multiplot
