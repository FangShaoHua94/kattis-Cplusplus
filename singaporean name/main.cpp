#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string call_as(string name);

int main() {
	string name="Ng Zhen Rui Matthew";
	name=call_as(name);
	name="Tan Jun An";
	name=call_as(name);
	name="Lim Li";
	name=call_as(name);
	cout<<"lol";
	return 0;
}

string call_as(string name){
//	char n[]=name;
	int count=0;
	vector<char> q[4];
//	char *pch;
//	pch=strtok(n," ");
//	while(pch!=NULL){
//		q[count++]=pch;
//		pch=strtok(NULL," ");
//	}
	for(int i=0;i<name.size();i++){
		if(name[i]==' '){
			count++;
		}else{
			q[count].push_back(name[i]);
		}
	}
	switch(count){
		case 1:
			for(char ch:q[0]){
				cout<<ch;
			}cout<<" ";
			for(char ch:q[1]){
				cout<<ch;
			}
			break;
		case 2:
			for(char ch:q[1]){
				cout<<ch;
			}cout<<" ";
			for(char ch:q[2]){
				cout<<ch;
			}
			break;
		case 3:
			for(char ch:q[3]){
				cout<<ch;
			}cout<<" ";
			for(char ch:q[0]){
				cout<<ch;
			}
			break;
	}
	cout<<endl;
	return name;
}
