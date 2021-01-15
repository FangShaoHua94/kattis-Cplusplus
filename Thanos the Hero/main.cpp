#include <iostream>

using namespace std;

int main()
{
    int n;
    long total=0;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
    }else{
        bool flag=true;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<i){
                flag=false;
            }
        }
        if(flag){
            for(int i=n-1;i>0;i--){
                if(arr[i]<=arr[i-1]){
                    total+=arr[i-1]-arr[i]+1;
                    arr[i-1]=arr[i]-1;
                }
            }
            cout<<total<<endl;
        }else{
            cout<<1<<endl;
        }
    }

    return 0;
}
