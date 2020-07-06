#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double x0,v0;
const double oM = 1;
const double dt = .05;
const double tMax = 100;
const double y = 1;       //damping factor
const double a0 = .5;    //driving force amplitude
const double k = .75;    //driving frequency



double forcingFunction() {
        double t =0;
        double a = a0*sin(k*t);    //sinusoidal driving force

return a;
}


double EulerX(double x0, double v0){
	double x1;
	
	x1 = (x0 + v0*dt);
        
	
return x1;	
}

double EulerV(double x0, double v0, double t){
	double v1;

	v1 = (v0 - (oM*oM*sin(x0) - (y*v0) + a0*sin(k*t)*dt));   
return v1;
}


double Verlet(double x0, double x1, double t, double a){
	double x2,v2 ;        

	x2 = (((2*x1) - (oM*oM*dt*dt)*(sin(x1)) + ((-1 + .5*y*dt)*x0 + a*dt*dt))/(1+ (.5*y*dt)));  
       
return x2;

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
EulerX(x0,v0);
	double x1{EulerX(x0,v0)};
EulerV(x0,v0,t);
	double v1{EulerV(x0,v0,t)};
	 

Verlet(x0,x1,t,a);
	double x2{Verlet(x0,x1,t,a)};
	double v2{Verlet(x0,x1,t,a)};


cout<<x0<<setw(12)<<v0<<endl;
cout<<x1<<setw(12)<<v1<<endl;

while (t<=tMax){
	
	a = a0*sin(k*t);
	x2 = (((2*x1) - (oM*oM*dt*dt)*(sin(x1)) + ((-1 + .5*y*dt)*x0)+ (a*dt*dt))/(1+ (.5*y*dt)));
	
	                                                                             
	x0=x1;
        x1=x2;
        
        v2 =  (x2 - x0)/(2*dt);      //verlet algorithm for v2,v3,v4... 
	cout<<x2<<setw(12)<<v2<<endl;
        t+=dt;
	}
return 0;
}
