#include<iostream>

using namespace std;

int main()
{

	int i,n;
        double b[i];


	cout << "Enter size of square matrix: "<<endl;
	cin >> n;
        cout << "Enter b vector values: " <<endl;
	
	for (int i=0; i<n; i++){
		cin >> b[i];
	}
	
	for(int j=0; j<n; j++)
	{
		
		cout<<"b["<<j<<"] = "<<b[j]<<"\n";
	}

return 0;
}
