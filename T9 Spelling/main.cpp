#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string x,y;
        getline(cin,x);
        for(int j=0;j<x.length();j++){
            string z;
            switch ((int)x[j]){
            case 99:
                z.append("2");
            case 98:
                 z.append("2");
            case 97:
                z.append("2");
                if(j>0&&((int)x[j-1])>=97&&((int)x[j-1])<=99){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 102:
                z.append("3");
            case 101:
                z.append("3");
            case 100:
                z.append("3");
                 if(j>0&&((int)x[j-1])>=100&&((int)x[j-1])<=102){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 105:
                z.append("4");
            case 104:
                z.append("4");
            case 103:
                z.append("4");
                 if(j>0&&((int)x[j-1])>=103&&((int)x[j-1])<=105){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 108:
                z.append("5");
            case 107:
                z.append("5");
            case 106:
                z.append("5");
                 if(j>0&&((int)x[j-1])>=106&&((int)x[j-1])<=108){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 111:
                z.append("6");
            case 110:
                z.append("6");
            case 109:
                z.append("6");
                 if(j>0&&((int)x[j-1])>=109&&((int)x[j-1])<=111){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 115:
                z.append("7");
            case 114:
                z.append("7");
            case 113:
                z.append("7");
            case 112:
                z.append("7");
                 if(j>0&&((int)x[j-1])>=112&&((int)x[j-1])<=115){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 118:
                z.append("8");
            case 117:
                z.append("8");
            case 116:
                z.append("8");
                 if(j>0&&((int)x[j-1])>=116&&((int)x[j-1])<=118){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 122:
                z.append("9");
            case 121:
                z.append("9");
            case 120:
                z.append("9");
            case 119:
                z.append("9");
                 if(j>0&&((int)x[j-1])>=119&&((int)x[j-1])<=122){
                    y.append(" ");
                }
                y.append(z);
                break;
            case 32:
                if(j>0&&((int)x[j-1])==32){
                    y.append(" ");
                }
                y.append("0");
                break;
            }
        }
        cout<<"Case #"<<i+1<<": "<<y<<endl;
    }
    return 0;
}
