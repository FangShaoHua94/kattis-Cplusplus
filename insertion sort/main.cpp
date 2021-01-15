#include <iostream>

using namespace std;

void insertion_sort(int arr[],int n);
void insertion_sort2(int arr[],int n);

int main()
{
    int arr[]={3,7,42,0,5,2,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    insertion_sort2(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void insertion_sort2(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0&&arr[j-1]>arr[j];j--){
            swap(arr[j-1],arr[j]);
        }
    }
}
