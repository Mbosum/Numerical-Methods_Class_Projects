using namespace std;

#include <iostream>
#include <iomanip>
#include <math.h>

#include <fstream>
ofstream prtlamE ("lam_E.dat",fstream::app);
ofstream prtwave("wave2.dat");

const double slope = 0;
const double lam = 3.00;
const double om = 1.00;
const double m = 1.00;
const double dx = .01;
const double tfin = 0.0;
const double eps = 1.0E-11;



double V(double x) {
        
        return (.25*((x*x*x*x) + (lam*lam)) - (.5*lam*x*x));     //Symmetric potential function

//	  return .25*x*x;
}
double fx(double psi, double v, double x, double E){
        
	return (2.0*(V(x)-E)*psi);         //(d^2 Psi)/(dx^2) = f(x,E), this is the time independent Schrodinger Eq
}


void plotwave(double E) {
	double xolder,xold,xnew, psiolder,psiold,psinew,volder,vold, vnew;
	double k1psi, k1v, k2psi, k2v;
	
	xold=-3.0; vold=0.0;                                       //approximate "guess" for leftmost bound of wave function solution 
	psiold = exp(-abs(xold)*sqrt(2.0*((xold*xold)/(2.0 - E))));                            //approximate wave function Psi(x)
	
	prtwave << setw(12) << xold << " " << setw(12) << psiold << " " << setw(12) << vold << endl;
	
	xnew = xold + dx;

	k1psi = vold*dx;
	k1v = fx(psiold, vold, xold, E)*dx;
	k2psi = (vold+k1v/2.0)*dx;
	k2v = fx(psiold+k1psi/2.0, vold+k1v/2.0, xold+dx/2.0,E)*dx;
	psinew=psiold+k2psi;
	vnew=vold+k2v;

	while(xnew<3.0) {
		xolder = xold; psiolder = psiold; volder = vold;
		xold = xnew;   psiold = psinew;   vold = vnew;

		xnew = xold + dx;
		psinew = 2.0*psiold - psiolder + fx(psiold, vold, xold, E)*dx*dx;
		vold = (psinew -psiolder)/dx/2.0;
		
		prtwave << setw(12) << xold <<  " " << setw(12) << psiold << " " << setw(12) << vold << endl;

	}
}


double find_slope(double E) {
	double xolder,xold,xnew, psiolder,psiold,psinew,volder,vold, vnew;
        double k1psi, k1v, k2psi, k2v;

	xold = -5.0; vold = 0.0;
	
	psiold = exp(-abs(xold)*sqrt(2.0*(xold*xold/2.0-E)));

	xnew=xold+dx;
	
	k1psi = vold*dx;
	k1v=fx(psiold, vold, xold, E)*dx;
	k2psi = (vold+k1v/2.0)*dx;
	k2v=fx(psiold+k1psi/2.0, vold+k1v/2.0, xold+dx/2.0, E)*dx;
	psinew=psiold+k2psi;
	vnew=vold+k2v;

	while (xnew < tfin) {
		xolder = xold;  psiolder = psiold; volder = vold;
		xold = xnew;    psiold = psinew;   vold = vnew;
		
		xnew = xold + dx;
		psinew = 2.0*psiold - psiolder + fx(psiold, vold, xold, E)*dx*dx;
		vold = (psinew - psiolder)/dx/2.0;
	}

	return vold;
}

double find_value(double E){
	double xolder,xold,xnew,psiolder,psiold,psinew,volder,vold,vnew;
	double k1psi,k1v,k2psi,k2v;
	xold = -5.0; vold = 0.0; 
	
        psiold = exp(-abs(xold)*sqrt(2.0*(xold*xold/2.0-E)));

        xnew=xold+dx;

        k1psi = vold*dx;
        k1v=fx(psiold,vold,xold,E)*dx;
        k2psi = (vold+k1v/2.0)*dx;
        k2v=fx(psiold+k1psi/2.0,vold+k1v/2.0,xold+dx/2.0,E)*dx;
        psinew=psiold+k2psi;
        vnew=vold+k2v;

        while (xnew < tfin) {
                xolder = xold;  psiolder = psiold; volder = vold;
                xold = xnew;    psiold = psinew;   vold = vnew;

                xnew = xold + dx;
		psinew = 2.0*psiold - psiolder + fx(psiold, vold, xold, E)*dx*dx;
                vold = (psinew - psiolder)/dx/2.0;


        }

        return psiold;
}


int main() {

	double E, Ebot, Etop,Emid;
	double slopebot, slopetop, slopemid;
	double valuebot, valuetop, valuemid;
	double testbot, testtop, testmid;
	int count = 0;

	Ebot = 1.16;
	Etop = 2.0;
	slopebot = find_slope(Ebot);
	valuebot = find_value(Ebot);
	
	if(slope==0){
		testbot = slopebot;
	}
	else {
		testbot = valuebot;
	}
	cout<< setw(12) << Ebot << " " << setw(12) << slopebot << " " << setw(12) << valuebot << endl;
	
	slopetop = find_slope(Etop);
	valuetop = find_value(Etop);

	if (slope== 0) {
		testtop = slopetop;
	}
	else {
		testtop = valuetop;
	}
	cout << setw(12) << Etop << " " << setw(12) << slopetop << " " << setw(12) << valuetop << endl;

	Emid = (Etop + Ebot)/2.0;
	slopemid = find_slope(Emid);
	valuemid = find_value(Emid);
	
	if(slope==0){
		testmid = slopemid;
	}
	else {
		testmid = valuemid;
	}
	cout << setw(12) << Emid << " " << setw(12) << slopemid << " " << setw(12) << valuemid << endl;

	while(abs(testmid) > eps && count < 100) {
		count++;
	
		if (testmid*testbot > 0) {
			Ebot = Emid;
			testbot = testmid;
		}
		else {
			Etop = Emid;
			testtop = testmid;
		}
		Emid = (Etop + Ebot)/2.0;
		slopemid = find_slope(Emid);
		valuemid = find_value(Emid);
		
		if(slope == 0) {
			testmid = slopemid;
		}
		else {
			testmid = valuemid;
		}
		
		cout<< setw(12) << Emid << " " << setw(12) << slopemid <<setw(12) << valuemid << endl;
		
		prtlamE << setw(12) << lam << " " << setw(12) << Emid << " " << setw(12) << slopemid << endl;
		
}
plotwave(Emid);
 
}


