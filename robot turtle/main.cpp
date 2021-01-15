#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,pair<int,int>> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<ii,ii> iiii;
typedef pair<si,ii> siii;
typedef vector<iiii> viiii;
typedef vector<siii> vsiii;
typedef pair<int,siii> isiii;
typedef vector<isiii> visiii;

const int INF=1e9;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	char mapz[8][8];
	int dist[8][8];
	bool visited[8][8];
	//dir 1-right 2-left 3-up 4-down
	int tr=7,tc=0,dir=1;
	int dr,dc;
	
	queue<isiii> pq;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>mapz[i][j];
			dist[i][j]=INF;
			visited[i][j]=false;
			if(mapz[i][j]=='D'){
				dr=i;
				dc=j;
			}
		}
	}
	
	dist[7][0]=0;
	visited[7][0]=true;
	pq.push({0,{{"",1},{7,0}}});
	
	string ans="";
	
	while(!pq.empty()){
//		pq=check(pq);
		isiii xx=pq.front();
		int step=xx.first;
		string stt=xx.second.first.first;
		int dd=xx.second.first.second;
		int rr=xx.second.second.first;
		int cc=xx.second.second.second;
		pq.pop();
		if(mapz[rr][cc]=='D'){
			ans=stt;
			break;
		}
		if(step>dist[rr][cc]+2) continue;
		
		//for all posible action
		
		//F
		//right
		if(dd==1&&cc+1<8&&(mapz[rr][cc+1]=='.'||mapz[rr][cc+1]=='D')&&!visited[rr][cc+1]){
			visited[rr][cc+1]=true;
			dist[rr][cc+1]=step+1;
			pq.push({step+1,{{stt+='F',dd},{rr,cc+1}}});
		}
		//left
		if(dd==2&&cc-1>=0&&(mapz[rr][cc-1]=='.'||mapz[rr][cc-1]=='D')&&!visited[rr][cc-1]){
			visited[rr][cc-1]=true;
			dist[rr][cc-1]=step+1;
			pq.push({step+1,{{stt+='F',dd},{rr,cc-1}}});
		}
		//up
		if(dd==3&&rr-1>=0&&(mapz[rr-1][cc]=='.'||mapz[rr-1][cc]=='D')&&!visited[rr-1][cc]){
			visited[rr-1][cc]=true;
			dist[rr-1][cc]=step+1;
			pq.push({step+1,{{stt+='F',dd},{rr-1,cc}}});
		}
		//down
		if(dd==4&&rr+1<8&&(mapz[rr+1][cc]=='.'||mapz[rr+1][cc]=='D')&&!visited[rr+1][cc]){
			visited[rr+1][cc]=true;
			dist[rr+1][cc]=step+1;
			pq.push({step+1,{{stt+='F',dd},{rr+1,cc}}});
		}
		
		//R
		if(dd==1){
			pq.push({step+1,{{stt+='R',4},{rr,cc}}});
		}
		if(dd==2){
			pq.push({step+1,{{stt+='R',3},{rr,cc}}});
		}
		if(dd==3){
			pq.push({step+1,{{stt+='R',1},{rr,cc}}});
		}
		if(dd==4){
			pq.push({step+1,{{stt+='R',2},{rr,cc}}});
		}
		
		//L
		if(dd==1){
			pq.push({step+1,{{stt+='L',3},{rr,cc}}});
		}
		if(dd==2){
			pq.push({step+1,{{stt+='L',4},{rr,cc}}});
		}
		if(dd==3){
			pq.push({step+1,{{stt+='L',2},{rr,cc}}});
		}
		if(dd==4){
			pq.push({step,{{stt+='L',1},{rr,cc}}});
		}
		
		//X
		if(dd==1&&mapz[rr][cc+1]=='I'){
			mapz[rr][cc+1]='.';
			pq.push({step+1,{{stt+='X',1},{rr,cc}}});
		}
		if(dd==2&&mapz[rr][cc-1]=='I'){
			mapz[rr][cc-1]='.';
			pq.push({step+1,{{stt+='X',2},{rr,cc}}});
		}
		if(dd==3&&mapz[rr-1][cc]=='I'){
			mapz[rr-1][cc]='.';
			pq.push({step+1,{{stt+='X',3},{rr,cc}}});
		}
		if(dd==4&&mapz[rr+1][cc+1]=='I'){
			mapz[rr+1][cc+1]='.';
			pq.push({step+1,{{stt+='X',4},{rr,cc}}});
		}
	}
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(dist[i][j]==INF){
				cout<<"X ";
			}else{
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	
	cout<<ans;
	
	return 0;
}
