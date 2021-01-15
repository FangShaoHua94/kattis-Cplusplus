#include <iostream>

using namespace std;

int add(int,int);

int main()
{
    int arr[2000];
    int pos,c1,c2,c3,count=0,i=0;
    cin>>pos>>c1>>c2>>c3;
    while(pos!=0||c1!=0||c2!=0||c3!=0){
        int num=120;
        num+=add(pos,c1);
        num+=add(c2,c1);
        num+=add(c2,c3);
        arr[i++]=num;
        count++;
        cin>>pos>>c1>>c2>>c3;
    }
    for(i=0;i<count;i++){
        cout<<arr[i]*9<<endl;
    }
    return 0;
}

int add(int x,int y){
    if(x>=y){
        return x-y;
    }else{
        return x+40-y;
    }
}
