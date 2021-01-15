#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n!=-1){
        int j=0,x,y,total=0;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            total+=(y-j)*x;
            j=y;
        }
        cout<<total<<" miles"<<endl;
        cin>>n;
    }
    return 0;
}
