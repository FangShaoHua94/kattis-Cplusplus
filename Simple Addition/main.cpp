#include <iostream>

using namespace std;

int main()
{
    string x,y,sum="";
    cin>>x>>y;
    bool flag=false;
    int curx=x.length()-1,cury=y.length()-1;
    while(curx!=-1||cury!=-1){
       int a=0,b=0;
       if(curx!=-1){
        a=(int)(x[curx]-'0');
        curx--;
       }
       if(cury!=-1){
        b=(int)(y[cury]-'0');
        cury--;
       }
       if(flag){
        a++;
        flag=false;
       }
       if(a+b>=10){
        flag=true;
       }
       sum.insert(0,1,(char)((a+b)%10+'0'));
    }
    if(flag){
        sum.insert(0,1,'1');
    }
    cout<<sum;

    return 0;
}
