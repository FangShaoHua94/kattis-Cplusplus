#include <bits/stdc++.h>

using namespace std;

const long long int INF= 1e9;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct ver{
	long long int distan;
	int step;
	int vert;
};


int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int TC;cin>>TC;
	
	auto comp=[](ver a,ver b){
		if(a.distan!=b.distan){
			return a.distan>b.distan;
		}
		if(a.step!=b.step){
			return a.step>b.step;
		}
		return a.vert>b.vert;
	};
	
	while(TC--){
		
		int V;cin>>V;
		vector<vector<pair<int,int>>> table(V+5,vector<pair<int,int>>());
		
		
		for(int i=0;i<V;i++){
			int num;cin>>num;
//			cout<<num<<endl;
			for(int j=0;j<num;j++){
				int vertex,distance;
				cin>>vertex>>distance;
//				cout<<vertex<<" "<<weight<<endl;
				table[i].emplace_back(vertex,distance);
			}
		}
		
		int Q;cin>>Q;
		
		while(Q--){
			
			int s,t,k;
			cin>>s>>t>>k;
			
			vector<vector<long long int>> dist(V+5,vector<long long int>(k+30,INF));
			dist[s][1]=0;
			priority_queue<ver,vector<ver>,decltype(comp)> pq(comp);
			
			// distance,step,vertex
			ver x={0,1,s};
			pq.push(x);
			
			while(!pq.empty()){
				ver f=pq.top();pq.pop();

				if(f.distan>dist[f.vert][f.step]){
					continue;
				}
				if(f.step>k){
					continue;
				}
				for(auto &g:table[f.vert]){//for all neighbour of f
					if(dist[f.vert][f.step]+g.second>=dist[g.first][f.step+1]){//prevent going back to visited vertex
						continue;
					}
					dist[g.first][f.step+1]=dist[f.vert][f.step]+g.second;
					ver x={dist[g.first][f.step+1],f.step+1,g.first};
					pq.push(x);
				}
			}
//			cout<<"--------------------------------"<<endl;
//			for(int i=0;i<V;i++){
//				for(int j=0;j<k+30;j++){
//					cout<<dist[i][j]<<" ";
//				}
//				cout<<endl;
//			}
			
			long long int mini=INF;
			
			for(int i=1;i<=k;i++){
				mini=mini>dist[t][i]?dist[t][i]:mini;
			}
			
			if(mini==INF){
				cout<<-1<<endl;
			}else{
				cout<<mini<<endl;
			}
		}
	}
	
	return 0;
}
