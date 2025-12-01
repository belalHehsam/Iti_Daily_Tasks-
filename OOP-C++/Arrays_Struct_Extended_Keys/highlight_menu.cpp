#include <iostream>
#include <string>
#include <array>
#include<windows.h>
#include<conio.h>
using namespace std;

int main()
{
    int curr=0;
    char key;

     array<string,4>menu={"New","Display","Display All","Exit"};

     while(true){
        system("cls");
        cout << "---Employee Form---\n";
        for(int i=0;i<menu.size();i++){
            if(menu.at(curr)==menu.at(i))
             cout << "\033[31m> " << menu.at(i) << "\033[0m\n";
             else
                cout<<menu.at(i)<<endl;
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

            if(curr==(int)menu.size()-1) {
                cout << "Exiting... (Press 'q' or ESC to confirm exit)\n";
                char key2 = _getch();

                if (key2 == 'q' || key2 == 'Q' || key2 == 27) // 27 = ESC
                {
                    cout << "Goodbye!\n";
                    break;
                }
            }
            else
                cout<<"You are in "<<menu.at(curr)<<endl;


            cout << "Press any key to return to the menu"<<endl;
            _getch();

             }



     }
return 0;

}


