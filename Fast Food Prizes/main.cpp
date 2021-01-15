#include <iostream>

using namespace std;

class Prize{
    int* ticket;
    int* holding;
    int size;
    int cash;

public:
    void init(){
        cin>>size;
        ticket=new int[size];
        holding=new int[size];
        setticket();
        cin>>cash;
    }

    void add(int x,int y){
        if(containticket(x)!=-1){
            holding[containticket(x)]=y;
        }
    }

    int reward(){
        int sum=0;
        while(!done()){
            sum+=cash;
            for(int i=0;i<size;i++){
                holding[i]--;
            }
        }
        return sum;
    }

private:
    bool done(){
        for(int i=0;i<size;i++){
            if(holding[i]==0){
                return true;
            }
        }
        return false;
    }

    void setticket(){
        for(int i=0;i<size;i++){
            cin>>ticket[i];
            holding[i]=0;
        }
    }

    int containticket(int x){
        for(int i=0;i<size;i++){
            if(ticket[i]==x){
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    int testcase;
    cin>>testcase;
    int arr[testcase];
    for(int i=0;i<testcase;i++){
        int n,m,sum=0;
        cin>>n>>m;
        Prize a[n];
        for(int j=0;j<n;j++){
            a[j].init();
        }

        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            for(int k=0;k<n;k++){
                a[k].add(j+1,t);
            }
        }

        for(int j=0;j<n;j++){
            sum+=a[j].reward();
        }
        arr[i]=sum;
    }

    for(int i=0;i<testcase;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
