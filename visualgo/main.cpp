#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


const int INF = 1e9; 

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	ll v,e;
	cin>>v>>e;
	
	vector<vii> AL(v, vii());
	while(e--){
		int x,y,w;
		cin>>x>>y>>w;
		AL[x].emplace_back(y,w);
	}
	
	int s,t;
	cin>>s>>t;
	
	vi dist(v+5,INF);
    dist[s]=0;
    
    vi ways(v,0);
    ways[s]=1;
    
    set<ii> pq;
    pq.insert({0,s});
    
    while(!pq.empty()){
        ii x=*pq.begin();
        pq.erase(x);
        int d=x.first;
        int u=x.second;
        if(d>dist[u]) continue;
        for(auto &y:AL[u]){
            int v=y.first;
            int w=y.second;
            if(dist[u]+w>dist[v]) continue;
            if(dist[u]+w==dist[v]){
//                path[v].push_back(u);
				  ways[v]+=ways[u];
            }else{
                pq.erase({dist[v],v});
                dist[v]=dist[u]+w;
                ways[v]=ways[u];
                pq.insert({dist[v],v});
            }
        }
	}   
	
	cout<<ways[t];
	
	return 0;
}
