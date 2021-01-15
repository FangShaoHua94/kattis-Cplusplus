#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int TC;
	cin>>TC;
	
	while(TC--){
		
		int n,m;
		cin>>n>>m;
		
		int tt[n];
		for(int i=0;i<n;i++){
			cin>>tt[i];
		}
		
		set<int> adj[n];
		set<int> adj2[n];
		
		for(int i=0;i<m;i++){
			int ii,jj;
			cin>>ii>>jj;
			ii--;jj--;
			adj[jj].insert(ii);
			adj2[ii].insert(jj);
		}
		
		queue<int> q1;
		queue<int> q2;
		
		for(int i=0;i<n;i++){
			if(adj[i].empty()){
				if(tt[i]==1){
					q1.push(i);
				}else{
					q2.push(i);
				}
			}
		}
		
		long int countt=0;
		while(!q1.empty()||!q2.empty()){
			
			while(!q1.empty()){
				int xx=q1.front();
				q1.pop();
				for(auto yy:adj2[xx]){
					adj[yy].erase(xx);
					adj2[xx].erase(yy);

					if(adj[yy].empty()){
						if(tt[yy]==1){
							q1.push(yy);
						}else{
							q2.push(yy);
						}
					}
				}
			}
			
			if(!q2.empty()){
				countt++;
			}
			
			while(!q2.empty()){
				int xx=q2.front();
				q2.pop();
				for(auto yy:adj2[xx]){
					adj[yy].erase(xx);
					adj2[xx].erase(yy);

					if(adj[yy].empty()){
						if(tt[yy]==1){
							q1.push(yy);
						}else{
							q2.push(yy);
						}
					}	
				}
			}
			
			if(!q1.empty()){
				countt++;
			}
		}
		
		cout<<countt<<"\n";
	}
	
	return 0;
}			
