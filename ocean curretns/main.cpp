#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef pair<int, ii> iii;
typedef vector<iii> viii;

const int INF = 1e9; 


int dir[16] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int r,c;
	cin>>r>>c;
	
	vvi ocean(r,vi(c));
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char x;
			cin>>x;
			ocean[i][j]=(int)(x-'0');
		}
	}
	
	int n;
	cin>>n;
	while(n--){
		int rs,cs,rd,cd;
		cin>>rs>>cs>>rd>>cd;
		rs--;cs--;rd--;cd--;
		vvi dist(r,vi(c,INF));
		dist[rs][cs]=0;
		
		priority_queue<iii,vector<iii>,greater<iii>> pq;
		pq.push({0,{rs,cs}});
		
		while(!pq.empty()){
			iii x=pq.top();
			pq.pop();
			int d=x.first;
			int rr=x.second.first;
			int cc=x.second.second;

			if(d>dist[rr][cc]) continue;
			if(rr==rd&&cc==cd) break;
			
			for(int j=0;j<8;++j){
				int nr=rr+dir[2*j];
				int nc=cc+dir[2*j+1];
				int cost=d+(j!=ocean[rr][cc]);
				if(nr<0||nr>=r||nc<0||nc>=c||dist[nr][nc]<=cost) continue;
				dist[nr][nc]=cost;
				pq.push({cost,{nr,nc}});
			}
		}
		cout<<dist[rd][cd]<<"\n";
	}
	

	return 0;
}
