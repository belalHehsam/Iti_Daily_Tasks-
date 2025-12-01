#include <iostream>

using namespace std;
class Stack{
 private:
        int * ptr;
        int top;
        int size;
 public:
         static int counter;
    Stack(){
        top =0;
        size=10;
        ptr= new int[10];
        counter++;
    }

    Stack(int value){
         top=0;
         size=value;
         ptr=new int[value];
         counter++;

    }
     Stack & push(int value){
            if(top==size){
                cout<<"The Stack Is Full";
            }
            else{
                ptr[top]=value;
                top++;
            }
            return *this;
    }

    Stack &pop(){
        int retrival=0;
        if(!top)
            cout<<"Empty";
        else
        {
            top--;
            cout<<"The Value that deleted  is :"<<ptr[top]<<endl;
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

    ~Stack(){
        delete[] ptr;
    }
};
int Stack::counter=0;

int main()
{
    Stack s1(5);
    Stack s2(5);

    s1.push(30).push(20).push(10).pop().showsElemetns();

    Stack::display();
     return 0;
}
