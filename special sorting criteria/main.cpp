#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	
	string name;
	int n=0;
	vector<string> v;
	while(n++<5){
		cin>>name;
		v.push_back(name);
	}	
	
	sort(v.begin(),v.end(),
	[](string a,string b)->bool{
		string aa=a;
		reverse(aa.begin(),aa.end());
//		cout<<aa<<" ";
		string bb=b;
		reverse(bb.begin(),bb.end());
//		cout<<bb<<endl;
		if(bb.compare(aa)>0){
			return true;
		}else{
			return false;
		}
	});
	
	for(auto &s:v){
		cout<<s<<endl;
	}
	
	return 0;
}
