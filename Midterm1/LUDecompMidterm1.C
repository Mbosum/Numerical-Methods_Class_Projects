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

//LU Decomposition using crout's algorithm for L and U matrices
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
//Ly=b
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
//Ux=y
int i,j,k;


for (i = n-1; i >= 0; i--){
	x[i]=y[i];	

        for (j=i+1; j<=n ;j++) {
        	x[i] = x[i] - u[i][j]*x[j];      
        }

	x[i] =x[i]/u[i][i];
        
}
}


void InvertMat(double l[m][m], double u[m][m], double z[m][m], double aInv[m][m], int n) {

int i,j,k;


//Ax = b
//A(A^-1)x=x

//A(A^-1)=I
//(LU)(A^-1) = I


//Solve for (L*U)(A^-1)  = I


//Forward Sub Lz = I

//Process is same as before except since z is a matrix instead of a vector, add second index

//Populate Identity matrix of size n
double I[m][m] = {0};

   for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                I[i][i] = 1;
        }
   }

//2 D forward Sub
for (i = 0; i < n; i++) {
        for (j=0; j<n;j++) {
		for (k=0; k<j; k++) {

                I[i][j] = I[i][j]-(l[i][k]*z[i][k]);
        }
        z[i][j] = I[i][j];
}
}


//Back sub to solve for A^-1: U* (A^-1) = z
//Process is same as before except solving for A^-1 which is a matrix instead of a vector, add second index
//2D Back substitution
for(i=0;i<n;i++){
for (j = n-1; j >= 0; j--){
        aInv[i][j]= z[i][j];

        for (k=i+1; k<=n ;k++) {
                aInv[i][j] = aInv[i][j] - u[j][k]*aInv[k][i];
        }

        aInv[i][j] =aInv[i][j]/u[j][j];

}
}
}



double Determinant( double l[m][m], double u[m][m], int n) {


int i,j,k;
double detA=1;

for (i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(i==j)
			detA *= u[i][i];	

//The diagonals of L are always 0, so the determinant of A depends only on the diagonals of U	
		}
}	

return detA;
}


int main() {
   double a[m][m], l[m][m], u[m][m],multLU[m][m],z[m][m], aInv[m][m], x[m], y[m],b[m];
   int n,i,j,k;
      
//User input of A matrix      

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

//Prove L and U decomposition was done correctly
	cout<<"L and U multiplied together yields back A:"<<endl;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<multLU[i][j]<<" ";
		}
		cout << endl;
	}

//user input for b vector 

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

//call forward sub method 
        ForwardSub(l,b,y,n );
	cout << "Forward Sub to solve: Ly = b for y is: "<<endl;

		for (i=0;i<n;i++){
			cout<<y[i]<<endl;
		}
	
	cout<<"\n"<<endl;

//call backwards sub method
	BackSub(u,y,x,n);
	cout << "Backwards Sub to solve Ux=y for x is: "<<endl;

		for(i=0;i<n;i++){
			cout<<x[i]<<endl;
	}	

	cout<<"\n"<<endl;

//call invertMat method
	InvertMat(l,u, z, aInv, n);
	
	cout<< "Computing inverse matrix of A"<<endl;
	cout<<"After forward sub, solution  z[i][j] for Lz=I is: "<<endl;

//output result of Lz=I

		for(i=0; i<n; i++){
			for(j=0;j<n;j++) {
			cout<< z[i][j]<< " ";
			}
		cout<<endl;
		}
	
//output result of U(A^-1) =z

	cout<<"After Backwards sub, The Inverse of A is: "<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout<<aInv[i][j]<<" ";
			}
		cout<<endl;
		}	

	cout<<"\n"<<endl;
	
//Call determinant function

	Determinant(l,u,n);
		
		double detA{Determinant(l,u,n) };	
		cout<<"Determinant of A is:"<<endl;	
		cout<<detA<<endl;

return 0;
}

