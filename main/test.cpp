#include<iostream>
using namespace std;

class Base
{
public:
    virtual void show() { cout<<" In Base \n"; }
    virtual void find(){}
};

class Derived: public Base
{
public:
    virtual void show() { cout<<"In Derived \n"; }
    using Base::find;
    virtual void find(int a) {cout <<"find \n";}
};

int main(void)
{
    Base *bp = new Derived;
    bp->show();

    Derived* boy = dynamic_cast<Derived*>(bp);
    boy->find(1);
    return 0;
}
