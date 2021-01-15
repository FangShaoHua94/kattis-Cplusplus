#include <iostream>

using namespace std;

string convert(int x);

int main()
{
    string str;
    while(getline(cin,str)){
        string q;
        for(int i=0;i<str.length();i++){
            if(isdigit(str[i])){
                //cout<<str[i]<<endl;
                int x=(int)(str[i]-'0');
               // cout<<x<<endl;
                if((i+1)<str.length()&&isdigit(str[i+1])){
                    x=x*10+(int)(str[i+1]-'0');
                    i++;
                   // cout<<x<<endl;
                }
                string temp=convert(x);
                q.append(temp);
            }else{
                q+=str[i];
            }
        }
        if(q[0]>='a'){
            q[0]=q[0]-'a'+'A';
        }
        cout<<q<<endl;
    }
    return 0;
}

string convert(int x){
    string a[]={"ten","twenty","thirty","forty","fifty",
                "sixty","seventy","eighty","ninety"};
    string b[]={"one","two","three","four","five",
                "six","seven","eight","nine"};
    string c[]={"eleven","twelve","thirteen","fourteen",
                "fifteen","sixteen","seventeen","eighteen",
                "nineteen"};
    if(x==0){
        return "zero";
    }
    if(x<10){
        return b[x-1];
    }

    if(x>10&&x<20){
        return c[x-11];
    }
    if(x%10==0){
       // cout<<a[x/10-1];
        return a[x/10-1];
    }
    string q;
    q.append(a[x/10-1]);
    q.append("-");
    q.append(b[x%10-1]);
    return q;
}
