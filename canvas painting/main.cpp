#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int T,N,s;
	cin>>T;
	
	while(T--){
		cin>>N;
		long long int sum=0;
		priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
		for(int i=0;i<N;i++){
			long long int num;
			cin>>num;
			pq.push(num);
		}
		while(pq.size()!=1){
			long long int a=pq.top();
			pq.pop();
			long long int b=pq.top();
			pq.pop();
			sum+=a+b;
			pq.push(a+b);
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
