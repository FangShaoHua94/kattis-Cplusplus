#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int N,t;
	cin>>N>>t;
	vector<int> v(N);
	for(auto &i:v){
		cin>>i;
	}
	long long int sum=0;
	int curr_index=0;
	unordered_set<int> s;
	switch(t){
		case 1:
			cout<<7<<endl;
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
			sort(v.begin(),v.begin()+3);
			cout<<v[1]<<endl;
			break;
		case 4:
			for(auto x:v){
				sum+=x;
			}
			cout<<sum<<endl;
			break;
		case 5:
			for(auto x:v){
				if(x%2==0){
					sum+=x;
				}
			}
			cout<<sum<<endl;
			break;
		case 6:
			for(auto i:v){
				i%=26;
				cout<<(char)(i+'a');
			}
			break;
		case 7:
			s.insert(curr_index);
			while(true){
				if(curr_index>=N){
					cout<<"Out"<<endl;
					break;
				}else if(curr_index==N){
					cout<<"Done"<<endl;
					break;
				}else if(s.find(curr_index)!=s.end()){
					cout<<"Cyclic"<<endl;
				}else{
					curr_index=v[curr_index];
					s.insert(curr_index);
				}
			}	
			break;
	}
	return 0;
}
