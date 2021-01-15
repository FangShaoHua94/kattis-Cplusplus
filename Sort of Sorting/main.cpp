#include <iostream>

using namespace std;

void sortz(string arr[],int n);
int compare(string a,string b);
void print(string arr[],int n);


int main()
{
    int n;
    cin>>n;
    while(n){
        string arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sortz(arr,n);
        print(arr,n);
        cin>>n;
        if(n){
            cout<<endl;
        }
    }
    return 0;
}
void sortz(string arr[],int n){
    bool swapped;
    do{
        swapped=false;
        for(int i=0;i<n-1;i++){
            if(compare(arr[i],arr[i+1])==1){
                string temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                swapped=true;
            }
        }
    }while(swapped);
}

int compare(string a,string b){
    for(int i=0;i<2;i++){
        if(a[i]>b[i]){
            return 1;
        }else if(a[i]<b[i]){
            return -1;
        }
    }
    return 0;
}

void print(string arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
