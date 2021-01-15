#include <iostream>

using namespace std;

int main()
{
    int num,display=0,waited=0;
    cin>>num;
    for(int i=0;i<num;i++){
        int m,s;
        cin>>m>>s;
        display+=m*60;
        waited+=s;
    }
    cout.precision(9);
    if(1.0*waited/display>1){
        cout<<fixed<<1.0*waited/display;
    }else{
        cout<<"measurement error";
    }
    return 0;
}
