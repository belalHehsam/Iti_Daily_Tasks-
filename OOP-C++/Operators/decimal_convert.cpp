#include <iostream>

//using namespace std;

int main()
{
    int num ;
    std::cout<<"Enter the Number"<<std::endl;
    std::cin>>num;
    std::cout << "Hexadecimal " << std::hex << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;
    return 0;
}
