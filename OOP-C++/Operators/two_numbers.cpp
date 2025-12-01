#include <iostream>

//using namespace std;

int main()
{

    int sum,diff,num1,num2;
    float avg;

    std::cout<<"Enter Num1"<<std::endl;
    std::cin>>num1;

    std::cout<<"Enter Num2"<<std::endl;
    std::cin>>num2;

    sum=num1+num2;
    diff=num1-num2;
    avg=sum/2.0;

    std::cout<<"the Sum is "<<sum<<std::endl;
    std::cout<<"the difference is "<<diff<<std::endl;
    std::cout<<"the average is "<<avg<<std::endl;
    return 0;
}
