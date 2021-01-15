#include <bits/stdc++.h>

using namespace std;

#define maxi 1010
char mapz[maxi][maxi];

int length=0;

int edge(char map[maxi][maxi],int N,int M,int y,int x){
	int count=0;
	if((y-1>=0&&map[y-1][x]=='1')){
		count++;
	}
	if((y+1<N&&map[y+1][x]=='1')){
		count++;
	}
	if((x-1>=0&&map[y][x-1]=='1')){
		count++;
	}
	if((x+1<M&&map[y][x+1]=='1')){
		count++;
	}
	return count;
}

void dfs(char map[maxi][maxi],int N,int M,int y,int x){
	map[y][x]='2';
	length+=edge(mapz,N,M,y,x);
	
	if(y+1<N&&map[y+1][x]=='0'){
		dfs(map,N,M,y+1,x);
	}
	if(y-1>=0&&map[y-1][x]=='0'){
		dfs(map,N,M,y-1,x);
	}
	if(x+1<M&&map[y][x+1]=='0'){
		dfs(map,N,M,y,x+1);
	}
	if(x-1>=0&&map[y][x-1]=='0'){
		dfs(map,N,M,y,x-1);
	}	
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0;i<=N+2;i++){
		for(int j=0;j<=M+2;j++){
			mapz[i][j]='0';
		}
	}
	
	//0-water 1-land

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>mapz[i][j];
		}
	}
	
//	for(int i=0;i<=N+1;i++){
//		for(int j=0;j<=M+1;j++){
//			cout<<mapz[i][j];
//		}
//		cout<<endl;
//	}
	

	dfs(mapz,N+2,M+2,0,0);
	cout<<length;


	return 0;
}
