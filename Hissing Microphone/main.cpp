#include <iostream>

using namespace std;

int main()
{
    string x;
    cin>>x;
    for(int i=0;i<x.length()-1;i++){
        if(x[i]=='s'&&x[i+1]=='s'){
            cout<<"hiss";
            return 0;
        }
    }
    cout<<"no hiss";
    return 0;
}
