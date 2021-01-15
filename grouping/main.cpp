#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int N,K;
	cin>>N>>K;
	int score[N];
	for(int i=0;i<N;i++){
		cin>>score[i];
	}

	sort(score,score+N);//counting sort
	
	for(int i=0;i<N;i++){
		cout<<score[i]<<" ";
	}
	
	if(N==K){
		cout<<score[N-1]-score[0];
		return 0;
	}
	int min=score[K-1]-score[0];
	for(int i=0;i<N-K;i++){
		min=min>(score[i+K-1]-score[i])?score[i+K-1]-score[i]:min;
	}
	cout<<min;
		
	return 0;
}
