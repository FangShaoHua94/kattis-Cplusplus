#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef pair<ii,ii> iiii;
typedef vector<iiii> viiii;
typedef vector<viiii> vviiii;

const int INF=1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n,m,a,b,k,g;
	cin>>n>>m>>a>>b>>k>>g;
	a--;b--;
	
	vi geo(g);
	
	for(int i=0;i<g;i++){
		int gg;
		cin>>gg;
		gg--;
		geo[i]=gg;
	}
	
//	for(auto xx:geo){
//		cout<<xx<<" ";
//	}cout<<endl;
	
	vviiii adj(n,viiii());
	
	for(int i=0;i<m;i++){
		int aa,bb,l;
		cin>>aa>>bb>>l;
		aa--;bb--;
		iiii xx={{bb,l},{0,0}};
		iiii yy={{aa,l},{0,0}};
		adj[aa].emplace_back(xx);
		adj[bb].emplace_back(yy);
	}
	
	int sets=0;
	for(int i=0;i<g-1;i++){
		int s=geo[i];
		int e=geo[i+1];
		for(auto &xx:adj[s]){
			if(xx.first.first==e){
				xx.second.first=sets;
				xx.second.second=sets+xx.first.second;
			}
		}
		for(auto &xx:adj[e]){
			if(xx.first.first==s){
				xx.second.first=sets;
				xx.second.second=sets+xx.first.second;
				sets=sets+xx.first.second;
			}
		}
	}
//	
//	for(int i=0;i<n;i++){
//		cout<<i<<":";
//		for(auto yy:adj[i]){
//			cout<<"["<<yy.first.first<<","<<yy.first.second<<","<<yy.second.first<<","<<yy.second.second<<"]";
//		}
//		cout<<endl;
//	}
		
	
	vector<long int> dist(n,INF);
	dist[a]=k;
	
	priority_queue<ii,vii,greater<ii>> pq;
	pq.push({k,a});
	
	while(!pq.empty()){
		int d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		
		if(d>dist[u]) continue;
		
		for(iiii xx:adj[u]){
			int v=xx.first.first;
			int w=xx.first.second;
			int srange=xx.second.first;
			int erange=xx.second.second;
//			cout<<"dist[u]: "<<dist[u]<<endl;
			if(dist[u]+w>=dist[v]) continue;
			if(dist[u]>=srange&&dist[u]<erange){
				dist[v]=w+erange;
				pq.push({dist[v],v});
			}else{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
//			cout<<"distance:";
//			for(int i=0;i<n;i++){
//				cout<<dist[i]<<" ";
//			}cout<<endl;
		}
	}
	
//	cout<<"distance:";
//	for(int i=0;i<n;i++){
//		cout<<dist[i]<<" ";
//	}cout<<endl;
	
	cout<<dist[b]-k<<endl;
	return 0;
}



