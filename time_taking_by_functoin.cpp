#include <iostream>
#include <thread>
#include <chrono> // this is required header file to use the high_resolution_clock class
#include <algorithm>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;

 ull oddSum = 0;
 ull evenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start ; i <= end; ++i)
    {
        if((i%2)== 0)
        {
            evenSum = evenSum + i;
        }
    }
}
void findOdd(ull start, ull end)
{
    for (ull i = start; i <= end ; ++i)
        if(( i % 2) != 1)
        {
            oddSum = oddSum+i;
        }
   
}
int  main()
{
    ull start = 0; ull end = 1900000000;
    
    auto startime = high_resolution_clock::now(); // your time start now. 
    findEven(start, end);
    findOdd(start, end);
    auto stoptime = high_resolution_clock::now(); // Time up .
    
    auto duration = duration_cast<microseconds>(stoptime - startime); // total time in microseconds
    
    cout << "Odd Sum : " << oddSum << endl;
    cout << "even sum : " << evenSum << endl;
    cout <<"Total time taken : " <<  duration.count()/1000000 << endl;
    
    return 0;
}


/*
output :
Odd Sum : 902500000950000000
even sum : 902500000950000000
Total time taken : 8
Program ended with exit code: 0
*/
