#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        x = 0;
        cout << "A default" << x;
    }
    A(int x_)
    {
        x = x_;
        cout << "A parameter" << x;
    }
    int x;
};

class Point
{
protected:
    A a;

public:
    Point() { A(7); }
};
int main()
{
    Point p;
}