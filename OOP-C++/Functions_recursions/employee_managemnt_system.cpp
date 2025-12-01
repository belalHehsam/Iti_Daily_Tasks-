#include <iostream>
#include <string>
#include <array>
#include<windows.h>
#include<conio.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
using namespace std;
void Menu();
void newEmp();
void display();
void displayAll();
    struct Employee {
        string name;
        int age;
        int salary;
        int id;
    };
array<Employee, 4> employees;

int indexes[4]={0};

int main()
{

        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);

    Menu();
   return 0;

}
void Menu(){
     int curr=0;
     char key;
     array<string,4>menu={"New","Display","Display All","Exit"};
     while(true){
        system("cls");
        cout << "---Employee Form---\n";
        for(int i=0;i<menu.size();i++){
            if(menu.at(curr)==menu.at(i))
             cout << "\033[31m> " << menu.at(i) << "\033[0m\n";
             else cout<<menu.at(i)<<endl;
        }
        key=_getche();
        if(key==-32){
            key=_getch();
             if (key==72){
                    curr--;
                    if(curr<0) curr=menu.size()-1;
             } //up
            else if (key == 80){
             curr++; //down
              if( curr> menu.size()-1) curr=0;
            }
        }
        else if(key==13){
            system("cls");
            if(curr==(int)menu.size()-1)
            {
                 cout<<"Existing...";
                  break;
            }
           else {
                    if(curr==0) newEmp();
                    else if(curr==1) display();
                    else if(curr==2) displayAll();
                    cout << "Press any key to return to the menu"<<endl;
                    _getch();
                }
             }
     }
}

void newEmp(){
    system("cls");
    int index;
    cout<<"Enter the index of Employee from 0-3:"<<endl;
    cin>>index;

    if(index < employees.size()){
        indexes[index]=1;
        system("cls");
        cout << "\033[1;1H" << "emp " <<":\n";
        cout << "\033[2;4H" << "Id:\n";
        cout << "\033[2;" << 8 * 4 << "HAge:\n";
        cout << "\033[3;" << 8 * 4 << "HName:\n";
        cout << "\033[3;4H" << "Salary:\n";

        cout << "\033[2;7H";
        cin>> employees[index].id;

        cout << "\033[3;11H";
        cin>> employees[index].salary;

        cout << "\033[2;36H";
        cin>> employees[index].age;

        cout << "\033[3;38H";
        cin>> employees[index].name;
        cout<<"The Employee Added Successful.."<<endl;
    }
    else
        cout<<"not valid position"<<endl;
}

void display(){
    system("cls");
    int index;
    cout<<"Enter the Index Of Employee from 0-3 :"<<endl;
    cin>>index;
    if(index>=employees.size()){
        cout<<"Not Valid Index"<<endl;
    }
    else{
            if(indexes[index]==1){
                    system("cls");

                     cout << "\033[1;1H" << "emp " <<":";
                     cout << "\033[2;4H" << "Id: "<<employees.at(index).id;
                     cout << "\033[2;" << 8 * 4 << "HAge: "<<employees.at(index).age;
                     cout << "\033[3;" << 8 * 4 << "HName: "<<employees.at(index).name;
                     cout << "\033[3;4H" << "Salary: "<<employees.at(index).salary <<endl;
                      cout<<"Please Enter Any Key.."<<endl;
            }
            else
                cout<<"not employee in this position"<<endl;
    }
}

void displayAll() {
    system("cls");
    int printed = 0;
    for (int i = 0; i < employees.size(); i++) {
        if (indexes[i] == 1) {
            int baseRow = 1 + (printed * 4);
            cout << "\033[" << baseRow     << ";1H" << "emp " << i + 1 << ":";
            cout << "\033[" << baseRow + 1 << ";4H" << "Id: " << employees.at(i).id;
            cout << "\033[" << baseRow + 1 << ";" << 8 * 4 << "HAge: " << employees.at(i).age;
            cout << "\033[" << baseRow + 2 << ";4H" << "Name: " << employees.at(i).name;
            cout << "\033[" << baseRow + 2 << ";" << 8 * 4 << "HSalary: " << employees.at(i).salary;

            cout << "\033[" << baseRow + 3 << ";1H"
                 << "======================================================" << endl;

            printed++;
        }
    }
}



