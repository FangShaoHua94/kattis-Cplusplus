#include <iostream>

using namespace std;

int main()
{
    int h,w,n;
    cin>>h>>w>>n;
    int curw=0,total=0;
    bool flag=true;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(flag){
            curw+=x;
            total+=x;
            curw=curw==w?0:curw;
            if(curw>w){
                flag=false;
            }
        }
    }
    if(total<h*w){
        flag=false;
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
