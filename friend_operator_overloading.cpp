#include <iostream>
 using namespace std;
class B
{
private:
    int x;
public:
//    explicit B(int _x):x(_x){} // old stule manually
    B(int _x):x(_x){} // automatically
    
    //10 < b
    friend bool operator <( int val, const B &b)
    {
        return (val < b.x);
    }
    
    // b < 10
    friend bool operator <( const B &b , int val)
    {
        return (b.x < val);
    }
    
    // (14 > b)
    friend bool operator >(int val, const B& b)
    {
        return(val>b.x);
    }
    friend bool operator > (const B& b, int val)
    {
        return (b.x > val);
    }
    
 };


int main()
{
     B b = 5;
     if(10<b)
         cout << "Larger";
     else if(b<10)
         cout << "Smaller";
     else
         cout << "Nothing";
    
    if (14 > b)
        cout << "true" << endl;
    else if  (b > 121)
        cout << "flase " << endl;
    
    return 0;
 }
