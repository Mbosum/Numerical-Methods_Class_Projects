#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

//filler matrix dimension
const int m = 5;

void LUdecomposition(double a[m][m], double l[m][m], double u[m][m],double multLU[m][m], int n) {
   int i,j,k;
     
   
  for (i = 0; i < n; i++) {
//fill diagonal elements in L matrix with 1s 	
	l[i][ i] = 1;
     } 
      for (j = 0; j < n; j++)
      {
            for (i = 0; i < n; i++)
            {
                  if (i >= j)
                  {
                        u[j][i] = a[j][i];
                        for(k = 0; k < j; k++){
                             u[j][ i] = u[j][ i] -  u[k][ i] * l[j][ k];
                 	}
		}
                  if (i > j)
                  {
                        l[i][j] = a[i][ j];
                        for (k = 0; k < j; k++) {
                             l[i][j] = l[i][ j] - u[k][j] * l[i][ k];
			}
                   l[i][ j] = l[i] [j] / u[j][ j];
                  }
            }
      }


//compute product of L and U matrices to prove that given A is returned
double sum;

for (int i=0; i<n; i++){

        for(int j=0;j<n;j++) {

                sum =0;
                for (int k =0; k<n; k++){

                sum =  sum + l[i][k] * u[k][j];

                }

                multLU[i][j]=sum;

        }
}

}


void ForwardSub(double l[m][m], double b[m], double y[m], int n) {

//The function destroys b and returns y in its place.

int i,j,k;

for (i = 0; i < n; i++) {	
	for (j=0; j<i;j++) {
		b[i] = b[i]-(l[i][j]*y[j]);
	}
	y[i] = b[i];
}
}

void BackSub (double u[m][m], double y[m], double x[m],int n) {

//The function destroys y and returns x in its place.

int i,j,k;

//x[m] = y[m]/u[m][m];

for (i = n-1; i >= 0; i--){
	x[i]=y[i];	

        for (j=i+1; j<=n ;j++) {
        	x[i] = x[i] - u[i][j]*x[j];      
        }

	x[i] =x[i]/u[i][i];
        
}
}


void InvertMat(double l[m][m], double u[m][m], double z[m][m], int n) {

int i,j,k;


//Ax = b
//A(A^-1)x=x
//A(A^-1)=I
//(LU)(A^-1) = I


//Solve for (L*U)Xn = En
//	Need to figure out how to do this automatically for a user defined matrix, so the program knows how many dimensions to solve for

//Forward Sub Ly = I
double I[m][m] = {0};

   for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                I[i][i] = 1;
        }
   }


for (i = 0; i < n; i++) {
        for (j=0; j<n;j++) {
		for (k=0; k<j; k++) {

                I[i][j] = I[i][j]-(l[i][k]*z[i][k]);
        }
        z[i][j] = I[i][j];
}
}



}



void Determinant( double l[m][m], double u[m][m], int n) {

//write a function that takes an n×n matrix A as input and returns its determinant.   It should use LU decomposition

int i,j,k;
double detA=1;
double detL=1;
double detU=1;

for (i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(i==j)
			detL*=l[i][i];
			cout<< "detL is: "<<detL<<endl;

			detU*=u[i][i];	
			cout<< "detU is: "<<detU<<endl;
		}
}	

cout<<detL<<endl;
cout<<detU<<endl;
detA=detL*detU;


}

int main() {
   double a[m][m], l[m][m], u[m][m],multLU[m][m],z[m][m], x[m], y[m],b[m];
   double detA;
   int n,i,j,k;

      

   cout << "Enter dimension of square matrix : "<<endl;
   cin >> n;

   cout<<"Enter the desired A  matrix values: "<<endl;


   for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)

//Input user input through i,j components of A matrix   

   cin >> a[i][j];
   cout << "\n"<<endl;

  
//Calling LU decomp function defined above
   LUdecomposition(a,l,u,multLU, n);
   
   cout << "L Matrix is:"<<endl;

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {

//output L matrix components for user defined A matrix from called LU decomp function
         cout<<l[i][j]<<" ";
      }
      cout << endl;
   }

   cout<<"\n"<<endl;

   cout << "U Matrix is:"<<endl;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
//output U matrix components for user defined A matrix from called LU decomp function

         cout<<u[i][j]<<" ";
      }
      cout << endl;
   }

	cout<<"\n"<<endl;
	
	cout<<"L and U multiplied together yields back A:"<<endl;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<multLU[i][j]<<" ";
		}
		cout << endl;
	}


	cout<<"\n"<<endl;

	cout << "Enter b vector values: " <<endl;

        for (int i=0; i<n; i++){
                cin >> b[i];
        }

        for(int j=0; j<n; j++)
        {

                cout<<"b["<<j<<"] = "<<b[j]<<"\n";
        }
	
	cout<<"\n"<<endl;

        ForwardSub(l,b,y,n );
	cout << "Forward Sub to solve: Ly = b for y is: "<<endl;

		for (i=0;i<n;i++){
			cout<<y[i]<<endl;
		}
	
	cout<<"\n"<<endl;

	BackSub(u,y,x,n);
	cout << "Backwards Sub to solve Ux=y for x is: "<<endl;

		for(i=0;i<n;i++){
			cout<<x[i]<<endl;
	}	

	cout<<"\n"<<endl;

	InvertMat(l,u, z, n );
	
	cout<<"y[i][j] is: "<<endl;

		for(i=0; i<n; i++){
			for(j=0;j<n;j++) {
			cout<< z[i][j]<< " ";
			}
		cout<<endl;
		}

	cout<<"\n"<<endl;
	
	Determinant(l,u,n);
	
		cout<<"Determinant of A is:"<<endl;	
		cout<<detA<<endl;

return 0;
}

