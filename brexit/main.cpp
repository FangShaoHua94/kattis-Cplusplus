#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int c,p,x,l;
	cin>>c>>p>>x>>l;
	vector<unordered_set<int>> table(c+5);
	vector<int> ori_size(c+5);
	
	for(int i=0;i<p;i++){
		int a,b;
		cin>>a>>b;
		table[a].insert(b);
		table[b].insert(a);
	}
	
	for(int i=1;i<=c;i++){
		ori_size[i]=table[i].size();
	}
	
	if(x==l){
		cout<<"leave"<<endl;
		return 0;
	}
	
	queue<int> leaved;
	leaved.push(l);
	
	while(!leaved.empty()){
		int leaving=leaved.front();
		leaved.pop();
		for(auto &k:table[leaving]){
			table[k].erase(leaving);
			if(table[k].size()*2<=ori_size[k]){
				leaved.push(k);
				if(k==x){
					cout<<"leave"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"stay"<<endl;
	
	return 0;
}
