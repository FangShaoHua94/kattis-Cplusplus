#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin>>N;
	cin.get();
	
	stack<pair<int,int>> st;
	map<int,priority_queue<int>> m;
	long long int gold=0;
//		first int is the energy, second is the gold
	while(N--){
		int a,b;
		string str;
		cin>>str;
//		cout<<"str:"<<str<<endl;
		if(str=="add"){
			cin>>a>>b;
//			cout<<"ab:"<<a<<" "<<b<<endl;
			cin.get();
			pair<int,int> pp;
			pp.first=a;
			pp.second=b;
			m[a].push(b);
		}else{
			gold=0;
			cin>>a;
//			cout<<"a:"<<a<<endl;
			cin.get();
			
			while(a){
				auto pos=m.upper_bound(a);
				if(pos==m.begin()){
					break;
				}
				--pos;
				a-=pos->first;
				priority_queue<int> &pq=pos->second;
				gold+=pq.top();
				pq.pop();
				if(pq.empty()){
					m.erase(pos);
				}
			}
			cout<<gold<<endl;
		}
	}
	return 0;
}
