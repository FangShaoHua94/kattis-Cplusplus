#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void counting_sort(vector<int> v,int n);


int main() {
	int TC;
	long long int N,A,B,C,X,Y;
	cin>>TC;
	while(TC--){
		cin>>N>>A>>B>>C>>X>>Y;
		long long int max=C>A?C:A+1;
		vector<long long int> s(N);
		vector<long long int> R(max,0);
		
		s[0]=A; R[A]++;
		
		for(long long int i=0;i<N;i++){
			s[i]=(s[i-1]*B+A)%C;
			R[s[i]]++;
		}
		
		sort(s.begin(),s.end());//nlogn
		
		long long int V;
		for(long long int i=0;i<max;i++){
			for(long long int j=0;j<R[i];j++){
				V=(V*X+i)%C;
			}
		}
		cout<<V<<endl;	
	}
	
	return 0;
}
