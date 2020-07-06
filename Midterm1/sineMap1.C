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
        double r = .8;
	int n;
       

	//need to implement 3 loops:
	//1) iterate r from .7-.9 in steps of .0001
	//2)iterate the map from x to g(x,r) 1000 times
	//3) loop that prints 64 pairing  of r and x in separate lines

	/*	
	cout << "r= ? ";
        cin >> r;
	*/
	int counter1,counter2=0;

	
	cout << "Choose an Xo value in range from (0<x<1) ";
 	cin >> x;
		
        cout << setw(16) <<"Xo: "<<  x << setw(16) << endl;
	cout<<endl; 
/*	
	for(r=.7;r<.9;r+=.0001){
	
	
	}

*/


// think this should be a loop from n=0 to 1000 (thousand iterations of the mapping)
/*
	for (n=0; n<1000; n++) {
           		
                
		cout << setw(16) << x << setw(16) << g(x,r) << endl;
		cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
	        
		x = g(x,r);
		
		}
*/
/*			
		for(n=1000;n<1064;n++){
		 	cout << setw(16) << x << setw(16) << g(x,r) << endl;
		 	cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
		
		        x = g(x,r);
*/		for(n=0;n<64;n++) {
		
                        cout << setw(16) << x << setw(16) << g(x,r) << endl;
                        cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
                
                        x = g(x,r);
			counter1+=1;	
		}	
 cout<<"total iterations: "<< counter1<<endl;
} 

