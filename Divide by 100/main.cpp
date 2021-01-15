#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int trailzero(string x);

int main()
{
    string n,m;
    cin>>n>>m;
    if(n.length()>m.length()){
        if(trailzero(n)>trailzero(m)){
            n=n.substr(0,trailzero(n)-trailzero(m)+1);
        }else{
            n.insert(n.length()-trailzero(m),".");
            n=n.substr(0,n.length()-trailzero(n));
        }
        cout<<n;
    }else{
        if(m.length()==1){
            cout<<n;
        }
        m=m.substr(1,m.length()-n.length());
        n=n.substr(0,n.length()-trailzero(n));
        m.insert(1,".");
        m.append(n);
        cout<<m;
    }

    return 0;
}

int trailzero(string x){
    int c=0;
    for(int i=x.length()-1;i>0;i--){
        if(x[i]=='0'){
            c++;
        }else{
            break;
        }
    }
return c;
}
