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


template<typename T>
class Stack{
    int top;
    int size;
    T *ptr;

public:
     static int counter;
    Stack()=delete;

    Stack(int size=5):top(0),size(size),ptr(new T[size]){counter++;};

    Stack & push(T value){
                if(top==size){
                    cout<<"Stack Full"<<endl;
                }
                else{
                       this->ptr[top]=value;
                       this->top++;
                }
                return *this;
    }

    Stack &pop(){
        if(!top)
            cout<<"The Stack is Empty"<<endl;
        else
        {
            top--;
            cout<<"the value deleted :"<<this->ptr[top]<<endl;
        }
        return *this;
    }


    void showsElemetns(){
        for(int i=0; i<top;i++){
            cout<<ptr[i]<<endl;
        }
    }

    static void display(){
        cout<<"The counter of objects is :"<<counter<<endl;
    }

    //Copy Constructor
    Stack(Stack &other){
        cout << "Copy constructor called" << endl;
        this->top=other.top;
        this->size=other.size;
        this->ptr=new T[size];
        for(T i=0;i<other.top;i++)
            this->ptr[i]=other.ptr[i];
        counter++;
    }

     //move constructor
    Stack(Stack &&other) noexcept{
        cout << "Move constructor called" << endl;
        this->top=other.top;
        this->size=other.size;
      //  this->ptr=new int[size];
        this->ptr=other.ptr;
       // for(int i=0;i<other.top;i++)
         //   this->ptr[i]=other.ptr[i];
        other.top=0;
        other.size=0;
        other.ptr=nullptr;
    }

    //overload = operator copy
    Stack& operator=(Stack & old){
        delete [] this->ptr;
        this->top=old.top;
        this->size =old.size;
        this->ptr = new T[size];
        for(T i =0;i<old.top;i++)
            this->ptr[i]=old.ptr[i];

            return *this;
    }

    //overload = move
      Stack& operator=(Stack && old){
        delete [] this->ptr;
        this->top=old.top;
        this->size =old.size;
        this->ptr = old.ptr;
       /* for(int i =0;i<old.top;i++)
            this->ptr[i]=old.ptr[i];*/

        old.top=0;
        old.size=0;
        old.ptr=nullptr;
            return *this;
    }

    //overload []
    int & operator[] (int i){
            return this->ptr[i];
    }

    ~Stack(){
        cout<<"The Destructor Called"<<endl;
        delete[] ptr;
    }

};
template<typename T>
int  Stack<T>::counter=0;
int main()
{
    Stack<int>s(4);
    s.push(5).push(10).push(12);

    Stack<int>s2(4);
    s2.push(5).push(10).push(12);

    Stack<int>s3(4);
    s3.push(5).push(10).push(12);


    Stack<float>s4(4);
    s4.push(7.6).push(6.4).push(1.23);

   // s2.showsElemetns();
/*

    Complex c1(3, 4);
    Complex c2(7, -2);

    Stack<Complex> s4(5);
    s4.push(c1).push(c2);
    s4.showsElemetns();
*/
    Stack<float>::display();

    return 0;
}
