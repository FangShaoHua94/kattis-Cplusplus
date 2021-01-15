#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


string call_as(string name);

int main() {
	
	int n;cin>>n;cin.get();
	vector<string> TA(n);
	for(int i=0;i<n;i++){
		getline(cin,TA[i]);
	}
	
	for(auto &v:TA){
		cout<<call_as(v)<<" ("<<v<<")"<<endl;
	}
	
	sort(TA.begin(),TA.end(),
	[](string a,string b)->bool
	{	
		cout<<a<<" "<<b<<endl;
		if(call_as(a)==call_as(b)){
			cout<<"yes"<<endl;
			cout<<a.compare(b)<<endl;
			return a.compare(b);
		}
		cout<<b.compare(a)<<endl;
		return b.compare(a);
	});
	
	for(auto &v:TA){
		cout<<call_as(v)<<" ("<<v<<")"<<endl;
	}
	
	//3 Lam Yun Shao Ranald 
	//Lam Yun Shaa Ranald
	//Jin Zhe 
	return 0;
}

string call_as(string name){
//	char n[]=name;
	int count=0;
	vector<char> q[4];
//	char *pch;
//	pch=strtok(n," ");
//	while(pch!=NULL){
//		q[count++]=pch;
//		pch=strtok(NULL," ");
//	}
	string r;
	for(int i=0;i<name.size();i++){
		if(name[i]==' '){
			count++;
		}else{
			q[count].push_back(name[i]);
		}
	}
	switch(count){
		case 1:
			for(char ch:q[0]){
				r+=ch;
			}
			r+=" ";
			for(char ch:q[1]){
				r+=ch;
			}
			break;
		case 2:
			for(char ch:q[1]){
				r+=ch;
			}
			r+=" ";
			for(char ch:q[2]){
				r+=ch;
			}
			break;
		case 3:
			for(char ch:q[3]){
				r+=ch;
			}
			r+=" ";
			for(char ch:q[0]){
				r+=ch;
			}
			break;
	}
	return r;
}
