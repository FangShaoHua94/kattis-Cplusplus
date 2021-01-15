#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    cin.get();
    while(n-->0){
        string str;
        getline(cin,str);
        int arr[26]={0};
        for(int i=0;i<str.length();i++){
            int num=(int)str[i];
            if(num>=65&&num<=90){
                arr[num-65]=1;
            }
            if(num>=97&&num<=122){
                arr[num-97]=1;
            }
        }
        string x;
        for(int i=0;i<26;i++){
            if(arr[i]==0){
                x+=(char)(i+97);
            }
        }
        if(x.length()!=0){
            cout<<"missing "<<x<<endl;
        }else{
            cout<<"pangram"<<endl;
        }
    }

    return 0;
}
