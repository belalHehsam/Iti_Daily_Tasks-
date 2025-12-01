#include <iostream>
#include "car.h"
using namespace std;
int sum(int num1,int num2);
int sum(float num1,int num2);
int sum(int num1 , int num2,int num3);

int main()
{
/*
    cout << sum(2, 3) << endl;
    cout << sum(200, 30) << endl;
    cout << sum(1, 2, 3) << endl;
    */

    return 0;
}

int sum(int num1,int num2){

    return num1+num2;
}

double sum(double num1,double num2){
        return num1+num2;
}

int sum(int num1 , int num2,int num3){
            return num1+num2+num3;
}
