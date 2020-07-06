using  namespace std;
#include <iostream>
#include <iomanip>

const double a=1.0 ; 
const double b=4.0 ; 
const double c=2.0 ;

double f(double x) {
  return a*x*x+b*x+c;
}

double g2(double x) {
  return (a*x*x-c)/(2.0*a*x+b);
}

int main(){
  double x;
  int n;
  cout << "x = ? ";
  cin >> x;
  for(n=0;n<20;n++) {
    cout << setw(4) << n << setw(16) << x << setw(16) << f(x) << endl;
    x=g2(x);
  }
}
