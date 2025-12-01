/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include<span>
#include <array>
using namespace std;
void change(span<int>all) ;

int main()
{

    array<int,6> arr={1,2,3,4,5,6};

    change(arr);

    for(int num :arr){
        std::cout << num << std::endl;
    }
    return 0;
}

void change(span<int>all){

            int half=(int)all.size()/2;
            span<int> part1;
            span<int> part2;

    if( (all.size()) % 2 == 1 ){
        part1=all.subspan(0,(int)all.size()/2 );
        part2=all.subspan( (int) all.size()/2 , (int)(all.size()/2)+1 );
    }
    else
    {
       part1=all.subspan(0,(int)all.size()/2 );
       part2=all.subspan( (int) all.size()/2 , (int) all.size()/2 );
    }


    for(auto &x:part1){
            x=1;
    }

    /*
    for(int i=0 ;i<all.size();i++){
        all[i]=0;
        if(i>=half){
             all[i]=1;
        }

    }
    */
}
