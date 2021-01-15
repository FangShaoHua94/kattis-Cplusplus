#include <iostream>
#include <vector>

using namespace std;

void addtoback(string x[],string y);

int main()
{
    int x=0,y=0;
    string arr[7];
    for(int i=0;i<7;i++){
        cin>>arr[i];
        cin.ignore();
    }

    string zero="xxxxxx...xx...xx...xx...xx...xxxxxx";
    string one="....x....x....x....x....x....x....x";
    string two="xxxxx....x....xxxxxxx....x....xxxxx";
    string three="xxxxx....x....xxxxxx....x....xxxxxx";
    string four="x...xx...xx...xxxxxx....x....x....x";
    string five="xxxxxx....x....xxxxx....x....xxxxxx";
    string six="xxxxxx....x....xxxxxx...xx...xxxxxx";
    string seven="xxxxx....x....x....x....x....x....x";
    string eight="xxxxxx...xx...xxxxxxx...xx...xxxxxx";
    string nine="xxxxxx...xx...xxxxxx....x....xxxxxx";
    string plus=".......x....x..xxxxx..x....x.......";
    string sym[11]={zero,one,two,three,four,five,six,seven,eight,nine,plus};

    int a=0,m;
    bool flag=false;
    while(a<arr[0].length()){
        string temp;
        for(int i=0;i<7;i++){
            for(int j=a;j<a+5;j++){
                temp+=arr[i][j];
            }
        }

        for(m=0;m<11;m++){
            if(temp.compare(sym[m])==0){
                break;
            }
        }
        if(m==10){
            flag=true;
        }else{
            if(flag){
                y=y*10+m;
            }else{
                x=x*10+m;
            }
        }
        a+=6;
    }

    int ans=x+y;
    string str[7];
    while(ans>0){
        int digit=ans%10;
        addtoback(str,sym[digit]);
        ans/=10;
    }
    for(int i=0;i<7;i++){
        str[i]=str[i].substr(0,str[i].size()-1);
        cout<<str[i]<<endl;
    }

    return 0;
}

void addtoback(string x[],string y){
    for(int i=0;i<7;i++){
        string temp=y.substr(5*i,5);
        temp.append(".");
        temp.append(x[i]);
        x[i]=temp;
    }
}
