#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


vector<int> generate(int n){
	vector<int> v;
	for(int i=0;i<n;i++){
		v.push_back(rand()%10000);
	}
	return v;
}

int main() {
	
	int n;
	cin>>n;
	pair<int,int> p[n];
	vector<int> v=generate(n);
	
	for(int i=0;i<n;i++){
//		int num;
//		cin>>num;
//		p[i].first=num;
		p[i].first=v[i];
		p[i].second=i;
	}
	
	for(int i=0;i<n;i++){
		cout<<p[i].first<<" "<<p[i].second<<endl;
	}
	
	cout<<"sorted:"<<endl;
	
	sort(p,p+n,
	[](pair<int,int> a,pair<int,int> b)->bool{
		return a.first<b.first;	
	});
	
	for(int i=0;i<n;i++){
		cout<<p[i].first<<" "<<p[i].second<<endl;
	}
	
	return 0;
}
