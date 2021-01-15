#include <iostream>

using namespace std;

int main()
{
   int n,m,x;
   cin>>n;
   int tprice[n];
   for(int i=0;i<n;i++){
    cin>>tprice[i];
   }
   cin>>m;
   int topprice[m];
   for(int i=0;i<m;i++){
    cin>>topprice[i];
   }
   int lowest;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int y;
            cin>>y;
            if(i==0&&j==0){
                lowest=tprice[i]+topprice[y-1];
            }else{
                lowest=(lowest<(tprice[i]+topprice[y-1]))?lowest:(tprice[i]+topprice[y-1]);
            }
        }
    }
    cin>>x;
    if(x/lowest-1<0){
        cout<<0;
    }else{
        cout<<x/lowest-1;
    }

   return 0;
}
