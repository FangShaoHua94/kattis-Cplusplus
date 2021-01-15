#include <iostream>

using namespace std;

int main()
{
    int y=5,arr[13]={0};
    char x;

    while(y--){
        cin>>x;
        switch(x){
        case 'A':
            arr[0]++;
            break;
        case 'T':
            arr[9]++;
            break;
        case 'J':
            arr[10]++;
            break;
        case 'Q':
            arr[11]++;
            break;
        case 'K':
            arr[12]++;
            break;
        default:
            arr[x-'0']++;
        }
        cin>>x;
    }
    int max=arr[0];
    for(int i=1;i<13;i++){
        max=max>arr[i]?max:arr[i];
    }
    cout<<max;
    return 0;
}
