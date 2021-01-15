#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class StackR{
	private:
		stack<int> a;
		stack<int> b;
		
	public:
		StackR(){
			
		}
		void push(int value){
			if(!a.empty()){
				if(a.top()>value){
					a.push(a.top());
				}else{
					a.push(value);
				}
			}else{
				a.push(value);
			}
			b.push(value);
		}
		int top(){
			return b.top();
		}
		int pop(){
			a.pop();
			int temo=b.top();
			b.pop();
			return temo;
		}
		int findmax(){
			if(a.empty()){
				return -1;
			}
			return a.top();
		}
};

int main() {
	StackR S;
	cout<<S.findmax()<<endl;
	S.push(2);S.push(7);S.push(1);
	S.push(6);S.push(8);S.push(5);
	cout<<S.top()<<endl;
	cout<<S.findmax()<<endl;
	S.pop();
	cout<<S.top()<<endl;
	cout<<S.findmax()<<endl;
	S.pop();
	cout<<S.top()<<endl;
	cout<<S.findmax()<<endl;
	return 0;
}
