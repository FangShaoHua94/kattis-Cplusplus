#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	cin>>n;
	
	vector<pair<int,int>> vertex(n+2);
	
	for(int i=0;i<n+2;i++){
		int x,y;
		cin>>x>>y;
		vertex[i]={x,y};
	}
	
	//distance=(x1-x2)^2+(y1-y2)^2
	
	vector<vector<pair<int,int>>> table(n+2,vector<pair<int,int>>());
	
	for(int i=0;i<n+2;i++){
		for(int j=0;j<n+2;j++){
			if(i!=j){
				int a=vertex[i].first;
				int b=vertex[i].second;
				int c=vertex[j].first;
				int d=vertex[j].second;
				table[i].emplace_back(j,(a-c)*(a-c)+(b-d)*(b-d));
			}
		}
	}
	
//	for(int i=0;i<n+2;i++){
//		cout<<i<<": ";
//		for(auto x:table[i]){
//			cout<<"["<<x.first<<"-"<<x.second<<"]";
//		}
//		cout<<endl;
//	}
	// start = n, end = n+1
	vector<int> path(n+2);
	vector<int> dist(n+2,INF);
	dist[n]=0;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,n});
	
	while(!pq.empty()){
		pair<int,int> x=pq.top();
		pq.pop();
		int d=x.first;
		int u=x.second;
		if(d>dist[u]) continue;
		for(auto &y:table[u]){
			int v=y.first;
			int w=y.second;
			if(dist[u]+w>=dist[v]) continue;
			dist[v]=dist[u]+w;
			pq.push({dist[v],v});
			path[v]=u;
		}
	}
	
//	for(int i=0;i<n+2;i++){
//		cout<<dist[i]<<" ";
//	}cout<<endl;
//	
//	for(auto x:path){
//		cout<<x<<" ";
//	}
//	cout<<endl;
	bool flag=false;
	vector<bool> check(n+2);
	int x=path[n+1];
	check[n+1]=true;
	stack<int> correct_path;

	for(int i=0;i<n+2;i++){
//		cout<<"x is "<<x <<endl;
		if(check[x]==true){
			flag=true;
			break;
		}
		check[x]=true;
		if(x==n){
			break;
		}
		correct_path.push(x);
		x=path[x];
	}

	if(correct_path.size()==0||flag){
		cout<<"-";
	}else{
		while(!correct_path.empty()){
			cout<<correct_path.top()<<"\n";
			correct_path.pop();
		}
	}
	
	return 0;
}
