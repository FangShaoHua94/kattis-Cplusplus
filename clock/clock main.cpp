#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	clock_t begin=clock();
	
	
	int counter=0;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			for(int k=0;k<1000;k++){
				counter++;
			}
		}
	}
	
	cout<<counter<<" "<<(double)((clock()-begin)/CLOCKS_PER_SEC);
	return 0;
}
