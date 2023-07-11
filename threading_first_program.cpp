#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;
typedef unsigned long long ull;
 ull oddSum = 0;   ull evenSum = 0;
void findEven(ull start, ull end)
{
    cout << "thread findEven \n" << endl;
    for (ull i = start ; i <= end; ++i)
    {
        if((i%2)== 0)  { evenSum = evenSum + i; }
    }
}
void findOdd(ull start, ull end)
{
    cout << "thread findOdd\n " << endl;
    for (ull i = start; i <= end ; ++i)
    {
        if(( i % 2) != 1) { oddSum = oddSum+i; }
    }
}
int  main()
{
    ull start = 0; ull end = 1900000000;
    auto startime = high_resolution_clock::now();
    
    // thread is created.
    thread t1(findOdd, start,  end) ;
    thread t2(findEven, start, end);
    t1.join();
    t2.join();
    auto stoptime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stoptime - startime);
    cout <<"Total time taken : " <<  duration.count()/1000000 << endl;
    return 0;
}
