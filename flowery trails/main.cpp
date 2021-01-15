#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	
	int p,t;
	cin>>p>>t;
	
	vector<vector<pair<int,int>>> table(p,vector<pair<int,int>>());
	
	for(int i=0;i<t;i++){
		int x,y,dist;
		cin>>x>>y>>dist;
		table[x].emplace_back(y,dist);
		table[y].emplace_back(x,dist);
	}
	// start 0, end p-1
	vector<int> dist(p,INF);
	vector<vector<pair<int,int>>> path(p);//vertex,dist
	dist[0]=0;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,0});
	
	while(!pq.empty()){
		pair<int,int> x=pq.top();
		pq.pop();
		int d=x.first;
		int u=x.second;
		if(d>dist[u]) continue;
		for(auto &y:table[u]){
			int v=y.first;
			int w=y.second;
			if(dist[u]+w>dist[v]) continue;
			if(dist[u]+w==dist[v]){
				path[v].push_back({u,w});
			}else{
				path[v].clear();
				dist[v]=dist[u]+w;
				path[v].push_back({u,w});
				pq.push({dist[v],v});
			}
		}
	}
	
//	for(int i=0;i<path.size();i++){
//		cout<<i<<":";
//		for(auto y:path[i]){
//			cout<<"["<<y.first<<"-"<<y.second<<"]";
//		}
//		cout<<endl;
//	}
	
	int distance=0;
	queue<int> q;
	vector<bool> visited(p,false);
	visited[p-1]=true;
	for(auto &y:path[p-1]){
		q.push(y.first);
		distance+=y.second;
	}
	while(!q.empty()){
		int num=q.front();
		q.pop();
		if(visited[num]) continue;
		for(auto &y:path[num]){
			q.push(y.first);
			distance+=y.second;
		}
		visited[num]=true;
	}
	
	cout<<distance*2;
	return 0;
}
