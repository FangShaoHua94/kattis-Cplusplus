#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int compare(int x,int y){//positve no need swap, negative swap
	if(x%2==0&&y%2==1){//x even,y odd,no need swap
		return 1;
	}
	if(x%2==1&&y%2==0){//x odd,y even, need swap
		return 0;
	}
	if(x%2==0&&y%2==0){//both even, if x>y then no need swap
		return x>y;
	}
	if(x%2==1&&y%2==1){//both odd, if x<y then no need swap
		return x<y;
	}
}
//14 1 3 2 4 5 6 7 5 7 2 1 2 9 6

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> A(n);
//	A = {1, 3, 2, 4, 5, 6, 7, 5, 7, 2, 1, 2, 9, 6};
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(auto v:A){
		cout<<v<<" ";
	}cout<<endl;
	sort(A.begin(),A.end(),compare);
	
	for(auto v:A){
		cout<<v<<" ";
	}cout<<endl;
	
	return 0;
}
