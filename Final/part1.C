#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


const double dt = .01;
const double tMax = 10;   


double EulerX(double y0, double v0){           //calculate x1 via Euler method since verlet method is not self starting (requires 2 initial sets of points)
	double y1;
	
	y1 = (y0 + (v0*dt));
        
	
return y1;	
}

double EulerV(double y0,double v0){    //calculate v1 via Euler method since verlet method is not self starting (requires 2 initial sets of points)
	double v1;

	v1 = v0 + (-y0*((y0*y0) - 1)) *(dt);     
return v1;
}


double Verlet(double y0, double y1){                
	double y2,v2 ;        

	y2 = (2*y1) - (y0) - (y1*((y1*y1) - 1))*(dt*dt);    //verlet algorithm for duffing equation
       
return y2;

}



int main() {


double y0,v0;

double t=0;

 cout<<"y0 = ";                //user input for initial conditions
 cin>> y0;
 cout<<"v0 = ";
 cin>> v0;

EulerX(y0, v0);
	double y1{EulerX(y0,v0)};
        
	
EulerV(y0,v0);
	double v1{EulerV(y0,v0)};
	 

Verlet(y0,y1);
	double y2{Verlet(y0,y1)};
	double v2{Verlet(y0,y1)};


cout<< y0 << setw(12) << v0 <<endl;
cout<< y1 << setw(12) << v1 <<endl;

while (t<=tMax){
	
	y2 = (2*y1) - (y0) - (y1*((y1*y1) - 1))*(dt*dt);         
	                                                                             
	y0=y1;
        y1=y2;
        
        v2 =  (y2 - y0)/(2*dt); 

	cout<<y2<<setw(12)<<v2<<endl;

        t+=dt;
	}
return 0;
}
