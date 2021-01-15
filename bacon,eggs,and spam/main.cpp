#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n;cin>>n;
	string order,name,food;
	
	
	while(n){
		map<string,set<string>> m;
		while(n--){
			cin>>name;
			getline(cin,order);
			istringstream b(order);
			
			while(!b.eof()){
				b>>food;
				m[food].insert(name);
			}
		}
		for(auto &v:m){
			cout<<v.first<<" ";
			for(auto &i:v.second){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		cin>>n;
	}
	
	return 0;
}
