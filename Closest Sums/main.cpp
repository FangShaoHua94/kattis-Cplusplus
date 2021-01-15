#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n,m,val,z=1;

    while(cin>>n){
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>m;
        cout<<"Case "<<z<<":"<<endl;
        while(m-->0){
            cin>>val;
            int diff=abs(arr[0]+arr[1]-val),ans=arr[0]+arr[1];
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(abs(arr[i]+arr[j]-val)<diff){
                        diff=abs(arr[i]+arr[j]-val);
                        ans=arr[i]+arr[j];
                    }
                }
            }
            cout<<"Closest sum to "<<val<<" is "<<ans<<"."<<endl;
        }
        z++;
    }
    return 0;
}
