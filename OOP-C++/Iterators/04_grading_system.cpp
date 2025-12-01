#include <iostream>

using namespace std;

int main()
{
int grade;
    cout<<"Enter Your Grade"<<endl;
    cin>>grade;

    if(grade <= 100 && grade >= 85)
        cout<<"A";
    else
        if(grade <=84 && grade >= 74)
            cout<<"B";
        else
            if(grade <=73 &&grade>= 60)
                cout<<"C";
             else
                cout<<"F";
    return 0;
}
