#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n,max,x;
    cin>>n;
    vector<int> v;
    vector<int> ma;
    for(int i=0;i<n;i++){
        cin>>x;
        if(i==0){
            max=x;
        }
        max=max>x?max:x;
        v.push_back(x);
        ma.push_back(max);
    }
    
    
    vector<int> bac;
    int min=v.at(n-1);
    for(int i=n-1;i>=0;i--){
        min=min<v.at(i)?min:v.at(i);
        bac.push_back(min);
    }
    
//  for(int r:v){
//      cout<<r<<" ";
//  }cout<<endl;
//  for(int r:ma){
//      cout<<r<<" ";
//  }cout<<endl;
//  for(int r:bac){
//      cout<<r<<" ";
//  }cout<<endl;
    
    
    int count=0;
    for(int i=0;i<n;i++){
        int t=v.at(i);
        if(t>=ma.at(i)&&t<=bac.at(n-i-1)){
            count++;
        }
    }
    cout<<count;

    return 0;
}
