#include <iostream>

using namespace std;

int compare(string,string);

int main()
{
    int n,x;
    cin>>n;
    string pre,cur;
    bool flag=true;
    cin>>pre;
    for(int i=1;i<n;i++){
        cin>>cur;
        if(i==1){
            x=compare(pre,cur);
        }else{
            if(compare(pre,cur)!=x){
                flag=false;
            }
        }
        pre=cur;
    }
    if(!flag){
        cout<<"NEITHER"<<endl;
    }else{
        if(x>0){
            cout<<"INCREASING"<<endl;
        }else{
             cout<<"DECREASING"<<endl;
        }
    }

    return 0;
}


int compare(string a,string b){
    for(int i=0;i<a.length()||i<b.length();i++){
        if((int)a[i]!=(int)b[i]){
            if((int)b[i]>(int)a[i]||a[i]=='\0'){
                return 1;
            }else if((int)b[i]<(int)a[i]||b[i]=='\0'){
                return -1;
            }
        }
    }
    return 0;
}
