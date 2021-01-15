#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define maxx 1005

	char mapz[maxx][maxx];
	int fire[maxx][maxx];
	int dist[maxx][maxx];

const int INF=1e9;


queue<iii> check(queue<iii> qq){
	queue<iii> xx;
	cout<<"queue: ";
	while(!qq.empty()){
		xx.push(qq.front());
		cout<<"["<<qq.front().first<<","<<qq.front().second.first<<","<<qq.front().second.second<<" ";
		qq.pop();
	}
	cout<<"]"<<endl;
	cout<<endl;
	return xx;
}


int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int r,c;
	
	cin>>r>>c;

	
	queue<iii> startfire;
	int jr,jc;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			dist[i][j]=INF;
			cin>>mapz[i][j];
			if(mapz[i][j]=='F'){
				fire[i][j]=0;
				startfire.push({0,{i,j}});
			}else{
				fire[i][j]=INF;
			}
			if(mapz[i][j]=='J'){
				jr=i;
				jc=j;
				dist[i][j]=0;
			}
		}
	}
	
//	startfire=check(startfire);
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cout<<mapz[i][j]<<" ";
//		}
//		cout<<endl;
//	}cout<<endl;
	
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cout<<fire[i][j]<<" ";
//		}
//		cout<<endl;
//	}cout<<endl;
	
	
	//let fire go, mark the step 
	while(!startfire.empty()){
		iii xx=startfire.front();
		int step=xx.first;
		int rr=xx.second.first;
		int cc=xx.second.second;
		startfire.pop();
		if(step>fire[rr][cc]) continue;
//		cout<<"["<<step<<","<<rr<<","<<cc<<"]"<<endl;
		//up
		if(rr-1>=0){
			if(mapz[rr-1][cc]!='#'){
				if(fire[rr][cc]+1<fire[rr-1][cc]){
					fire[rr-1][cc]=fire[rr][cc]+1;
					startfire.push({step+1,{rr-1,cc}});
				}
			}
		}
		//down
		if(rr+1<r){
			if(mapz[rr+1][cc]!='#'){
				if(fire[rr][cc]+1<fire[rr+1][cc]){
					fire[rr+1][cc]=fire[rr][cc]+1;
					startfire.push({step+1,{rr+1,cc}});
				}
			}
		}
		//left
		if(cc-1>=0){
			if(mapz[rr][cc-1]!='#') {
				if(fire[rr][cc]+1<fire[rr][cc-1]){
					fire[rr][cc-1]=fire[rr][cc]+1;
					startfire.push({step+1,{rr,cc-1}});
				}
			}
		}
		if(cc+1<c){
			if(mapz[rr][cc+1]!='#'){
				if(fire[rr][cc]+1<fire[rr][cc+1]){
					fire[rr][cc+1]=fire[rr][cc]+1;
					startfire.push({step+1,{rr,cc+1}});
				}
			}
		}
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(fire[i][j]==INF){
				cout<<"X ";
			}else{
				cout<<fire[i][j]<<" ";
			}
		}
		cout<<endl;
	}cout<<endl;
	
	queue<iii> pq;
	pq.push({0,{jr,jc}});
	
	while(!pq.empty()){
		iii xx=pq.front();
		int step=xx.first;
		int rr=xx.second.first;
		int cc=xx.second.second;
		pq.pop();
		
		if(step>dist[rr][cc]) continue;
		
		//up
		if(rr-1>=0){
			if(mapz[rr-1][cc]!='#'&&step+1<fire[rr-1][cc]){
				if(dist[rr][cc]+1<dist[rr-1][cc]){
					dist[rr-1][cc]=dist[rr][cc]+1;
					pq.push({step+1,{rr-1,cc}});
				}
			}
		}
		//down
		if(rr+1<r){
			if(mapz[rr+1][cc]!='#'&&step+1<fire[rr+1][cc]){
				if(dist[rr][cc]+1<dist[rr+1][cc]){
					dist[rr+1][cc]=dist[rr][cc]+1;
					pq.push({step+1,{rr+1,cc}});
				}
			}
		}
		//left
		if(cc-1>=0){
			if(mapz[rr][cc-1]!='#'&&step+1<fire[rr][cc-1]) {
				if(dist[rr][cc]+1<dist[rr][cc-1]){
					dist[rr][cc-1]=dist[rr][cc]+1;
					pq.push({step+1,{rr,cc-1}});
				}
			}
		}
		if(cc+1<c){
			if(mapz[rr][cc+1]!='#'&&step+1<fire[rr][cc+1]){
				if(dist[rr][cc]+1<dist[rr][cc+1]){
					dist[rr][cc+1]=dist[rr][cc]+1;
					pq.push({step+1,{rr,cc+1}});
				}
			}
		}
		
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(dist[i][j]==INF){
				cout<<"X ";
			}else{
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	
	int mini=INF;
	
	for(int i=0;i<c;i++){
		if(dist[0][i]<mini){
			mini=dist[0][i];
		}
		if(dist[r-1][i]<mini){
			mini=dist[r-1][i];
		}
	}
	
	for(int i=0;i<r;i++){
		if(dist[i][c-1]<mini){
			mini=dist[i][c-1];
		}
		if(dist[i][0]<mini){
			mini=dist[i][0];
		}
	}
	
	if(mini==INF){
		cout<<"IMPOSSIBLE";
	}else{
		cout<<mini+1;
	}
	
	return 0;
}
