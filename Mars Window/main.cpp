#include <iostream>

using namespace std;

int main()
{
    int y;
    cin>>y;
    int year=2018,month=4,i=0;
    while(year<=y){
        //cout<<year<<" "<<month<<" "<<year-2016<<endl;
        if(year==y){
            cout<<"yes";
            return 0;
        }
        month+=2;
        if(month>12){
            month=month%12;
            year++;
        }
        year+=2;
    }
    cout<<"no";


    return 0;
}
