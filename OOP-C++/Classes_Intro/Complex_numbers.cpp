#include <iostream>
#include<string>
using namespace std;

class Complex {
    private:
        float real;
        float imag;
        //  int id;
        // int id = ++counter;
    public:
         static int totalCreated;
         static int ActiveObjects;
        Complex()/*{totalCreated++;ActiveObjects++}*/=default;

        Complex(float r){
          cout<<"The Constructor With One Paramter Called " <<endl;
            real=r;
            imag=0;
            totalCreated++;
            ActiveObjects++;
            cout << "Object ID = " << totalCreated << endl;

        }
        Complex(float r,float m){
           cout<<"The Constructor With Two Paramter Called " <<endl;
            real=r;
            imag=m;
            totalCreated++;
            ActiveObjects++;
            cout << "Object ID = " << totalCreated << endl;
        }

        void showCounter(){
            cout<<"The numbers of Active objects is : "<<ActiveObjects<<endl;
            cout<<"The numbers of all objects is : "<<totalCreated<<endl;
        }

       void printComplex() {
            if (real == 0 && imag == 0) {
                cout << 0 << endl;
            }
            else if (real == 0) {
                if (imag == 1)
                    cout << "i" << endl;
                else if (imag == -1)
                    cout << "-i" << endl;
                else
                    cout << imag << "i" << endl;
            }
            else if (imag == 0) {
                cout << real << endl;
            }
            else {
                cout << real;
                if (imag > 0) {
                    if (imag == 1)
                        cout << "+i" << endl;
                    else
                        cout << "+" << imag << "i" << endl;
                }
                else {
                    if (imag == -1)
                        cout << "-i" << endl;
                    else
                        cout << imag << "i" << endl;
                }
            }
}
/*
    static int getNextID() {
    return ++totalCreated;
}
      */  ~Complex(){
            cout<<"The Destructor Called "<<endl;
            ActiveObjects--;
        }

};

int Complex::totalCreated=0;
int Complex::ActiveObjects=0;

int main()
{
/*
    Complex c1;
    Complex c2(5);

    c1.showCounter();

    {
        Complex c3(8, -2);
        c3.showCounter();
    }
    c1.showCounter();
*/

      cout << "\n=== Testing printComplex() ===\n" << endl;

    Complex c1(5, 7);
    Complex c2(-3, -3);
    Complex c3(0, -8);
    Complex c4(0, 8);
    Complex c5(8, 1);
    Complex c6(0, -9);
    Complex c7(-9, 3);
    Complex c8(8, 1);

    cout << "Results:\n";

    c1.printComplex();
    c2.printComplex();
    c3.printComplex();
    c4.printComplex();
    c5.printComplex();
    c6.printComplex();
    c7.printComplex();
    c8.printComplex();

    cout << "\n";
    c1.showCounter();

    cout << "\n=== End of Program ===\n";


    return 0;
}
