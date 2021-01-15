#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char score[14][10000];
    string x;
    int pos=0;
    for(int i=0;i<n;i++){
        cin>>x;
        //cout<<x<<endl;
        int val=(int)x[0];
        //cout<<"val-"<<val<<endl;
        if(val<=71){
            score[71-val][pos]='*';
        }else{
            score[103-val+7][pos]='*';
        }
        pos++;
        if(x.length()==2){
            int num=(int)(x[1]-'1');
            for(int j=0;j<num;j++){
                if(val<=71){
                    score[71-val][pos]='*';
                }else{
                    score[103-val+7][pos]='*';
                }
            pos++;
            }
       }
       pos++;
    }

    for(int i=0;i<14;i++){
        if(i<=6){
            cout<<(char)(71-i)<<": ";
        }else{
            cout<<(char)(103-i+7)<<": ";
        }
        for(int j=0;j<pos-1;j++){
            if(score[i][j]=='\0'){
                if(i==1||i==3||i==5||i==7||i==9||i==13){
                    cout<<'-';
                }else{
                    cout<<' ';
                }
            }else{
                cout<<score[i][j];
            }
        }
        cout<<endl;
    }

    return 0;
}
