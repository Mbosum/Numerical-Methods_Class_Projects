#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double x0,v0;
const double oM = 1;
const double dt = .05;
const double tMax = 100;
const double y = 1;
const double a0 = .5;    //driving force amplitude
const double k = .75;    //driving frequency

//need:
//const y value
//a0 value
//a(t) function

double forcingFunction() {
 	double t = 0;	
	double a = a0*sin(k*t);    //sinusoidal driving force

return a;
}

double Euler(double x0, double v0, double a){
	double x1,v1;
	
	x1 = (x0 + v0*dt); //need to update this formula
        v1 = (v0 - (oM*oM*oM*oM*sin(x0)*dt));	//need to update this formula
	
return x1;	
}


double VerletX(double x0, double x1, double a){
	double x2;
        

	x2 = ((2*x1) - (x0) + (-oM*oM*dt*sin(x1)));  //need to update this formula
       
return x2;

}

double VerletV(double x0,double x1, double x2, double a){
	double v2;

	v2 =  (x2 - x0)/(2*dt); 

return v2;
}





int main() {


double x0,v0;

double t=0;

 cout<<"x0 = ";
 cin>> x0;
 cout<<"v0 = ";
 cin>> v0;

forcingFunction();
	double a{forcingFunction()};

Euler(x0,v0,a);
	double x1{Euler(x0,v0,a)};
	double v1{Euler(x1,v1,a)};
	 

VerletX(x0,x1,a);
	double x2{VerletX(x0,x1,a)};
VerletV(x0,x1,x2,a);
	double v2{VerletV(x0,x1,x2,a)};
	 

	//cout<<x2<<endl;
	//cout<<v2<<endl;

cout<<x0<<setw(12)<<v0<<endl;
cout<<x1<<setw(12)<<v1<<endl;

while (t<=tMax){
	
	x2 = ((2*x1) - (x0) + (-oM*oM*dt*sin(x1)));  //need to update this formula
	v2 =  (x2 - x0)/(2*dt);
	
	a = sin(k*t);
//	cout<<a<<endl;
	cout<<x2<<setw(12)<<v2<<endl;
	                                                                             
	x0=x1;
        x1=x2;
        
        
        t+=dt;
	}
return 0;
}
