#include <bits/stdc++.h>

using namespace std;

void noobanswer(string A,string B);

int main() { //O(N+26)
	string A,B;
	cin>>A>>B;
	int a[26]={0},b[26]={0};
	for(auto x:A){
		a[(int)(x-'a')]++;
	}
	for(auto x:B){
		b[(int)(x-'a')]++;
	}
	for(int i=0;i<26;i++){
		if(a[i]!=b[i]){
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes";
	return 0;
}

void noobanswer(string A,string B){
	bool flag2=true;
	for(auto x:A){
		bool flag=false;
		for(auto y:B){
			if(y==x){
				flag=true;
				break;
			}
		}
		if(!flag){
			flag2=false;
			break;
		}
	}
	if(flag2){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	
}
