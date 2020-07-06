#include<iostream>
#include<math.h>
using namespace std;


//this code is from online:
//	I need to figure out the following:
//		-does it use pivoting
//		-back/front substitution
//		-how to change it for my specific purposes
//		-should I keep the user input?
//
//Status Update: It seems to be outputting the wrong L and U matrices so I'm going to try to use the crout function Engelbrecht gave us, using the user input main function in the rest of this program

const int m = 5;

void LUdecomposition(double a[m][m], double l[m][m], double u[m][m], int n) {
   int i,j,k;
//L matrix produced:
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (j < i)
         l[j][i] = 0;
         else {
            l[j][i] = a[j][i];
            for (k = 0; k < i; k++) {
               l[j][i] = l[j][i] - l[j][k] * u[k][i];
            }
         }
      }
      for (j = 0; j < n; j++) {
         if (j < i)
            u[i][j] = 0;
         else if (j == i)
            u[i][j] = 1;
         else {
            u[i][j] = a[i][j] / l[i][i];
            for (k = 0; k < i; k++) {
               u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
            }
         }
      }
   }
}


//the code is correct up until this poin
int main() {
   double a[m][m], l[m][m], u[m][m];
   int n,i,j,k;
   
   cout << "Enter dimension of square matrix : "<<endl;
   cin >> n;

   cout<<"Enter the desired A  matrix values: "<<endl;

//Not sure what the role of the following 2 for loops is
   for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
   cin >> a[i][j];

   cout << "\n"<<endl;
   
//Calling LU decomp function defined above

   LUdecomposition(a, l, u, n);
   cout << "L Matrix is:"<<endl;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         cout<<l[i][j]<<" ";
      }
      cout << endl;
   }
   cout << "U Matrix is:"<<endl;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         cout<<u[i][j]<<" ";
      }
      cout << endl;
   }
   return 0;
}
