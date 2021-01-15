#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void radix_sort(int arr[],int n);

int main()
{
    int arr[]={32346,7445,41346,643,534,6342,2355};
    int n =sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void radix_sort(int arr[],int n){
    vector<queue<int>> bucket(10);
    int divi=1;
    while(divi<100000){
        for(int i=0;i<n;i++){
            bucket.at(arr[i]/divi%10).push(arr[i]);
        }
        int dex=0;
        for(int i=0;i<10;i++){
            while(!bucket.at(i).empty()){
                arr[dex++]=bucket.at(i).front();
                bucket.at(i).pop();
            }
        }
        divi*=10;
    }
}
