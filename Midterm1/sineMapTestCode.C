using namespace std;
#include <stdio.h>
#include <math.h>
#include <iostream>
#include<iomanip>



double g(double  x,double r) {
	return (r*sin(3.1415926*x)); 
}




int main() {
	double x = 0;
        double r = 0;
	int n;
       
		

	for(r=.7;r<=.9;r+=.0001){ 
		cout<<r<<endl;
		for(x=0; x<=1; x+=.001) {	
		cout<<x<<endl;
	
		}
	}
	//need to implement 3 loops:
	//1) iterate r from .7-.9 in steps of .0001
	//2)iterate x from 0 to 1 in steps of .001
	//3) loop that prints 64 pairing  of r and x in separate lines
/*

	cout << "r= ? ";
        cin >> r;
	cout << "x= ? ";
 	cin >> x;
		
        cout << setw(16) << x << setw(16) << endl;

	for (n=0; n<40; n++) {
           		
                
		cout << setw(16) << x << setw(16) << g(x,r) << endl;
		cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
	        
		x = g(x,r);

*/
	}
 
