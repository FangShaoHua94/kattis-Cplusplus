#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef pair<int, ii> iii;
typedef vector<iii> viii;

const int INF = 1e9; 

void check(vi distance,vi step,vi act_dist){
	cout<<"distance:";
	for(auto x:distance){
		cout<<x<<" ";
	}cout<<endl;
	cout<<"step:";
	for(auto x:step){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"actua_distance:";
	for(auto x:act_dist){
		cout<<x<<" ";
	}cout<<endl;
	cout<<endl;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;

	unordered_map<string,int> mm;
	mm["English"]=0;
	for(int i=1;i<=n;i++){
		string x;
		cin>>x;
		mm[x]=i;
	}
	n++;
	vvii AL(n,vii());
	
	for(int i=0;i<m;i++){
		string x,y;
		int w;
		cin>>x>>y>>w;
		AL[mm[x]].emplace_back(mm[y],w);
	}
	
	vi dist(n,INF);
	dist[0]=0;
	vi step(n,INF);
	step[0]=0;
	
	vi actual_dist(n,0);
	
	priority_queue<iii,viii,greater<iii>> pq;
	//step,distance,vertice
	pq.push({0,{0,0}});
	
	while(!pq.empty()){
//		check(dist,step,actual_dist);
		
		iii xx=pq.top();
		pq.pop();
		int s=xx.first;
		int d=xx.second.first;
		int u=xx.second.second;
		if(s>step[u]) continue;
		if(s==step[u]&&d>dist[u]) continue;
//		if(d>dist[u]) continue;
		for(auto yy:AL[u]){
			int v=yy.first;
			int w=yy.second;
			if(step[u]+1>step[v]) continue;
			if(step[u]+1==step[v]&&dist[u]+w>=dist[v]) continue;
			dist[v]=dist[u]+w;
			actual_dist[v]=w;
			step[v]=step[u]+1;
			pq.push({step[u]+1,{dist[v],v}});
		}
	}
	//check impossible
	for(auto x:dist){
		if(x==INF){
			cout<<"Impossible";
			return 0;
		}
	}
	
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=actual_dist[i];
	}
	
	cout<<sum<<endl;
	
	return 0;
}
