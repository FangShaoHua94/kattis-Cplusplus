#include <bits/stdc++.h>

using namespace std;

//void print(vector<int> v){
//	cout<<"vector: ";
//	for(int &num:v){
//		cout<<num<<" ";
//	}
//	cout<<endl;
//}

void insertz(vector<int> &v,int num,int start,int end){
	//cout<<"start:"<<start<<" end:"<<end<<endl;
	if(start>=end){
		 v.insert(v.begin()+start,num);
	}else{
		int mid=(start+end)/2;
		if(v.at(mid)>num){
			insertz(v,num,start,mid);
		}else if(v.at(mid)<num){
			insertz(v,num,mid+1,end);
		}else{
			v.insert(v.begin()+mid,num);
		}
	}
}

int main2() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; //1-100
	cin>>tc;
	
	while(tc--){
		
		int n;//1-400000
		cin>>n;
		long int sum=0;
		
		vector<int> v;
		for(int i=1;i<=n;i++){
			int num;
			cin>>num;
			//cout<<"size:"<<v.size()<<endl;
			insertz(v,num,0,v.size());
			//print(v);
			if(i%2==0){
				sum+=(v.at(i/2)+v.at(i/2-1))/2;
			}else{
				sum+=v.at(i/2);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
