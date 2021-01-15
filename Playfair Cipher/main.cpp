#include <iostream>

using namespace std;

int main()
{
    char table[5][5];
    string str;
    int alpha[26]={0};
    getline(cin,str);
    int curx=0,cury=0;
    for(int i=0;i<str.length();i++){
        char x=str[i];
        if(!alpha[(int)(x-'a')]&&x!=' '&&x!='q'&&cury!=5){
            table[cury][curx]=x;
            curx++;
            if(curx==5){
                curx=0;
                cury++;
            }
            alpha[(int)(x-'a')]=1;
        }
    }
    int index=0;
    while(cury<5){
        if(index!=(int)('q'-'a')&&!alpha[index]){
            table[cury][curx]=(char)(index+'a');
            curx++;
            if(curx==5){
                curx=0;
                cury++;
            }
        }
        index++;
    }

//    for(int i=0;i<5;i++){
//        for(int j=0;j<5;j++){
//            cout<<table[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    string text;
    getline(cin,text);
    for(int i=0;i<text.length();i++){
        while(text[i]==' '){
            text.erase(i,1);
        }
    }
    //cout<<text<<endl;

    index=0;
    while(index<text.length()-1){
        if(text[index]==text[index+1]){
            text.insert(index+1,1,'x');
        }
        index+=2;
    }
    if(text.length()%2){
        text.append("x");
    }
   // cout<<text<<endl;

    for(int i=0;i<text.length();i+=2){
        char a=text[i],b=text[i+1];
        //cout<<a<<" "<<b<<endl;
        int arow,acol,brow,bcol;
        for(int m=0;m<5;m++){
            for(int n=0;n<5;n++){
                if(table[m][n]==a){
                    arow=m;
                    acol=n;
                }
                if(table[m][n]==b){
                    brow=m;
                    bcol=n;
                }
            }
        }
        if(arow==brow){
            char x=table[arow][(acol+1)%5]-'a'+'A';
            cout<<x;
            char y=table[brow][(bcol+1)%5]-'a'+'A';
            cout<<y;
        }else if(acol==bcol){
            char x=table[(arow+1)%5][acol]-'a'+'A';
            cout<<x;
            char y=table[(brow+1)%5][bcol]-'a'+'A';
            cout<<y;
        }else{
            char x=table[arow][bcol]-'a'+'A';
            cout<<x;
            char y=table[brow][acol]-'a'+'A';
            cout<<y;
        }
    }

    return 0;
}
