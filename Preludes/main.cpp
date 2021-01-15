#include <iostream>


using namespace std;

int main()
{
    string a,b,c,d;
    int i=1;
    while(cin>>a){
        if(a=="A#"){
            c="Bb";
        }else if(a=="Bb"){
            c="A#";
        }else if(a=="C#"){
            c="Db";
        }else if(a=="Db"){
            c="C#";
        }else if(a=="D#"){
            c="Eb";
        }else if(a=="Eb"){
            c="D#";
        }else if(a=="F#"){
            c="Gb";
        }else if(a=="Gb"){
            c="F#";
        }else if(a=="G#"){
            c="Ab";
        }else if(a=="Ab"){
            c="G#";
        }else{
            c="UNIQUE";
        }
        cin>>d;
        if(c=="UNIQUE"){
            cout<<"Case "<<i<<": "<<c<<endl;
        }else{
            cout<<"Case "<<i<<": "<<c<<" "<<d<<endl;
        }
        i++;
    }
    return 0;
}
