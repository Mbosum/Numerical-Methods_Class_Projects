/*:
This program determines the Second Excited state energy and plots the second excited state wavefunction for the case lambda =1.0 

*/
using namespace std;

#include <iostream>
#include <iomanip>
#include <math.h>
#include<stdlib.h>

#include <fstream>
ofstream prtwave("secondExcitedStatelam1.dat");

const double slope = 0;
const double lamda = 1.0;
const double omega = 1.00;
const double m = 1.00;
const double dx = .01;
const double tfin = 0.0;
const double eps = 1.0E-11;



double V(double x) {
        
        return (.25*((x*x*x*x) + (lamda*lamda)) - (.5*lamda*x*x));     //Symmetric potential function
}

double fx(double psi, double v, double x, double E){
        
	return (2.0*(V(x)-E)*psi);         //(d^2 Psi)/(dx^2) = f(x,E), this is the time independent Schrodinger Eq
}


void plotWaveFunction(double E) {                                           //this function is responsible for plotting psi(x) and is called in the main function
	double xolder,xold,xnew,psiold, psiolder,psinew,volder,vold, vnew;
	double k1psi, k1v, k2psi, k2v;

	psiold, psiolder = 1;
	
	xold=-3.0; vold=0.0;                                       //approximate "guess" for leftmost bound of wave function solution 
	psiold = exp(-abs(xold)*sqrt(2.0*((xold*xold)/(abs(2.0 - E)))));                            //approximate wave function Psi(x)
	
	prtwave << setw(12) << xold << " " << setw(12) << psiold << " " << setw(12) << vold << endl;
	
	xnew = xold + dx;

	k1psi = vold*dx;
	k1v = fx(psiold, vold, xold, E)*dx;
	k2psi = (vold+k1v/2.0)*dx;
	k2v = fx(psiold+k1psi/2.0, vold+k1v/2.0, xold+dx/2.0,E)*dx;
	psinew=psiold+k2psi;
	vnew=vold+k2v;

	while(xnew<3.0) {                              //iterates through x= -3,3 and psi(x) and v(x) approximated by the verlet method
		xolder = xold; psiolder = psiold; volder = vold;
		xold = xnew;   psiold = psinew;   vold = vnew;

		xnew = xold + dx;
		psinew = 2.0*psiold - psiolder + fx(psiold, vold, xold, E)*dx*dx;
		vold = (psinew -psiolder)/dx/2.0;
		
		prtwave << setw(12) << xold <<  " " << setw(12) << psiold << " " << setw(12) << vold << endl;   //outputed to a file in the header next to prtwave

	}
}


double find_slope(double E) {                                               //This function is responsible for locating the slope value condition required for the energy eigenvalue 
	double xolder,xold,xnew, psiolder,psiold,psinew,volder,vold, vnew;  //at a given energy state
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

double find_value(double E){   //locates the psi(x) value at the critical slope condition
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

	double E, Ebottom, Etop,Emiddle;
	double slopeBottom, slopeTop, slopeMiddle;
	double valueBottom, valuetop, valueMiddle;
	double testBottom, testtop, testMiddle;
	int count = 0;

	Ebottom = 1.2;     //above first excited state energy eigenvalue                       
	Etop = 2.9;
	slopeBottom = find_slope(Ebottom);       //call find_slope
	valueBottom = find_value(Ebottom);      //call find_value
	
	if(slope==0){			        //Even function condition (psi prime = 0)
		testBottom = slopeBottom;
	}
	else {
		testBottom = valueBottom;
	}
	cout<< setw(12) << Ebottom << " " << setw(12) << slopeBottom << " " << setw(12) << valueBottom << endl;
	
	slopeTop = find_slope(Etop);
	valuetop = find_value(Etop);

	if (slope== 0) {	
		testtop = slopeTop;
	}
	else {
		testtop = valuetop;
	}
	cout << setw(12) << Etop << " " << setw(12) << slopeTop << " " << setw(12) << valuetop << endl;

	Emiddle = (Etop + Ebottom)/2.0;
	slopeMiddle = find_slope(Emiddle);
	valueMiddle = find_value(Emiddle);
	
	if(slope==0){
		testMiddle = slopeMiddle;
	}
	else {
		testMiddle = valueMiddle;
	}
	cout << setw(12) << Emiddle << " " << setw(12) << slopeMiddle << " " << setw(12) << valueMiddle << endl;

	while(abs(testMiddle) > eps && count < 100) {      //bisection search algorithm to determine energy eigenvalue somewhere between Ebottom and Etop
		count++;
	
		if (testMiddle*testBottom > 0) {
			Ebottom = Emiddle;
			testBottom = testMiddle;
		}
		else {
			Etop = Emiddle;
			testtop = testMiddle;
		}
		Emiddle = (Etop + Ebottom)/2.0;
		slopeMiddle = find_slope(Emiddle);
		valueMiddle = find_value(Emiddle);
		
		if(slope == 0) {
			testMiddle = slopeMiddle;
		}
		else {
			testMiddle = valueMiddle;
		}
		
		cout<< setw(12) << Emiddle << " " << setw(12) << slopeMiddle << setw(12) << valueMiddle << endl;

		
}
plotWaveFunction(Emiddle);
 
}


