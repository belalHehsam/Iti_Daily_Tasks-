#include <iostream>
#include<string>
using namespace std;

class Complex {
    private:
        float real{1.0};
        float imag{1.0};
    public:
         static int totalCreated;
         static int ActiveObjects;

        Complex()=default;

        Complex(float r):real(r),imag(0){

          cout<<"The Constructor With One Paramter Called " <<endl;
            totalCreated++;
            ActiveObjects++;
            cout << "Object ID = " << totalCreated << endl;
        }
        Complex(float r,float m):real(r),imag(m){
           cout<<"The Constructor With Two Paramter Called " <<endl;
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

        //overLoad +
            Complex operator + (Complex &c){
                Complex reslut;
                reslut.real= this->real+c.real;
                reslut.imag= this->imag+c.imag;
                return reslut;
        }
         //overLoad -
            Complex operator - (Complex &c){
                Complex reslut;
                reslut.real= this->real-c.real;
                reslut.imag= this->imag-c.imag;
                return reslut;
        }
          //overLoad *
            Complex operator * (Complex &c){
                Complex result;
                result.real = real * c.real - imag * c.imag;
                result.imag = real * c.imag + imag * c.real;
                return result;
        }
        //overLoad *
            Complex operator / (Complex &c){
                Complex result;
                float denominator = c.real * c.real + c.imag * c.imag;
                result.real = (real * c.real + imag * c.imag) / denominator;
                result.imag = (imag * c.real - real * c.imag) / denominator;
                return result;
        }
        //overLoad >
            bool operator >(Complex &c){
                if((this->real > c.real) && (this->imag >c.imag))
                    return 1;
                else
                    return 0;
        }
        //overLoad <
            bool operator <(Complex &c){
                if((this->real < c.real) && (this->imag <c.imag))
                    return 1;
                else
                    return 0;
        }
        //overload ++c;
            Complex &operator++(){
                    this->real++;
                    return *this;
            }
            //post
            //we can't return & because we must return the old version before the increment
            Complex operator++(int){
                    Complex temp= *this;
                    this->real++;
                    return temp;
            }

            //type casting to int
            operator int(){
                return real;
            }

            //overload <<
           friend ostream & operator <<(ostream & out, Complex &c);

            //overload >>
            friend istream &operator >>(istream &in ,Complex &c);

    ~Complex(){
            cout<<"The Destructor Called "<<endl;
            ActiveObjects--;
        }

};
    ostream & operator <<(ostream & out, Complex &c){
                out << c.real << " + " << c.imag << "i";
                return out;
    }

    istream &operator >>(istream &in ,Complex &c){
             in >> c.real >> c.imag;
    return in;
    }


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

    Complex c1;
    Complex c2(3);
    Complex c3(3.7, 4);
    cout << "\n=== Testing Arithmetic Operators ===" << endl;
    Complex sum = c2 + c3;
    cout << "Sum = ";
    sum.printComplex();

    Complex diff = c3 - c2;
    cout << "Difference = ";
    diff.printComplex();

    Complex mul = c2 * c3;
    cout << "Multiplication = ";
     mul.printComplex();

    Complex div = c3 / c2;
    cout << "Division = ";
    div.printComplex();

    cout << "\n=== Testing Relational Operators ===" << endl;
    if (c3 > c2)
        cout << "c3 is greater than c2" << endl;
    else
        cout << "c3 is NOT greater than c2" << endl;

    cout << "\n=== Testing Increment Operators ===" << endl;
    cout << "Before ++c2: "; c2.printComplex();
    ++c2;
    cout << "After ++c2 (prefix): "; c2.printComplex();

    c2++;
    cout << "After c2++ (postfix): "; c2.printComplex();

    cout << "\n=== Testing Type Casting ===" << endl;
    int realPart = (int)c3;
    cout << "Casting c3 to int gives: " << realPart << endl;

    cout << "\n=== Counters ===" << endl;
    c3.showCounter();

    cout << "\n=== End of Main ===" << endl;


    Complex ss;
    cout<<"Enter the Values of Ss"<<endl;
    cin>>ss;

    cout<<ss<<endl;

    return 0;
}
