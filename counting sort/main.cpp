#include <iostream>

using namespace std;

void counting_sort(int arr[],int n);

int main()
{
    int arr[]={3,7,4,0,5,2,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    counting_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
void counting_sort(int arr[],int n){
    int sizn=n*2;
    int temp[sizn]={0};

    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<sizn;i++){
        while(temp[i]!=0){
            arr[index++]=i;
            temp[i]--;
        }
    }

}
