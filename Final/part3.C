#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//double y0,v0;
const double dt = .01;
const double tMax = 100;
const double b = .1;       //damping factor
const double a0 = .1;    //driving force amplitude
const double k = 1.41;    //driving frequency



double forcingFunction() {
        double t =0;
        double a = a0*cos(k*t);    //sinusoidal driving force

return a;
}


double EulerX(double y0, double v0){
	double y1;
	
	y1 = (y0 + v0*dt);
        
	
return y1;	
}

double EulerV(double y0, double v0, double t){
	double v1;

	v1 = v1 = v0 + ((-y0*y0*y0) + y0 - (b*v0) + a0*cos(k*t))  *(dt);   
return v1;
}


double Verlet(double y0, double y1, double t, double a){
	double y2,v2 ;        

	y2 = (((2*y1) + (-y1*y1*y1 + y1)*(dt*dt) + ((-1 + .5*b*dt)*y0 + a*dt*dt))/(1+ (.5*b*dt)));  
       
return y2;

}



int main() {


double y0,v0;

double t=0;

 cout<<"y0 = ";
 cin>> y0;
 cout<<"v0 = ";
 cin>> v0;


forcingFunction();
        double a{forcingFunction()};
EulerX(y0,v0);
	double y1{EulerX(y0,v0)};
EulerV(y0,v0,t);
	double v1{EulerV(y0,v0,t)};
	 

Verlet(y0,x1,t,a);
	double y2{Verlet(y0,y1,t,a)};
	double v2{Verlet(x0,x1,t,a)};


cout<<y0<<setw(12)<<v0<<endl;
cout<<y1<<setw(12)<<v1<<endl;

while (t<=tMax){
	
	a = a0*sin(k*t);
//	y2 = (((2*x1) - (oM*oM*dt*dt)*(sin(x1)) + ((-1 + .5*b*dt)*x0)+ (a*dt*dt))/(1+ (.5*b*dt)));
y2 = (((2*y1) + (-y1*y1*y1 + y1)*(dt*dt) + ((-1 + .5*b*dt)*y0 + a*dt*dt))/(1+ (.5*b*dt)));	
	                                                                             
	y0=x1;
        y1=x2;
        
        v2 =  (y2 - y0)/(2*dt);      //verlet algorithm for v2,v3,v4... 
	cout<<x2<<setw(12)<<v2<<endl;
        t+=dt;
	}
return 0;
}
