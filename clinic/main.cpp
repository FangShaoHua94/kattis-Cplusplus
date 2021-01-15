#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	long long int n,k;
	cin>>n>>k;
	
	auto comp=[](pair<long long int,string> a,pair<long long int,string> b){
		if(a.first!=b.first){
			return a.first<b.first;
		}
		return a.second.compare(b.second)>0;
	};
	
	priority_queue<pair<long long int,string>,vector<pair<long long int,string>>,decltype(comp)> pq(comp);
	unordered_map<string,bool> mapp;
	
	for(long long int i=0;i<n;i++){
		int q;
		long long int t;
		cin>>q>>t;
		if(q==1){
			string m;
			long long int s;
			cin>>m>>s;
			mapp[m]=true;
			pq.push({s-k*t,m});
		}else if(q==2){
			while(!pq.empty()&&mapp[pq.top().second]==false){
				pq.pop();
			}
			if(pq.empty()){
				cout<<"doctor takes a break"<<"\n";
			}else{
				cout<<pq.top().second<<"\n";
				pq.pop();
			}
		}else{
			string m;
			cin>>m;
			mapp[m]=false;
		}
	}
	
	return 0;
}
