#include <iostream>
#include <cstdlib>

using namespace std;

void random_quick_sort(int arr[],int left,int right);

int main()
{
    int arr[]={3,7,42,0,5,2,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    random_quick_sort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


void random_quick_sort(int arr[],int left,int right){
    int l=left,r=right-1,siz=right-left;
    if(siz>1){
        int pivot=arr[rand()&siz+l];

        while(l<r){
            while(arr[r]>pivot&&r>l){
                r--;
            }
            while(arr[l]<pivot&&l<=r){
                l++;
            }
            if(l<r){
                swap(arr[l],arr[r]);
                l++;
            }
        }
        random_quick_sort(arr,left,l);
        random_quick_sort(arr,r,right);
    }

}

