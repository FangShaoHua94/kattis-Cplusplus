#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int N,t;cin>>N>>t;
	vector<int> v(N);
	int start=0,end=N-1;
	bool flag=false;
	for(auto &val:v){
		cin>>val;
	}
    
    switch (t){
    	case 1:
    		sort(v.begin(),v.end());
    		
    		while(start<end&&v[start]+v[end]!=7777){
    			if(v[start]+v[end]>7777){
    				end--;
				}else{
					start++;
				}
			}
			if(v[start]+v[end]==7777){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
    		break;
    	case 2:
    		sort(v.begin(),v.end());
    		for(int i=0;i<N-2;i++){
    			if(v[i]==v[i+1]){
    				cout<<"Contains duplicate"<<endl;
    				flag=true;
    				break;
				}
			}
			if(!flag){
				cout<<"Unique"<<endl;
			}
    		break;	
    	case 3:
    		sort(v.begin(),v.end());
    		for(int i=0;i<N/2;i++){
    			if(v[i]==v[i+N/2]){
    				cout<<v[i]<<endl;
    				flag=true;
    				break;
				}
			}
			if(!flag){
				cout<<-1<<endl;
			}
			break;
		case 4:
			sort(v.begin(),v.end());
			if(N%2==1){
				cout<<v[N/2]<<endl;
			}else{
				cout<<v[N/2-1]<<" "<<v[N/2]<<endl;
			}
			break;
		case 5:
			sort(v.begin(),v.end());
			for(int i=0;i<N;i++){
				if(v[i]>=100&&v[i]<=999){
					cout<<v[i]<<" ";
				}
			}
			cout<<endl;
			break;
	}
    
	return 0;
}
