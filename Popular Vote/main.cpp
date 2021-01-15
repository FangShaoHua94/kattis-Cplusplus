#include <iostream>

using namespace std;

int main()
{
    unsigned int tcase;
    cin>>tcase;
    while(tcase-->0){
        unsigned int num,total=0,max,id=1;
        bool x=false;
        cin>>num>>max;
        total=max;
        for(int i=1;i<num;i++){
            int vote;
            cin>>vote;
            if(max==vote){
                x=true;
            }else if(max<vote){
                max=vote;
                x=false;
                id=i+1;
            }
            total+=vote;
        }
        if(x){
            cout<<"no winner"<<endl;
        }else if(1.0*max/total>0.5){
            cout<<"majority winner "<<id<<endl;
        }else{
            cout<<"minority winner "<<id<<endl;
        }
    }
    return 0;
}
