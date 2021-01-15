#include <iostream>

using namespace std;

int main()
{
    int n,i=1;
    while(cin>>n){
        int max,min,range,x;
        cin>>x;
        max=x;
        min=x;
        while(n-->1){
            cin>>x;
            max=max>x?max:x;
            min=min<x?min:x;
        }
        cout<<"Case "<<i<<": "<<min<<" "<<max<<" "<<max-min<<endl;
        i++;
    }
    return 0;
}
