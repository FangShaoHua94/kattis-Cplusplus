#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void print(stack<int> s){
	cout<<"stack:";
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}cout<<endl;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,k,p,pos=0,q,m;
	string v;
	cin>>n>>k;
	stack<int> s;
	s.push(pos);
	for(int i=0;i<k;i++){
		cin>>v;
//		cout<<"str:"<<v<<endl;
		if(v=="undo"){
			cin>>m;
			while(m--){
				s.pop();
			}
			pos=s.top();
		}else{//number
			string::size_type sz;
			q=stoi(v,&sz);
			q=q%n;
//			cout<<"q:"<<q<<endl;
			pos=(pos+q);
			while(pos<0){
				pos+=n;
			}
			pos=pos%n;
			s.push(pos);
		}
//		print(s);
//		cout<<"pos:"<<pos<<endl;
//		cout<<endl;
	}
	cout<<pos;
	return 0;
}


