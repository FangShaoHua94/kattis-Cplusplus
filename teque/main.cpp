#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;



void showdq(deque <int> g) 
{ 
    deque <int> :: iterator it; 
    cout<<"[";
    for (it = g.begin(); it != g.end(); ++it){
    	 cout <<  *it<<" "; 
	} 
    cout <<"]"<<endl; 
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<int> a;
	deque<int> b;
	
	int N;
	cin>>N;
	string a1="push_back";
	string a2="push_front";
	string a3="push_middle";
	string a4="get";
	
	string S;int x;
	while(N--){
		cin>>S>>x;
		if(S=="push_back"){
			b.push_back(x);
		}else if(S=="push_front"){
			a.push_front(x);
		}else if(S=="push_middle"){
			while(a.size()>b.size()){
				b.push_front(a.at(a.size()-1));
				a.pop_back();
			}
			while(a.size()<b.size()){
				a.push_back(b.at(0));
				b.pop_front();
			}

			b.push_front(x);
		}else if(S=="get"){
			if(x>=a.size()){
				cout<<b.at(x-a.size())<<endl;
			}else{
				cout<<a.at(x)<<endl;
			}
		}
//		showdq(a);
//		showdq(b);

	}

	return 0;
}
