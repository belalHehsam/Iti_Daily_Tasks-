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
void decimalToBinary(int n);
int main()
{
    int num;
    std::cout << "Enter the Number" << std::endl;
    std::cin >> num;
    decimalToBinary(num);
    return 0;
}

void decimalToBinary(int n){
    if(n==0)
        return;
        decimalToBinary(n/2);
        std::cout << n%2 ;
}
