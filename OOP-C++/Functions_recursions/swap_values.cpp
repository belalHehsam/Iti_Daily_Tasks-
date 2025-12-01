/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include<span>
#include <array>
using namespace std;
void swap(int&num1 , int&num2);
int main()
{
    
    int x=5;
    int y=10;
    cout << "x before swapping is:"<<x << endl;
    cout << "y before swapping is:"<<y <<endl;
    swap(x,y);
    
    cout << "x After swapping is:"<<x << endl;
    cout << "y After swapping is:"<<y <<endl;
    return 0;
}

void swap(int&num1 , int&num2){
    int temp;
    temp=num1;
    num1=num2;
    num2=temp;
}
