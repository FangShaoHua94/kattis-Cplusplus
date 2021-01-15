#include <bits/stdc++.h>

using namespace std;
/* run this program. using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int arr[]={5,8,6,1,7,2};
	list<int> a(begin(arr),end(arr));
	string x;
	int front=1;
	cin>>x;
	for(auto ch:x){
		if(ch=='D'){
			if(front==1){
				a.pop_front();
			}else{
				a.pop_back();
			}
		}else{
			front*=-1;
		}
		if(front==1){
			for(list<int>::iterator it=a.begin();it!=a.end();++it){
				cout<<*it<<" ";
			}cout<<endl;
		}else{
			for(list<int>::iterator it=a.rbegin();it!=a.rend();++it){
				cout<<*it<<" ";
			}cout<<endl;
		}
	}
	return 0;
}
