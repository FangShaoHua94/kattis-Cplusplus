#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++){
        cin>>str[i];
    }

    int fir,sec;
    int y=0;
    string a[10000];
    while(y++<3){
        cin>>fir;
        if(a[fir].empty()){
            a[fir]=to_string(fir);
        }
        cin>>sec;
        if(a[sec].empty()){
            a[sec]=to_string(sec);
        }
        a[fir]=a[sec]+a[fir];
    }
    cout<<a[fir]<<endl;
//    int x=a[fir];
//    while(x>0){
//        cout<<str[x%10-1];
//        x/=10;
//    }

    return 0;
}


