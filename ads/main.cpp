#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define maxi 205


void border(char web[maxi][maxi],int visited[maxi][maxi],int h,int w,int y,int x){

	visited[y][x]=1;
	
	if(y+1<h&&visited[y+1][x]==0&&web[y+1][x]=='+'){
		border(web,visited,h,w,y+1,x);
	}
	
	if(y-1>=0&&visited[y-1][x]==0&&web[y-1][x]=='+'){
		border(web,visited,h,w,y-1,x);
	}
	
	if(x+1<w&&visited[y][x+1]==0&&web[y][x+1]=='+'){
		border(web,visited,h,w,y,x+1);
	}
	
	if(x-1>=0&&visited[y][x-1]==0&&web[y][x-1]=='+'){
		border(web,visited,h,w,y,x-1);
	}
	
}

bool flag;

bool checkword(char x){
	int g=(int)x;
	
	if((g>=48&&g<=57)||(g>=97&&g<=122)||(g>=65&&g<=90)){
		return true;
	}
	if(x=='?'|x=='!'||x==','||x=='.'||x==' '){
		return true;
	}
	
	return false;
}

void checkpic(char web[maxi][maxi],int visited[maxi][maxi],int h,int w,int y,int x){
	
	visited[y][x]=2;
	
	if(!checkword(web[y][x])){
		flag=true;
	}
	
	if(!flag&&y+1<h&&visited[y+1][x]==0&&web[y+1][x]!='+'){
		checkpic(web,visited,h,w,y+1,x);
	}
	
	if(!flag&&y-1>=0&&visited[y-1][x]==0&&web[y-1][x]!='+'){
		checkpic(web,visited,h,w,y-1,x);
	}
	
	if(!flag&&x+1<w&&visited[y][x+1]==0&&web[y][x+1]!='+'){
		checkpic(web,visited,h,w,y,x+1);
	}
	
	if(!flag&&x-1>=0&&visited[y][x-1]==0&&web[y][x-1]!='+'){
		checkpic(web,visited,h,w,y,x-1);
	}
	
}

void erase_border(char web[maxi][maxi],int visited[maxi][maxi],int h,int w,int y,int x){
	
	web[y][x]=' ';
	visited[y][x]=3;
	
	if(y+1<h&&visited[y+1][x]==1){
		erase_border(web,visited,h,w,y+1,x);
	}
	
	if(y-1>=0&&visited[y-1][x]==1){
		erase_border(web,visited,h,w,y-1,x);
	}
	
	if(x+1<w&&visited[y][x+1]==1){
		erase_border(web,visited,h,w,y,x+1);
	}
	
	if(x-1>=0&&visited[y][x-1]==1){
		erase_border(web,visited,h,w,y,x-1);
	}
	
}

void erase_inside(char web[maxi][maxi],int visited[maxi][maxi],int h,int w,int y,int x){
	
	web[y][x]=' ';
	visited[y][x]=3;
	
	if(y+1<h&&visited[y+1][x]!=3){
		erase_inside(web,visited,h,w,y+1,x);
	}
	
	if(y-1>=0&&visited[y-1][x]!=3){
		erase_inside(web,visited,h,w,y-1,x);
	}
	
	if(x+1<w&&visited[y][x+1]!=3){
		erase_inside(web,visited,h,w,y,x+1);
	}
	
	if(x-1>=0&&visited[y][x-1]!=3){
		erase_inside(web,visited,h,w,y,x-1);
	}
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	
	int h,w;
	cin>>h>>w;
	cin.get();
	
	char web[maxi][maxi];
	int visited[maxi][maxi];
	
	string str;
	for(int i=0;i<h;i++){
		getline(cin,str);
		for(int j=0;j<w;j++){
			web[i][j]=str[j];
			visited[i][j]=0;
		}
	}
//	cout<<"------------------------------------"<<endl;
//	
//	for(int i=0;i<h;i++){
//		for(int j=0;j<w;j++){
//			cout<<web[i][j];
//		}
//		cout<<endl;
//	}
//	cout<<"------------------------------------"<<endl;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(visited[i][j]==0&&web[i][j]=='+'){
				flag=false;
				int y=i,x=j;
				border(web,visited,h,w,y,x);//border visited==1
				checkpic(web,visited,h,w,y+1,x+1);//visited==2
				
				if(flag){//there is ban word
					erase_border(web,visited,h,w,y,x);//visited==3
					erase_inside(web,visited,h,w,y+1,x+1);//visited==3
				}
			}
		}
	}
	
//	cout<<"---------------------------------------------------------------"<<endl;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<web[i][j];
		}
		cout<<"\n";
	}
//	cout<<"------------------------------------"<<endl;
	
	
	
	return 0;
}
