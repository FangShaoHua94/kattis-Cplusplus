#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	set<string> section[26];
	map<string,string> mapp;
	int maxlen=-1;
	
	string str;	
	while(getline(cin,str)){
		
		if(str.length()==0){
			
			for(int i=0;i<26;i++){
				for(auto xx:section[i]){
					for(int j=0;j<(maxlen-xx.length());j++){
						cout<<" ";
					}
					cout<<mapp[xx]<<endl;
				}
				section[i].clear();
			}
			mapp.clear();
			cout<<endl;
			maxlen=-1;
			
		}else{		
			int len=str.length();
			char last=str[len-1];
			int sect=(int)last-'a';
			
			if(len>maxlen){
				maxlen=len;
			}
			
			string copy=str;
			reverse(copy.begin(),copy.end());
			
			mapp[copy]=str;
			section[sect].insert(copy);
		}
	}
	
	for(int i=0;i<26;i++){
		for(auto xx:section[i]){
			for(int j=0;j<(maxlen-xx.length());j++){
				cout<<" ";
			}
			cout<<mapp[xx]<<endl;
		}
	}
	
	return 0;
}

//			cout<<"max length:";
//			for(auto xx:maxlen){
//				cout<<xx<<" ";
//			}cout<<endl;
//			
//			for(int i=0;i<26;i++){
//				cout<<"section "<<i<<":";
//				for(auto xxx:section[i]){
//					cout<<xxx<<" ";
//				}
//				cout<<endl;
//			}
