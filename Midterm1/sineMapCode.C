using namespace std;
#include <stdio.h>
#include <math.h>
#include <iostream>
#include<iomanip>

//this is the right code, but need to find correct r value



double g(double  x,double r) {
	return (r*sin(3.1415926*x)); 
}

int main() {
	double x = 0;
        double r = 0;
	int n;
	int counter=0;
      
	cout << "x= ? ";
 	cin >> x;
		
        cout << setw(16) << x << setw(16) << endl;
/*
 for(n=0;n<1000;n++){
                cout << setw(16) << x << setw(16) << g(x,r) << endl;
                cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
                x = g(x,r);
        }

}
*/

for(r=.7;r<.9;r+=.0001)
	{

//iterate the map 1000 times	
	for (n=0; n<1000; n++) {
                x = g(x,r);
        }


//iterate the map 64 more times, this time printing points r x0 on separate lines
	for(n=0;n<64;n++) {
		cout << setw(16) << r << setw(16) << g(x,r) << endl;
	//	cout << setw(16) << g(x,r) << setw(16) << g(x,r) << endl;
	        
		x = g(x,r);
	//	counter = counter +1;
	}
}
//cout<<"Total iterations: "<<counter<<endl;
//total number of lines in output file is 128064
} 
