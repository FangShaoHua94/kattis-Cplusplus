#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	vector<int> root(n,-1);
	set<int> larger[n];
	set<int> smaller[n];
	set<int> equ[n];
	
	int num=0;
	bool consis=true;
	
	for(int i=0;i<m;i++){
		int f,s;
		char ww;
		cin>>f;
		cin.get();
		cin>>ww>>s;
		
		if(!consis) continue;
		
		bool f1=false,f2=false;
		if(root[f]==-1){
			root[f]=num++;
			f1=true;
		}
		
		if(root[s]==-1){
			root[s]=num++;
			f2=true;
		}
		
		if(ww=='>'){
			
			if(!f1&&!f2){
				//check
				if(larger[root[s]].find(root[f])!=larger[root[s]].end()){
					consis=false;
					continue;
				}
			}
			
			//new relation
			larger[root[s]].insert(root[f]);
			smaller[root[f]].insert(root[s]);
			
		}else if(ww=='<'){
			if(!f1&&!f2){
				//check
				if(larger[root[f]].find(root[s])!=larger[root[f]].end()){
					consis=false;
					continue;
				}
			}
			
			//new relation
			larger[root[f]].insert(root[s]);
			smaller[root[s]].insert(root[f]);
		}else{
			//equal
			if(!f1&&!f2){
				//check
				if(root[f]==root[s]||root[s]==root[f]) continue;
				bool fff=true;
				for(auto xx:smaller[root[s]]){
					if(larger[root[f]].find(xx)!=larger[root[f]].end()){
						fff=false;
						break;
					}
				}
				if(!fff){
					consis=false;
					continue;
				}
				
				for(auto xx:larger[root[s]]){
					if(smaller[root[f]].find(xx)!=smaller[root[f]].end()){
						fff=false;
						break;
					}
				}
				if(!fff){
					consis=false;
					continue;
				}
				
				//transfer to f
				
				for(auto xx:larger[root[s]]){
					larger[root[f]].insert(xx);
				}
				for(auto xx:smaller[root[s]]){
					smaller[root[f]].insert(xx);
				}
				root[s]=root[f];
				equ[root[f]].insert(s);
				continue;
			}
			if(f1&&f2){
				root[s]=root[f];
				equ[root[f]].insert(s);
				continue;
			}
			
//			new relation
//			larger[root[f]].insert(root[s]);
//			smaller[root[s]].insert(root[f]);

			if(f1){
				root[f]=root[s];
			}else{
				root[s]=root[f];
			}
		}
	}
	
	for(int i=0;i<num;i++){
		cout<<root[i]<<" ";
	}
	cout<<endl;
	
	cout<<"larger:"<<endl;
	for(int i=0;i<n;i++){
		if(larger[i].empty()) continue;
		cout<<i<<" : ";
		for(auto xx:larger[i]){
			cout<<xx<<" ";
		}
		cout<<endl;
	}cout<<endl;
	
	cout<<"smaller:"<<endl;
	for(int i=0;i<n;i++){
		if(smaller[i].empty()) continue;
		cout<<i<<" : ";
		for(auto xx:smaller[i]){
			cout<<xx<<" ";
		}
		cout<<endl;
	}cout<<endl;
	
	cout<<"equ:"<<endl;
	for(int i=0;i<n;i++){
		if(equ[i].empty()) continue;
		cout<<i<<" : ";
		for(auto xx:equ[i]){
			cout<<xx<<" ";
		}
		cout<<endl;
	}cout<<endl;
	
	if(consis){
		cout<<"consistent";
	}else{
		cout<<"inconsistent";
	}
	
	return 0;
}
