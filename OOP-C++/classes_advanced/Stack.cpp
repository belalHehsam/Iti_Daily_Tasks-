#include <iostream>

using namespace std;
class Stack{
    int top;
    int size;
    int *ptr;

public:
     static int counter;
    Stack()=delete;

    Stack(int size=5):top(0),size(size),ptr(new int[size]){counter++;};

    Stack & push(int value){
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
        cout<<counter;
    }

    //Copy Constructor
    Stack(Stack &other){
        cout << "Copy constructor called" << endl;
        this->top=other.top;
        this->size=other.size;
        this->ptr=new int[size];
        for(int i=0;i<other.top;i++)
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
        this->ptr = new int[size];
        for(int i =0;i<old.top;i++)
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
int  Stack::counter=0;

int main()
{
    cout << "---- Create s1 ----" << endl;
    Stack s1(5);
    s1.push(10).push(20).push(30);
    s1.showsElemetns();

    cout << "\n---- Test operator[] ----" << endl;
    cout << "s1[1] = " << s1[1] << endl;
    s1[1] = 200;
    cout << "After edit: s1[1] = " << s1[1] << endl;

    cout << "\n---- Copy Constructor ----" << endl;
    Stack s2 = s1;
    s2.push(40);
    cout << "Elements of s2:" << endl;
    s2.showsElemetns();

    cout << "\n---- Move Constructor ----" << endl;
    Stack s3 = Stack(3);
    s3.push(7).push(8);
    s3.showsElemetns();

    cout << "\n---- Copy Assignment ----" << endl;
    s3 = s1;
    cout << "Elements of s3 after = :" << endl;
    s3.showsElemetns();

    cout << "\n---- Move Assignment ----" << endl;
    s3 = Stack(2);
    s3.push(111).push(222);
    s3.showsElemetns();

    cout << "\n---- END PROGRAM ----" << endl;


    return 0;
}
