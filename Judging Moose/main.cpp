#include <iostream>

using namespace std;

int main()
{
    int l,r;
    cin>>l>>r;
    if(!l&&!r){
        cout<<"Not a moose";
    }else if(l==r){
        cout<<"Even "<<l+r;
    }else{
        cout<<"Odd ";
        if(r>l){
            cout<<r+r;
        }else{
            cout<<l+l;
        }
    }
    return 0;
}
