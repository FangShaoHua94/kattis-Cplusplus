#include <iostream>

using namespace std;

void shift(int dir,int arr[4][4]);
void rotateanti(int arr[4][4]);
void rotateclock(int arr[4][4]);
void join(int arr[4]);
void sortrow(int arr[4]);
void sortz(int arr[4][4]);

int main()
{
    int arr[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    int dir;
    cin>>dir;
    shift(dir,arr);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

void shift(int dir,int arr[4][4]){
    switch(dir){
case 0:
    sortz(arr);
    break;
case 1:
    rotateanti(arr);
    sortz(arr);
    rotateclock(arr);
    break;
case 2:
    rotateanti(arr);
    rotateanti(arr);
    sortz(arr);
    rotateclock(arr);
    rotateclock(arr);
    break;
case 3:
    rotateanti(arr);
    rotateanti(arr);
    rotateanti(arr);
    sortz(arr);
    rotateclock(arr);
    rotateclock(arr);
    rotateclock(arr);
    break;
    }
}

void sortz(int arr[4][4]){
    for(int i=0;i<4;i++){
        sortrow(arr[i]);
        join(arr[i]);
        sortrow(arr[i]);
    }

}

void sortrow(int arr[4]){
    for(int i=0;i<3;i++){
        if(!arr[i]){
            for(int j=i+1;j<4;j++){
                if(arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    break;
                }
            }
        }
    }

}

void join(int arr[4]){
    for(int i=0;i<3;i++){
        if(arr[i]&&arr[i]==arr[i+1]){
            arr[i]*=2;
            arr[i+1]=0;
        }
    }
}

void rotateanti(int arr[4][4]){
    for(int i=0;i<2;i++){
        for(int j=i;j<3-i;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][3-i];
            arr[j][3-i]=arr[3-i][3-j];
            arr[3-i][3-j]=arr[3-j][i];
            arr[3-j][i]=temp;
        }
    }
}

void rotateclock(int arr[4][4]){
    for(int i=0;i<2;i++){
        for(int j=i;j<3-i;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[3-j][i];
            arr[3-j][i]=arr[3-i][3-j];
            arr[3-i][3-j]=arr[j][3-i];
            arr[j][3-i]=temp;
        }
    }
}
