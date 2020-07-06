using namespace std;
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>



void MatVecMult (double a[n][n],double x[n],double c[n]) {

	int i,j;
	for(i=0;i<n;i++){
		c[i] = 0.0;
		
		for(j=0;j<n;j++){

			c[i] = c[i] +a[i][j]*x[j];
		}
	}

}


void Init(double a[n][n], double b[n]){
	a[0][0] = 1.0; a[0][1] = 4.0; b[0] = 2.0;
	a[1][0] = 4.0; a[1][1]= 9.0;  b[1] = 8.0;
}

