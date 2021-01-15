#include <bits/stdc++.h>


using namespace std;

int flip(int x){
	int a=x/100;
	int b=x/10%10;
	int c=x%10;
	return c*100+b*10+a;
}

int main() {
	
	freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a,b;
	cin>>a>>b;
	int ra=flip(a),rb=flip(b);
	cout<<(ra>rb?ra:rb);
	
	return 0;
}


