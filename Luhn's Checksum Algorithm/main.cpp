#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str;
        cin>>str;
        int sum=0,flag=0;
        for(int i=str.length()-1;i>=0;i--){
            int val=(int)(str[i]-'0');
            if(flag%2){
                val*=2;
                if(val>=10){
                    val=val/10+val%10;
                }
            }
            sum+=val;
            flag++;
        }
        if(sum%10==0){
            cout<<"PASS"<<endl;
        }else{
            cout<<"FAIL"<<endl;
        }

    }
    return 0;
}

