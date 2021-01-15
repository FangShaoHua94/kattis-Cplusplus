#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
    int n,k,maxc=0;
    cin>>n>>k;
    queue <int> time;
    for(int i=0;i<n;i++){
        int now;
        cin>>now;
        if(i!=0&&time.front()+1000<=now){
            time.pop();
        }
        time.push(now);
        maxc=maxc>time.size()?maxc:time.size();

    }
    cout<<ceil(1.0*maxc/k);

    return 0;
}
