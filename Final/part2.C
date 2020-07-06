#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;



const double dt = .01;
const double tMax = 50;
const double b = .1;       //damping factor


double EulerX(double y0, double v0){
	double y1;
	
	y1 = (y0 + v0*dt);
        	
return y1;	
}

double EulerV(double y0, double v0){
	double v1;

	v1 = v0 + ((-y0*y0*y0) + y0 - (b*v0)) *(dt);   // modify with damping term -bv   
return v1;
}


double Verlet(double y0, double y1, double v1) {
	double y2,v2 ;        


// y2 = (2*y1) - (y0) + ((-y1*y1*y1) + y1 - (b*v1))* (dt*dt);

	y2 =( (2*y1) + dt*dt*((-y1*y1*y1) + y1) +  ((-1 + .5*b*dt)*y0) )/(1+ (.5*b*dt));    
       
return y2;

}



int main() {


double y0,v0;

double t=0;

 cout<<"y0 = ";
 cin>> y0;
 cout<<"v0 = ";
 cin>> v0;


EulerX(y0,v0);
	double y1{EulerX(y0,v0)};
EulerV(y0,v0);
	double v1{EulerV(y0,v0)};
	 

Verlet(y0,y1,v1);
	double y2{Verlet(y0,y1,v1)};
	double v2{Verlet(y0,y1,v1)};


cout<<y0<<setw(12)<<v0<<endl;
cout<<y1<<setw(12)<<v1<<endl;

while (t<=tMax){
	
	
//	y2 = (2*y1) - (y0) + ((-y1*y1*y1) + y1 - (b*v1))* (dt*dt);
y2 =( (2*y1) + dt*dt*((-y1*y1*y1) + y1) +  ((-1 + .5*b*dt)*y0) )/(1+ (.5*b*dt));	

	                                                                             
	y0=y1;
        y1=y2;
        
        v2 =  (y2 - y0)/(2*dt);      //verlet algorithm for v2,v3,v4... 
	
	cout<< y2 << setw(12) << v2 <<endl;
        
	t+=dt;
	}
return 0;
}
