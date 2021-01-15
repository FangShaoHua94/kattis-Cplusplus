#include <bits/stdc++.h>
using namespace std;

queue<int> qq(queue<int> q){
	queue<int> p;
	cout<<"queue:";
	while(!q.empty()){
		int t=q.front();
		p.push(t);
		q.pop();
		cout<<t<<" ";
	}
	cout<<endl;
	return p;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> table(n,vector<int>(n,0));
	
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		table[x][y]=1;
		table[y][x]=1;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	int count=0;
	
	bool visited[n]={false};
	queue<int> q;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			q.push(i);
			visited[i]=true;
		}
		cout<<"before: ";
		q=qq(q);
		cout<<"after"<<endl;
		bool flag=false;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(int j=0;j<n;j++){
				if(visited[j]) continue;
				if(!table[t][j]) continue;
				cout<<"["<<j<<"]"<<endl;
				q.push(j);
				flag=true;
				q=qq(q);
			}
			visited[t]=true;
		}
		cout<<endl;
		if(flag){
			count++;
		}
	}
	cout<<count<<endl;
	
	
	return 0;
}
