using namespace std;
#include <stdio.h>
#include <math.h>
#include <iostream>
#include<iomanip>

//this is the right code, but need to find correct r value



double g(double  x,double r) {
	return (r*sin(x)); 
}

int main() {
	double x = 0;
        double r = 0;
	int n;
	int counter=0;
        cout << "r= ? ";
        cin >> r;
	cout << "x= ? ";
 	cin >> x;
		
        cout << setw(16) << x << setw(16) << endl;

	for (n=0; n<40; n++) {
           		
                
		cout << setw(16) << x << setw(16) << g(x,r) << endl;
		cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
	        
		x = g(x,r);
		counter = counter +1;
	}
cout<<"Total iterations: "<<counter<<endl;

} 
