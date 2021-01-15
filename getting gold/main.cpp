#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define maxi 50

int gold=0;

void dfs(char map[][maxi],bool draft[][maxi],int px,int py){
//	cout<<"x:"<<px<<" y:"<<py<<endl;
	if(map[px][py]=='G'){
//		cout<<"wtf"<<endl;
		gold++;
	}
	map[px][py]='o';
	if(draft[px][py]){
		return ;
	}
	if(map[px-1][py]!='#'&&map[px-1][py]!='o'){
//		cout<<"down"<<endl;
		dfs(map,draft,px-1,py);
	}
	if(map[px+1][py]!='#'&&map[px+1][py]!='o'){
//		cout<<"up"<<endl;
		dfs(map,draft,px+1,py);
	}
	if(map[px][py-1]!='#'&&map[px][py-1]!='o'){
//		cout<<"left"<<endl;
		dfs(map,draft,px,py-1);
	}
	if(map[px][py+1]!='#'&&map[px][py+1]!='o'){
//		cout<<"right"<<endl;
		dfs(map,draft,px,py+1);
	}
}

char mapq[50][50];
bool draft[50][50];


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int w,h;cin>>w>>h;
	int px,py;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>mapq[i][j];
			if(mapq[i][j]=='P'){
				px=i;
				py=j;
			}else if(mapq[i][j]=='T'){
				draft[i][j]=true;
				draft[i-1][j]=true;
				draft[i+1][j]=true;
				draft[i][j-1]=true;
				draft[i][j+1]=true;
			}
		}
	}
	
	dfs(mapq,draft,px,py);

	cout<<gold<<endl;
	
	return 0;
}
