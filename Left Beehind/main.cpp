#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    while(!(x==0&&y==0)){
     string a=x+y==13?"Never speak again.\n":(x>y?"To the convention.":(x==y?"Undecided.":"Left beehind."));
     cout<<a<<endl;
     cin>>x>>y;
    }
    return 0;
}
