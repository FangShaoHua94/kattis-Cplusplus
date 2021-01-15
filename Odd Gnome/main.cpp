#include <iostream>

using namespace std;

int main()
{
    int group,j,sizez,ini,curr;
    cin>>group;
    while(group-->0){
        cin>>sizez>>ini;
        for(j=2;j<=sizez;++j){
            cin>>curr;
            if(curr!=ini+j-1){
                cout<<j<<endl;
                ini--;
            }
        }
    }
    return 0;
}
