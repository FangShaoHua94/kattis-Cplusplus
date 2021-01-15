#include <iostream>

using namespace std;

bool rightpath(int x,int y,string arr[],int n);


int main()
{
    int x,y,n;
    cin>>x>>y>>n;
    string arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string a="Left",b="Right",c="Forward";
    for(int i=0;i<n;i++){
        string temp=arr[i];
        if(arr[i]==a){
            arr[i]=b;
            if(rightpath(x,y,arr,n)){
                cout<<i+1<<" "<<b;
                break;
            }
            arr[i]=c;
            if(rightpath(x,y,arr,n)){
                cout<<i+1<<" "<<c;
                break;
            }
        }else if(arr[i]==b){
            arr[i]=a;
            if(rightpath(x,y,arr,n)){
                cout<<i+1<<" "<<a;
                break;
            }
            arr[i]=c;
            if(rightpath(x,y,arr,n)){
                cout<<i+1<<" "<<c;
                break;
            }
        }else if(arr[i]==c){
            arr[i]=a;
            if(rightpath(x,y,arr,n)){
                cout<<i+1<<" "<<a;
                break;
            }
            arr[i]=b;
            if(rightpath(x,y,arr,n)){
                cout<<i+1<<" "<<b;
                break;
            }
        }
        arr[i]=temp;
    }
    return 0;
}

bool rightpath(int x,int y,string arr[],int n){

    int curx=0,cury=0;
    int dir=0;  //direction north 0,west 1,south 2,east 3

    for(int i=0;i<n;i++){
        if(arr[i]=="Left"){
            dir=++dir%4;
        }else if(arr[i]=="Right"){
            dir=--dir<0?3:dir;
        }else{
            switch(dir){
        case 0:
            cury++;
            break;
        case 1:
            curx--;
            break;
        case 2:
            cury--;
            break;
        case 3:
            curx++;
            break;
            }
        }
    }
    if(curx==x&&cury==y){
        return true;
    }else{
        return false;
    }
}
