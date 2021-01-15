#include <bits/stdc++.h>

using namespace std;

#define maxi 505
typedef long long int ll;


ll mapz[maxi][maxi];
bool visited[maxi][maxi];

ll vol=0;
void dfs(ll mapz[maxi][maxi],bool visited[maxi][maxi],int h,int w,int y,int x,int lvl){
	if(mapz[y][x]>=lvl){
		vol+=mapz[y][x];
	}else{
		vol+=lvl;
	}

	visited[y][x]=true;
	
	for(int i=y-1;i<=y+1;i++){
		for(int j=x-1;j<=x+1;j++){
			if(visited[i][j]) continue;
			dfs(mapz,visited,h,w,i,j,lvl);
		}
	}
	
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int h,w;
	cin>>h>>w;
	
	for(int i=0;i<=h+1;i++){
		for(int j=0;j<=w+1;j++){
			mapz[i][j]=1;
			visited[i][j]=true;
		}
	}
	
	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>mapz[i][j];
			if(mapz[i][j]<0){
				visited[i][j]=false;
			}
		}
	}
	
	int ii,jj;
	cin>>ii>>jj;
	//drain location

	
	//check matrix
//	for(int i=0;i<h+2;i++){
//		for(int j=0;j<w+2;j++){
//			cout<<mapz[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	ll lvl=mapz[ii][jj];
	
	dfs(mapz,visited,h+2,w+2,ii,jj,lvl);
	cout<<-1*vol;
	
	
	
	return 0;
}
