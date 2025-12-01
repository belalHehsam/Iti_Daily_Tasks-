#include <iostream>

//using namespace std;

int main()
{
    char c;
    std::cout<<"Enter The Character"<<std::endl;
    std::cin>>c;
    std::cout<<"The ASCII Code is "<<static_cast<int>(c);
    return 0;
}

