#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    while(cin>>num){
        if(num==1){
            int x;
            cin>>x;
            cout<<"Jolly"<<endl;
        }else{
            int pnum,curnum,diff;
            bool jolly=true;
            cin>>pnum;
            int arr[num]={0};
            for(int i=1;i<num;i++){
                cin>>curnum;
                diff=abs(curnum-pnum);
                if(diff==0||diff>num-1||arr[diff]==1){
                    jolly=false;
                }
                arr[diff]=1;
                pnum=curnum;
            }
            if(jolly){
                cout<<"Jolly"<<endl;
            }else{
                cout<<"Not jolly"<<endl;
            }
        }
    }
    return 0;
}
