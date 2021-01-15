#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define maxi 25

bool reachable=false;

bool can_access(char map[maxi][maxi],int x,int y,int length){
	if(x>=0&&x<length&&y>=0&&y<length&&map[y][x]!='*'){
		return true;
	}
	return false;
}



void dfs(char map[maxi][maxi],bool visited2[maxi][maxi][7][7][7],int px,int py,int dice_top,int dice_right,int dice_up,int length){
//	cout<<"pos:"<<py<<" "<<px<<"----------bot:"<<7-dice_top<<endl;
	if(map[py][px]=='Q'){
		visited2[py][px][dice_top][dice_right][dice_up]=true;
	}
	map[py][px]='Q';
	if(map[py][px]=='H'&&dice_top==2){
		reachable=true;
		return;
	}

	
	if(!reachable&&can_access(map,px,py+1,length)&&!visited2[py+1][px][dice_up][dice_right][7-dice_top]){
		//down
		dfs(map,visited2,px,py+1,dice_up,dice_right,7-dice_top,length);
	}
	
	if(!reachable&&can_access(map,px,py-1,length)&&!visited2[py-1][px][7-dice_up][dice_right][dice_top]){
		//up
		dfs(map,visited2,px,py-1,7-dice_up,dice_right,dice_top,length);
	}
	
	if(!reachable&&can_access(map,px+1,py,length)&&!visited2[py][px+1][7-dice_right][dice_top][dice_up]){
		//right
		dfs(map,visited2,px+1,py,7-dice_right,dice_top,dice_up,length);
	}
	
	if(!reachable&&can_access(map,px-1,py,length)&&!visited2[py][px-1][dice_right][7-dice_top][dice_up]){
		//left
		dfs(map,visited2,px-1,py,dice_right,7-dice_top,dice_up,length);
	}

}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin>>T;
	while(T--){
//		cout<<"------------------------------------------------------------"<<endl;
		int length,px,py;
		cin>>length;

		char mapp[maxi][maxi];
		bool visited2[maxi][maxi][7][7][7]={false};
		for(int i=0;i<length;i++){
			for(int j=0;j<length;j++){
				cin>>mapp[i][j];
				if(mapp[i][j]=='S'){
					px=j;
					py=i;
				}
			}
			cin.get();
		}
		
		dfs(mapp,visited2,px,py,1,2,4,length);
		
		if(reachable){
			cout<<"Yes"<<"\n";
		}else{
			cout<<"No"<<"\n";
		}
		reachable=false;
	}

	return 0;
}
