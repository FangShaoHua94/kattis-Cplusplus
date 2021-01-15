#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	stack<int> s1,s2,s3;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		s1.push(num);
	}

	int temp;
	while(!s1.empty()){
		temp=s1.top();
		while(!s1.empty()&&temp>=s1.top()){
			s2.push(s1.top());
			s1.pop();
			temp=s2.top();
		}	
		while(!s1.empty()&&!s2.empty()){
			if(s1.top()<s2.top()){
				if(!s3.empty()&&s3.top()>s1.top()){
					cout<<"false";
					return 0;
				}
				s3.push(s1.top());
				s1.pop();
			}else{
				if(!s3.empty()&&s3.top()>s2.top()){
					cout<<"false";
					return 0;
				}
				s3.push(s2.top());
				s2.pop();
			}
		}
		while(!s2.empty()){
			if(!s3.empty()&&s3.top()>s2.top()){
				cout<<"false";
				return 0;
			}
			s3.push(s2.top());
			s2.pop();
		}
	}
	
	cout<<"true";
	return 0;
}
