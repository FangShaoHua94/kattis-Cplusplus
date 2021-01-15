#include <iostream>

using namespace std;

int getval(int,int);

int main()
{
    int s1,s2,r1,r2;
    cin>>s1>>s2>>r1>>r2;
    while(s1!=0&&s2!=0&&r1!=0&&r2!=0){
        int p1=getval(s1,s2),p2=getval(r1,r2);
        if(p1>p2){
            cout<<"Player 1 wins."<<endl;
        }else if(p2>p1){
            cout<<"Player 2 wins."<<endl;
        }else{
            cout<<"Tie."<<endl;
        }
        cin>>s1>>s2>>r1>>r2;
    }
    return 0;
}


int getval(int x,int y){
    if(x<=2&&y<=2&&x!=y){
        return 200;
    }else if(x==y){
        return x*10+y+100;
    }else{
        if(x>y){
            return x*10+y;
        }else{
            return y*10+x;
        }
    }
}
