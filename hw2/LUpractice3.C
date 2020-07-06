using namespace std;
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>


const int n =5;

void 

void LU_Crout3(double Mat[n][n]){
  int j,i,k;
  for(j=0;j<n;j++){
    for(i=0;i<=j;i++){
      if(i>0){for(k=0;k<i;k++){Mat[i][j]-=Mat[i][k]*Mat[k][j];}}
    }
    if(j<n-1){
      for(i=j+1;i<n;i++){
        if(j>0){for(k=0;k<j;k++){Mat[i][j]-=Mat[i][k]*Mat[k][j];}}
        Mat[i][j]=Mat[i][j]/Mat[j][j];
      }
    }
  }
}




int main() 
{
 
}    
