#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	long int n,K;
	cin>>n>>K;
	
	if(n<K){
		cout<<n-1;
	}else{
		if((n-1)%K==0){
			if(K==n-1){
				cout<<K;
			}else{
				cout<<K+1;
			}
		}else{
			cout<<(n-1)%K+K;
		}
	}
	
	
	return 0;
}
