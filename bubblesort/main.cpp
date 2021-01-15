#include <iostream>

using namespace std;

void bubble_sort(int arr[],int n);

int main()
{

    int arr[]={3,7,42,0,5,2,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool done=true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                done=false;
            }
        }
        if(done){
            break;
        }
    }
}
