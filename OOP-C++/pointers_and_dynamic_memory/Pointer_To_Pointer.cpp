#include <iostream>

using namespace std;

int main()
{
    int x=5;
    int *ptr=&x;
    int **pptr=&ptr;

    cout<<**pptr;

    return 0;
}
