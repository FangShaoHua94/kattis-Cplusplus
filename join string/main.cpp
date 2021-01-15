#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	cin.get();
	list<string> arr[n];
	for(int i=0;i<n;++i){
		string x;
		cin>>x;
		arr[i].push_back(x);
	}
	int a=0,b;--n;
	while(n--){
		cin>>a>>b;--a;--b;
		arr[b].splice(arr[a].end(),arr[b]);
		//a last element point to b
	}
	for(auto &s:arr[a]){
		cout<<s;
	}cout<<endl;
	
	return 0;
}
