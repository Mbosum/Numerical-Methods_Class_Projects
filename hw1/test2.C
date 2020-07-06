/* tanh example */
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>       /* tanh, log */
#include <iostream>
#include <iomanip>


double f(double x) {
  return tanh(x);
}

double g2(double x) {
  return tanh(x)*cosh(x)*cosh(x);
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
