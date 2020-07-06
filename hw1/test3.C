using namespace std;
#include <stdio.h>      
#include <math.h>       
#include <iostream>
#include <iomanip>



double f(double x,double a) {
  
  return (tanh(a*x)-x);
}

double g2(double x, double a) {
  return (x - ((tanh(a*x)-x)/(a/(cosh(a*x)*cosh(a*x))-1)));
}

int main(){
  double x = 0;
  double a = 0;
  cout << "a = ? ";
  cin >> a;
  cout << "x = ? ";
  cin >> x;
  
  for(int n=0;n<20;n++) {
        cout << setw(4) << n << setw(16) << x << setw(16) << f(x, a) << endl;
    	x=g2(x, a);
  }
}


