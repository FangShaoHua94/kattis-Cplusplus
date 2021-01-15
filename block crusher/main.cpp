#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int h,w;
	cin>>h>>w;
	
	while(h!=0){
		int block[h][w];
		int id[h*w];
		int f=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				char x;
				cin>>x;
				int y=(int)(x-'0');
				block[i][j]=y;
				id[f++]=y;
			}
		}
		
//		for(int i=0;i<h;i++){
//			for(int j=0;j<w;j++){
//				cout<<block[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//
//		for(auto x:id){
//			cout<<x<<" ";
//		}cout<<endl;
		
		int shortest_ditance=INF;
		vi cb(1200,0);

		for(int i=0;i<w;i++){
			int source=i;
			// ran dirsktra
			vi dist(h*w,INF);
			dist[source]=id[source];
			
			priority_queue<ii, vector<ii>, greater<ii>> pq;
			pq.push({id[source], source});
			//distance,id
			
			vector<vi> path(h*w);
			
			while(!pq.empty()){
				pair<int,int> r=pq.top();
				pq.pop();
				int d=r.first;
				int u=r.second;
				if(d>dist[u]) continue;

				for(int j=-1;j<=1;j++){
					int k=j*w;
//					cout<<"k:"<<k<<endl;
//					cout<<"u:"<<u<<endl;
					
					int kk=u-k-1;
					int qq=u-k+1;
					
					if(u%w==0){
						kk=u-k;
					}else if((u+1)%w==0){
						qq=u-k;
					}
					
					for(int m=kk;m<=qq;m++){	
						if(m==u) continue;
						if(m<0||m>h*w)continue;
//						cout<<"id:---"<<m<<endl;
						if(dist[u]+id[m]>dist[m]) continue;
						if(dist[u]+id[m]==dist[m]){
							path[m].push_back(u);
						}else{
							path[m].clear();
							path[m].push_back(u);
							dist[m]=dist[u]+id[m];
							pq.push({dist[m],m});
						}
					}
				}
			}
			
//			for(int i=0;i<path.size();i++){
//				cout<<i<<": ";
//				for(auto y:path[i]){
//					cout<<y<<" ";
//				}
//				cout<<endl;
//			}
//			
//			cout<<"distance:";
//			for(int i=0;i<h*w;i++){
//				cout<<dist[i]<<" ";
//			}cout<<endl;
			
//			obtain the smallest distance from each source
			for(int i=0;i<w;i++){
				if(shortest_ditance>dist[h*w-i-1]){
					shortest_ditance=dist[h*w-i-1];
					int dd=h*w-i-1;
					cb.clear();
					while(dd!=source){
						cb.push_back(dd);
						if(!path[dd].empty()){
							dd=path[dd][0];
						}else{
							break;
						}
					}
					cb.push_back(source);
				}
			}
//			cout<<"shortest_ditance:"<<shortest_ditance<<endl;
		}
		
//		cout<<"shortest path:";
		for(auto x:cb){
//			cout<<x<<" ";
			id[x]=-1;
		}
//		cout<<endl;
		
		for(int i=0;i<h*w;i++){
			if(id[i]!=-1){
				cout<<id[i];
			}else{
				cout<<" ";
			}
			if((i+1)%w==0){
				cout<<"\n";
			}
		}
		cout<<"\n";
		
		cin>>h>>w;
		if(h==0){
			break;
		}
	}
	
	return 0;
}
