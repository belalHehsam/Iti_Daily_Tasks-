#include <iostream>
#include<array>
#include<windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
using namespace std;

struct employee{
    int id;
    string name;
    int salary;
    int age;

};

int main()
{
     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    int size;
    cout << "enter number of employees ";
    cin>>size;

    employee employees[size] ;


    if(size <1)
    {
        cout<<"you entered a not valid number";
    }
    for(int i=0 ;i < size ;i++){
       system("cls");
    cout << "\033[1;1H" << "emp " << i+1<<":\n";
    cout << "\033[2;4H" << "Id:\n";
    cout << "\033[2;" << 8 * 4 << "HAge:\n";
    cout << "\033[3;" << 8 * 4 << "HName:\n";
    cout << "\033[3;4H" << "Salary:\n";

    cout << "\033[5;7H";
    cin>> employees[i].id;
/*
    cout << "\033[3;11H";
    cin>> employees[i].salary;


    cout << "\033[2;36H";
    cin>> employees[i].age;

    cout << "\033[3;38H";
    cin>> employees[i].name;


    }

       for(int i=0;i<size;i++){
        cout<<employees[i].id<<endl;
        cout<<employees[i].name<<endl;
        cout<<employees[i].age<<endl;
        cout<<employees[i].salary<<endl;

}
*/

return 0;
}}

























