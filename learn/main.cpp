#include <iostream>

using namespace std;

class myclass{

public:
    int x;
    myclass(int val):x(val){}
    const int& get() const{return x;}
    int& get(){return x;}
};

int main()
{
    myclass foo(10);
    const myclass bar(20);
    cout<<foo.x<<endl;
    foo.get()=15;

    cout<<foo.get()<<endl;
    cout<<foo.x<<endl;
    cout<<bar.get()<<endl;
    return 0;
}
