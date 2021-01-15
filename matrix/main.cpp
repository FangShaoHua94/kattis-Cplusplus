#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void print(double a[][2],int n,int m) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool independent(double a[][2],int n,int m) {
	if(a[0][0]==0){
		double max=a[0][0];
		int index=0;
		for(int i=0; i<n; i++) {
			max=max>a[i][0]?max:a[i][0];
			index=i;
		}

		for(int j=0; j<m; j++) {
			double temp=a[0][j];
			a[0][j]=a[index][j];
			a[index][j]=temp;
		}
		print(a,n,m);
	}else{
		double pivot;
		for(int i=0; i<n; i++) {
			pivot=a[i][0];
			if(i==0) {
				for(int j=0; j<m; j++) {
					cout<<a[i][j]<<" "<<pivot<<" "<<a[i][j]/pivot<<endl;
					a[i][j]/=pivot;
				}
			} else {
				for(int j=0; j<m; j++) {
					a[i][j]-=pivot*a[0][j];
				}
			}
		}
	
		print(a,n,m);
	}
	return true;

}


int main() {

	double a[3][2]={2,3,5,4,7,2};
	int n=3;
	int m=2;
	print(a,n,m);
	independent(a,n,m);



	return 0;
}
