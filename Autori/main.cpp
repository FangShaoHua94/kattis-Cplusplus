#include <iostream>

using namespace std;

int main()
{
    string str,ans;
    cin>>str;
    ans+=str[0];
    for(int i=0;i<str.length();i++){
        if(str[i]=='-'&&str[i+1]!='\0'){
            ans+=str[i+1];
        }
    }
    cout<<ans;
    return 0;
}
