#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

class Base
{
private:
    int a, b;

public:
    void setA(int n) { a = n; }
    void setB(int n) { b = n; }
    int getA() { return a; }
    int getB() { return b; }

public:
    Base() : a(0), b(0) {}

    Base(int n1, int n2) : a(n1), b(n2) {}

    int calcSum()
    {
        return a + b;
    }
};

class Derived : public Base
{
private:
    int c;

public:
    Derived() : Base(), c(0) {}

    Derived(int n) : Base(n, n), c(n) {}

    Derived(int n1, int n2, int n3) : Base(n1, n2), c(n3) {}

    void setC(int n) { c = n; }
    int getC() { return c; }

   int calcSum()
    {
        return Base::calcSum() + c;
            //    getA()+getB();
    }

};

int main()
{
    cout << "Hello Inheritance Part 1!" << endl;

    Derived d;
    d.setA(5);
    d.setB(6);
    d.setC(1);

    Derived d1(5);
    Derived d2(5, 6, 4);
    Base b(4, 8);

    cout << "sum of d is: " << d.calcSum() << endl;
    cout << "sum of d1 is: " << d1.calcSum() << endl;
    cout << "sum of d2 is: " << d2.calcSum() << endl;
    cout << "sum of b is: " << b.calcSum() << endl;

    return 0;
}
