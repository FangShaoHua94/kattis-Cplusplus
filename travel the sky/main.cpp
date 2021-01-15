#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct flight{
	int depart;
	int arrival;
	int capa;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int k,n,m;
	//k- num of airport, n- num of day, m-num of flight
	cin>>k>>n>>m;
	
	
	vector<int> passenger(k,0);
	map<int,vector<flight>> flights;
	map<int,vector<pair<int,int>>> addpeople;
	

	for(int i=0;i<m;i++){
		int d;
		flight f;
		cin>>f.depart>>f.arrival>>d>>f.capa;
		f.depart--;
		f.arrival--;
		d--;
		flights[d].push_back(f);
	}
	
	int d,depart,num;
	for(int i=0;i<k*n;i++){
		cin>>depart>>d>>num;
		depart--;d--;
		addpeople[d].push_back({depart,num});
	}
	
	bool flag=true;
	
	for(int i=0;i<n;i++){
		for(auto j:addpeople[i]){
			passenger[j.first]+=j.second;
		}
		
		for(auto j:flights[i]){
			passenger[j.depart]-=j.capa;
			if(passenger[j.depart]<0){
				flag=false;
				break;
			}
		}
		
		if(!flag){
			break;
		}
		
		for(auto j:flights[i]){
			passenger[j.arrival]+=j.capa;
		}
	}
		
	cout<<(flag?"optimal":"suboptimal")<<endl;
	
	return 0;
}
