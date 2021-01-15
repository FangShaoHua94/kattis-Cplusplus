#include <iostream>

using namespace std;

int flip(int);

int main()
{
    int x,y;
    cin>>x>>y;
    for(int i=10;i<1000;i*=10){
        if(x%i!=y%i){
            if(x%i>y%i){
                cout<<flip(x);
                break;
            }else{
                cout<<flip(y);
                break;
            }
        }
    }
    return 0;
}

int flip(int x){
    int y=0,i=100;
    while(x>0){
        y+=x%10*i;
        i/=10;
        x/=10;
    }
    return y;
}
