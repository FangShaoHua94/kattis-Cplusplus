#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void counting_sort(long long int arr[],int n,int x){
    long long int sizn=1000000;
    long long int temp[sizn]={0};

    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<sizn;i++){
        while(temp[i]!=0){
            arr[index++]=i;
            temp[i]--;
        }
    }
}


int main() {
	
	ios_base::sync_with_stdio(false);
cin.tie(NULL);

	int TC,N,A,B,C,X,Y;cin>>TC;
	while(TC--){
		cin>>N>>A>>B>>C>>X>>Y;
		long long int v[N];
		v[0]=A;
		for(int i=1;i<N;i++){
			v[i]=(v[i-1]*B+A)%C;
		}
		long long int bound=A>C?A+1:C+1;
//		for(int i=0;i<N;i++){
//    		cout<<v[i]<<" ";
//		}cout<<endl;
		counting_sort(v,N,bound);
//		radixSort(v,bound);
		long long int V=0;
		for(int i=0;i<N;i++){
			V=((V)*(X)+v[i])%Y;
		}
		cout<<V<<endl;
	}
	return 0;
}
