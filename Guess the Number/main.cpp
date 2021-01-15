#include <iostream>

using namespace std;

int main()
{
    int c=0;
    int i=1,j=1000;
    while(c<10){
        int guess=(i+j)/2;
        cout<<guess<<endl;
        string reply;
        cin>>reply;
        if(reply=="correct"){
            break;
        }
        if(reply=="higher"){
            i=guess+1;
        }else{
            j=guess-1;
        }
        c++;
    }

    return 0;
}
