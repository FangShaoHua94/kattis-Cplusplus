#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct adventurer{
	string name;
	int skill1,skill2,skill3;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	long long int N;cin>>N;cin.get();
	long long int count=0;
	string name;
	int skill1,skill2,skill3;
	bool flag=false;
	
	

	auto compare1=[](adventurer a,adventurer b){
		if(a.skill1==b.skill1){
			return a.name.compare(b.name)>0;
		}
		return a.skill1<b.skill1;	
	};
	auto compare2=[](adventurer a,adventurer b){
		if(a.skill2==b.skill2){
			return a.name.compare(b.name)>0;
		}
		return a.skill2<b.skill2;	
	};
	auto compare3=[](adventurer a,adventurer b){
		if(a.skill3==b.skill3){
			return a.name.compare(b.name)>0;
		}
		return a.skill3<b.skill3;	
	};
	auto compare4=[](adventurer a,adventurer b){
		return a.name.compare(b.name)>0;
	};
	priority_queue<adventurer,vector<adventurer>,decltype(compare1)> pq1(compare1);
	priority_queue<adventurer,vector<adventurer>,decltype(compare2)> pq2(compare2);
	priority_queue<adventurer,vector<adventurer>,decltype(compare3)> pq3(compare3);
	priority_queue<adventurer,vector<adventurer>,decltype(compare4)> pq4(compare4);
	unordered_set<string> s;

	for(int i=0;i<N;i++){
		cin>>name>>skill1>>skill2>>skill3;cin.get();
		adventurer x={name,skill1,skill2,skill3};
		pq1.push(x);
		pq2.push(x);
		pq3.push(x);
	}

	while(true){
		while(s.find(pq1.top().name)!=s.end()){
			pq1.pop();
		}
		s.insert(pq1.top().name);
		pq4.push(pq1.top());
		pq1.pop();

		
		while(s.find(pq2.top().name)!=s.end()){
			pq2.pop();
		}
		s.insert(pq2.top().name);
		pq4.push(pq2.top());
		pq2.pop();
//		print2(pq2);
		
		while(s.find(pq3.top().name)!=s.end()){
			pq3.pop();
		}
		s.insert(pq3.top().name);
		pq4.push(pq3.top());
		pq3.pop();
//		print3(pq3);
//		print4(pq4);
		if(pq4.size()==3){
			while(!pq4.empty()){
				cout<<pq4.top().name<<" ";
				pq4.pop();
			}
			cout<<endl;
			count+=3;
		}else{
			return 0;
		}
		if(N-count<3){
			return 0;
		}
	}
	return 0;
}
