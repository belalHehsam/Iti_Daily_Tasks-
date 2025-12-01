#include <iostream>

using namespace std;

int main()
{
    int num1,num2;
    char c;
        do{
            cout<<"Enter The num1"<<endl;
            cin>>num1;

            cout<<"Enter The num2"<<endl;
            cin>>num2;

            cout<<"select (a) for Add , Select (b) for subtract , Select(c) for Multibly , Select (d) for divide ,Select (E) for Exit"<<endl;
            cin>>c;

            switch(c){
                case 'a':
                    {
                        cout<<"num1+num2 = "<<num1 +num2 <<endl;
                        break;
                    }
                case 'b':
                    {
                        cout<<"num1 - num2 = "<<num1 - num2 <<endl;
                        break;
                    }
                case 'c':
                    {
                        cout<<"num1 * num2 = "<<num1 * num2 <<endl;
                        break;
                    }
                case 'd':
                    {
                        cout<<"num1 / num2 = "<<num1 / num2 <<endl;
                        break;
                    }
                case 'e':
                case 'E':
                    {
                        break;
                    }

                default:
                {
                    cout<<"invalid opertaor"<<endl;
                }

            }

        }while((c!='e') && (c!='E'));

    return 0;
}
