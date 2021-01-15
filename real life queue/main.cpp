#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

list<queue<int>> q;
int teamid[1000];

void RLEnqueue(int ID){
	if(!q.empty()){
		for(list<queue<int>>::iterator it=q.begin();it!=q.end();++it){
			if(teamid[(*it).front()]==teamid[ID]){
				(*it).push(ID);
				return;
			}
		}
	}
	queue<int> qu;
	qu.push(ID);
	q.push_back(qu);
}

int RLDequeue(){
	if(q.empty()){
		return -999;
	}
	int an=q.front().front();
	q.front().pop();
	if(q.front().empty()){
		q.pop_front();
	}
	return an;
}

void print(){
	cout<<"[";
	for(list<queue<int>>::iterator it=q.begin();it!=q.end();++it){
		cout<<"[";
		for(int i=0;i<(*it).size();i++){
			int temp=(*it).front();
			cout<<temp<<",";
			(*it).pop();
			(*it).push(temp);
		}
		cout<<"]";
	}
	cout<<"]"<<endl;
}

int main() {
	int T;cin>>T;
	for(int i=1;i<=T;i++){
		int k;
		cin>>k;
		while(k--){
			int ID;
			cin>>ID;
			teamid[ID]=i;
		}
	}
	
	int cmd;
	while(cin>>cmd,cmd!=3){
		if(cmd==1){
			int ID;cin>>ID;
			RLEnqueue(ID);
		}else{
			cout<<RLDequeue()<<endl;
		}
		print();
	}
	return 0;
}

//2 3 101 102 103 3 201 202 203 1 101 1 201 1 102 1 202 1 103 1 203 2 2 2 2 2 1 104 2 2 3
