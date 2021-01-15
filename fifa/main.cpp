#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct team{
		int id=0;
		int point=0;
		int goaldiff=0;
		int goal=0;
	};

int main() {
	
	int n;
	cin>>n;
	int ta,tb,agoal,bgoal;
	team t[n];
	for(int i=0;i<n*(n-1)/2;i++){
		cin>>ta>>tb>>agoal;
		getchar();
		cin>>bgoal;
		cout<<ta<<" "<<tb<<" "<<agoal<<" "<<bgoal<<endl;
		ta=ta-1;
		tb=tb-1;
		t[ta].id=ta+1;
		t[tb].id=tb+1;
		t[ta].goal+=agoal;
		t[tb].goal+=bgoal;
		if(agoal>bgoal){
			t[ta].point+=3;
			t[ta].goaldiff+=agoal-bgoal;
			t[tb].goaldiff+=bgoal-agoal;
		}else if(agoal==bgoal){
			t[ta].point+=1;
			t[tb].point+=1;
		}else{
			t[tb].point+=3;
			t[tb].goaldiff+=bgoal-agoal;
			t[ta].goaldiff+=agoal-bgoal;
		}
	}
	for(int i=0;i<n;i++){
		cout<<t[i].id<<" ";
		cout<<t[i].point<<" ";
		cout<<t[i].goaldiff<<" ";
		cout<<t[i].goal<<endl;
	}
	
	sort(t,t+n,
	[](team a,team b)->bool{
		if(a.point!=b.point){
			return b.point<a.point;
		}
		if(a.goaldiff!=b.goaldiff){
			return b.goaldiff<a.goaldiff;
		}
		if(a.goal!=b.goal){
			return b.goal<a.goal;
		}
		return a.id<b.id;
	});
	for(int i=0;i<n;i++){
		cout<<t[i].id<<" ";
		cout<<t[i].point<<" ";
		cout<<t[i].goaldiff<<" ";
		cout<<t[i].goal<<endl;
	}
	
	//4 1 2 1-2 3 4 2-1 2 3 2-2 1 4 3-0 2 4 0-1 1 3 1-0
	return 0;
}
