#include <iostream>
using namespace std;
class A 
{
    private:
        int *p; 
        
    public:
        A(int i);
        ~A(){ delete p; cout << "A :: Destructor " << endl; }
        A(const A&);
        A(A &&); 
        int get_val() { return *p ; }
};



// Construction
A::A(int i)
{
    p = new int;
    *p = i;
    cout << "A :: constructor" << endl; 
}

// Copy Construction defination
A::A(const A &source ) 
{
    this -> p = new int;
    *this -> p = *(source.p);
    cout << "A :: copy constructor" << endl; 
}

// Move Constructor 
A::A(A&& source)
{
    this -> p = source.p;
    source.p = nullptr;
    cout << "A :: Move constructor" << endl;
}

int main() 
{
    vector <A> va;
    va.push_back(A(10));
    return 0;
}
