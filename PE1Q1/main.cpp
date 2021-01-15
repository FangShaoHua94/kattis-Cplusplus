#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,t;
	cin>>N>>t;
	int v[N];

	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		v[i]=num;
	}

	long long int sum=0;
	list<char> l;
	switch (t){
		case 1:
			cout<<"7";
			break;
		case 2:
			if(v[0]>v[1]){
				cout<<"Bigger";
			}else if(v[0]==v[1]){
				cout<<"Equal";
			}else{
				cout<<"Smaller";
			}
			break;
		case 3:
			long long int k[3];
			k[0]=v[0];
			k[1]=v[1];
			k[2]=v[2];
			sort(k,k+3);
			cout<<k[1];
			break;
		case 4:
			for(int i=0;i<N;i++){
				sum+=v[i];
			}
			cout<<sum;
			break;
		case 5:
			for(int i=0;i<N;i++){
				if(v[i]%2==0){
					sum+=v[i];
				}
			}
			cout<<sum;
			break;
		case 6:
			for(int i=0;i<N;i++){
				char x;
				v[i]=v[i]%26;
				x=(char)(v[i]+'a');
				l.push_back(x);
			}
			for(auto q:l){
				cout<<q;
			}
			break;
		case 7:
			bool check[N];
			check[0]=true;
			int val=v[0];
			while(true){
				if(val>N-1){
					cout<<"Out";
					break;
				}else if(val==N-1){
					cout<<"Done";
					break;
				}
				val=v[val];
				if(check[val]){
					cout<<"Cyclic";
					break;
				}
				check[val]=true;
			}
			break;
	}
	return 0;
}
