#include<bits/stdc++.h> 
using namespace std; 

//void print(priority_queue<int> s){
//	while(!s.empty()){
//		cout<<s.top()<<" ";
//		s.pop();
//	}
//	cout<<endl;
//}
//
//void print2(priority_queue<int,vector<int>,greater<int> > s){
//	while(!s.empty()){
//		cout<<s.top()<<" ";
//		s.pop();
//	}
//	cout<<endl;
//}

int Medians(priority_queue<int> &s,priority_queue<int,vector<int>,greater<int> > &g,int x,int med) { 
	if (s.size() > g.size()){ 
		if (x < med) { 
			g.push(s.top()); 
			s.pop(); 
			s.push(x); 
		}else{
			g.push(x); 
		}
		med = (s.top() + g.top())/2; 
	}else if (s.size()==g.size()) { 
		if (x < med) { 
			s.push(x); 
			med = s.top(); 
		}else{ 
			g.push(x); 
			med = g.top(); 
		} 
	}else{ 
		if (x > med) { 
			s.push(g.top()); 
			g.pop(); 
			g.push(x); 
		}else{
			s.push(x); 
		}
		med = (s.top() + g.top())/2; 
	} 
	return med;
} 

int main() 
{ 	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		long sum=0;
		priority_queue<int> s;
		//naturally sort by decreasing order
		priority_queue<int,vector<int>,greater<int> > g; 
		//this constructor set it as increasing order
		for(int i=0;i<n;i++){
			int num,med;
			cin>>num;
			if(i==0){
				med=num;
				s.push(num); 
			}else{
				med=Medians(s,g,num,med);
			}
			 sum+=med;
//			 cout<<"s: ";
//			 print(s);
//			 cout<<"g: ";
//			 print2(g);
//			 cout<<"med: "<<med<<endl;
		}
		cout<<sum<<endl;
	}
	return 0; 
} 

