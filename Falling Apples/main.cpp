#include <iostream>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    char mat[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    int dest[c];
    std::fill_n(dest,c,r-1);

    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
           if(mat[i][j]!='.'){
              if(dest[j]==i){
                dest[j]=i-1;
              }else{
                if(mat[i][j]=='a'){
                    mat[dest[j]][j]='a';
                    mat[i][j]='.';
                    dest[j]--;
                }else{
                    dest[j]=i-1;
                }
              }
           }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    return 0;
}

