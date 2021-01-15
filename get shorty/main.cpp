#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n,m;
	
	while(cin>>n>>m){
		if(n==0){
			break;
		}
		
		vector<vector<pair<ld,int>>> al(n);
		
		for(int i=0;i<m;i++){
			int x,y;
			ld f;
			cin>>x>>y>>f;
			al[x].emplace_back(f,y);
			al[y].emplace_back(f,x);
		}

		
		vector<bool> visi(n,false);
		vector<ld> dist(n,0);
		
		priority_queue<pair<ld,int>> pq;
		pq.push({1,0});
		
		while(!pq.empty()){
			ld dd=pq.top().first;
			int uu=pq.top().second;
			pq.pop();
			
			if(visi[uu]){
				continue;
			}
			
			visi[uu]=true;
			dist[uu]=dd;
			
			for(auto yy:al[uu]){
				int vv=yy.second;
				ld ww=yy.first;
				pq.push({dd*ww,vv});
			}
		}

		cout << fixed;
        cout.precision(4);
		cout<<dist[n-1]<<endl;
	}
	
	
	
	return 0;
}
