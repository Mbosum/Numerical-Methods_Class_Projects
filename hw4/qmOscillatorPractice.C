using namespace std;

#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>

const double slope = 0;
const double lam = 3.00;
const double om = 1.00;
const double m = 1.00;
const double dx = .01;
const double tfin = 0.0;
const double eps = 1.0E-11;

double V(double);
double fx(double, double, double, double);


double fx(double psi, double v, double x, double E){
	return (2.0*(V(x)-E)*psi);
}

double V(double x) {
	return (.25*((x*x*x*x) + (lam*lam)) - (.5*lam*x*x));
}

