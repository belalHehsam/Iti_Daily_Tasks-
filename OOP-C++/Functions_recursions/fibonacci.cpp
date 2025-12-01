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
int fib(int n);
int main()
{
    cout<<fib(5);
    
    return 0;
}
int fib(int n){
    if(n<=1)
        return 1;
        return fib(n-1)+fib(n-2);
}
