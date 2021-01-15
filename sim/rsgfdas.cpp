#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void print(deque<char> q){
	for(auto& c:q){
		cout<<c;
	}cout<<endl;
}

void print2(stack<int> p){
	cout<<"s:";
	while(!p.empty()){
		cout<<p.top();
		p.pop();
	}
	cout<<endl;
}

int main() {
	
	ios_base::sync_with_stdio(false);
cin.tie(NULL);

	int tc;
	cin>>tc;
	cin.get();
	while(tc--){
//		cout<<str<<endl;
		deque<char> d;
		stack<int> s;
		int x=0;
		char ch=getchar();
		while(ch!='\n'){
//			cout<<ch;
//			cout<<"x("<<x<<"):";
			switch(ch){
				case ']':
					x=d.size();
					break;
				case '[':
					x=0;
					break;
				case '<':
					if(!s.empty()&&x!=0){
						d.erase(d.begin()+s.top());
						s.pop();
						x--;
					}
					break;
				default:
					d.emplace(d.begin()+x,ch);
					s.push(x);
					x++;
			}
//			if(!d.empty()){
//				cout<<x;
//				print(d);
//			}else{
//				cout<<"empty"<<endl;
//			}
//			print2(s);
			ch=getchar();
		}
		print(d);
	}
	return 0;
}
