#include <iostream>

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

int Complex::totalCreated=0;
int Complex::ActiveObjects=0;
    ostream & operator <<(ostream & out,Complex &c){

                out << c.real << " + " << c.imag << "i";
                return out;
    }
    istream &operator >>(istream &in ,Complex &c){
             in >> c.real >> c.imag;
    return in;
    }


template<typename T>
T sum(T n1,T n2){
    return n1+n2;
}


int main()
{
    cout<<sum(10,20)<<endl;

    cout<<sum(30.4,20.5)<<endl;

    Complex c1(2.4,5.1);
    Complex c2(10.1,2.2);

    cout<<"the sum of complex is:"<<endl;
    Complex c3= sum(c1,c2);
    cout<<c3<<endl;

    return 0;
}
