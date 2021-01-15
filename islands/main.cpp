#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define maxi 50

void dfs(char mapz[maxi][maxi],int r,int c,int y,int x){
	
	if(y<0||y>=r||x<0||x>=c){
		return;
	}
	
	mapz[y][x]='W';
	
	if(y-1>=0&&mapz[y-1][x]!='W'){
		dfs(mapz,r,c,y-1,x);
	}
	
	if(y+1<r&&mapz[y+1][x]!='W'){
		dfs(mapz,r,c,y+1,x);
	}
	
	if(x-1>=0&&mapz[y][x-1]!='W'){
		dfs(mapz,r,c,y,x-1);
	}
	
	if(x+1<c&&mapz[y][x+1]!='W'){
		dfs(mapz,r,c,y,x+1);
	}
	
}

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int r,c;cin>>r>>c;
	
	char mapz[maxi][maxi];
	
	int x=-1,y=-1;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mapz[i][j];
			if(x==-1){
				if(mapz[i][j]=='L'){
					x=j;
					y=i;
				}
			}
		}
	}
	
	if(x==-1){
		cout<<0<<"\n";
	}else{
		int count=0;
		bool flag=true;
		
		while(flag){
			flag=false;
			dfs(mapz,r,c,y,x);
			count++;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(mapz[i][j]=='L'){
						y=i;
						x=j;
						flag=true;
					}
				}
			}
		}
		cout<<count<<"\n";
	}
	
	
	return 0;
}
