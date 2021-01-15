#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;



int main() {
	int N,P;
	cin>>N>>P;
	pair<int,int> q[P];
	for(int i=0;i<P;i++){
		int S,D;
		cin>>S>>D;
		q[i].first=S;
		q[i].second=D;
	}
	sort(q,q+P,
	[](pair<int,int> a,pair<int,int> b)->bool{
		return b.first>a.first;	
	});
	
	for(int i=0;i<P;i++){
		cout<<q[i].first<<"-"<<q[i].second<<endl;
	}
	stack<int> s;
	bool flag=true;
	
	for(int i=0;i<P;i++){
		if(s.empty()){
			s.push(q[i].second);
		}else{
			if(q[i].first>=s.top()){
				s.pop();
				s.push(q[i].second);
			}else{
				s.push(q[i].second);
			}
		}	
	}
	int temp;
	while(!s.empty()){
		temp=s.top();
		s.pop();
		if(!s.empty()&&s.top()<temp){
			flag=false;
			break;
		}
	}
	//12 4 1 12 6 9 5 10 2 5
	//11 4 1 9 2 10 5 3 3 7
	if(flag){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	return 0;
}
