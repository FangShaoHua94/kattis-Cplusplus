#include <iostream>

using namespace std;

bool possible(int a,int b,int c);

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(possible(a,b,c)||possible(b,a,c)){
            cout<<"Possible"<<endl;
        }else{
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}

bool possible(int a,int b,int c){
    if(a+b==c||a*b==c||a-b==c||(b!=0&&1.0*a/b==1.0*c)){
       return true;
    }
    return false;
}
