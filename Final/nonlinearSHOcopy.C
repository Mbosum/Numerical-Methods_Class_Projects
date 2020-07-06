#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double x0,v0;
const double oM = 1;
const double dt = .05;
const double tMax = 100;


double EulerX(double x0,double v0){
	double x1;
	
	x1 = (x0 + (v0*dt));
        
	
return x1;	
}

double EulerV(double x0, double v0){
	double v1;

	v1 = (v0 - (oM*oM*sin(x0)*dt));
return v1;
}


double Verlet(double x0, double x1){
	double x2,v2 ;        

	x2 = ((2*x1) - (x0) + (-oM*oM*dt*sin(x1)));
       
return x2;

}



int main() {


double x0,v0;

double t=0;

 cout<<"x0 = ";
 cin>> x0;
 cout<<"v0 = ";
 cin>> v0;

EulerX(x0, v0);
	double x1{EulerX(x0,v0)};
        
	
EulerV(x0,v0);
	double v1{EulerV(x0,v0)};
	 

Verlet(x0,x1);
	double x2{Verlet(x0,x1)};
	double v2{Verlet(x0,x1)};


cout<<x0<<setw(12)<<v0<<endl;
cout<<x1<<setw(12)<<v1<<endl;

while (t<=tMax){
	
	x2 = ((2*x1) - (x0) + (-oM*oM*dt*sin(x1)));
	                                                                             
	x0=x1;
        x1=x2;
        
        v2 =  (x2 - x0)/(2*dt); 
	cout<<x2<<setw(12)<<v2<<endl;
        t+=dt;
	}
return 0;
}
