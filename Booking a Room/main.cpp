#include <iostream>

using namespace std;

int main()
{
    int r,n,x;
    cin>>r>>n;
    int arr[r]={0};
    while(n-->0){
        cin>>x;
        arr[x-1]=1;
    }
    for(int i=0;i<r;i++){
        if(!arr[i]){
            cout<<i+1;
            return 0;
        }
    }
    cout<<"too late";


    return 0;
}
