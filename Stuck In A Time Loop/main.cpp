#include <iostream>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    char mapz[r][c];
    bool check[r][c]={false};

    int curx=0,cury=0,co=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mapz[i][j];
        }
    }

    while(true){
        if(check[cury][curx]){
            cout<<"Lost"<<endl;
            return 0;
        }
        check[cury][curx]=true;
        switch(mapz[cury][curx]){
        case 'E':
            curx++;
            break;
        case 'S':
            cury++;
            break;
        case 'W':
            curx--;
            break;
        case 'N':
            cury--;
            break;
        case 'T':
            cout<<co<<endl;
            return 0;
            }
        if(curx<0||curx>=c||cury<0||cury>=r){
            cout<<"Out"<<endl;
            return 0;
        }
        co++;
    }
    return 0;
}
