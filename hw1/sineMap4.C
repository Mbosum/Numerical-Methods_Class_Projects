using namespace std;
#include <stdio.h>
#include <math.h>
#include <iostream>
#include<iomanip>

//this is the right code, but need to find correct r value



double g(double  x,double r) {
	return (r*sin(3.1415926*(r*sin(3.1415926*(r*sin(3.1415926*(r*sin(3.1415926*x)))))))); 
}

int main() {
	double x = 0;
        double r = 0;
	int n;
        cout << "r= ? ";
        cin >> r;
	cout << "x= ? ";
 	cin >> x;
		
        cout << setw(16) << x << setw(16) << endl;

	for (n=0; n<100; n++) {
           		
                
		cout << setw(16) << x << setw(16) << g(x,r) << endl;
		cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
	        
		x = g(x,r);
	}
} 
