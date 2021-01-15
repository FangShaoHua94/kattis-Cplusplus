#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct cat{
	int arrindex;
	string name;
	int severity;
	bool valid;
};

	auto compareCat=[](cat a,cat b){
			if(a.severity!=b.severity){
				return a.severity<b.severity;
			}
			return a.arrindex>b.arrindex;
		};
	
	unordered_map<string,cat> m;
		
	priority_queue<cat,vector<cat>,decltype(compareCat)> pq(compareCat);


void print(priority_queue<cat,vector<cat>,decltype(compareCat)> pq){
	vector<cat> v;
	cout<<"[";
	while(!pq.empty()){
		v.push_back(pq.top());
		cout<<pq.top().name<<"("<<pq.top().severity<<")"<<"("<<pq.top().arrindex<<") ";
		pq.pop();
	}
	cout<<"]"<<endl;
	for(int i=0;i<v.size();i++){
		pq.push(v[i]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int N,arrindex=0;
	cin>>N;

	int command,severity,increase;
	string name;
	
	while(N--){
		cin>>command;
		if(command==0){
			//insert
			cin>>name>>severity;
			cat x={arrindex++,name,severity,true};
			m[name] = x;
			pq.push(x);
		}else if(command==1){
			//update
			cin>>name>>increase;
			m[name].severity+=increase;
			pq.push(m[name]);
		}else if(command==2){
			//erase this cat
			cin>>name;
			m[name].valid=false;
		}else{
			//print max
			while(!pq.empty()&&(m[pq.top().name].valid!=true||m[pq.top().name].severity!=pq.top().severity)){
				pq.pop();
			}
			if(pq.empty()){
				cout<<"The clinic is empty"<<endl;
			}else{
				cout<<pq.top().name<<endl;
			}
		}
//		print(pq);
	}
	
	return 0;
}
