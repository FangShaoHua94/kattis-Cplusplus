#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m,p;
	cin>>n>>m>>p;
	vector<int> a(n);
	for(auto &i:a){
		cin>>i;
	}
	
	vector<int> b(m);
	for(auto &i:b){
		cin>>i;
	}
	
	vector <long double> c(n*m);
	int pos=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c.at(pos)=(long double)(pow(10,6)*a[i]/b[j]);
			pos++;
		}
	}
	sort(c.begin(),c.end());

	bool flag=true;
	for(int i=0;i<n*m-1;i++){
		if(((c.at(i+1)-c.at(i))/c.at(i))>1.0*p/100){
			flag=false;
			break;
		}
	}
	
	if(flag){
		cout<<"Ride on!";
	}else{
		cout<<"Time to change gears!";
	}
	return 0;
}
