
// Standard new
//Type* ptr = new Type;

// Placement new (कोई नया की-वर्ड नहीं, बस Syntax अलग है)
//Type* ptr = new (address) Type;

#include<iostream>
using namespace std;

class MyClass {
    int l;
public:
    MyClass() { cout << "Constructor Call Hua!" << endl; }
    ~MyClass() { cout << "Destructor Call Hua!" << endl; }
    void setl()
    {
        l = 10;
    }
};

int main()
{
    size_t classSize = sizeof(MyClass);
    char * memory = new char[10*classSize];
    
    MyClass *mc1 = new (&memory[0*classSize]) MyClass();
    MyClass *mc2 = new (&memory[2*classSize]) MyClass();
    MyClass *mc3 = new (&memory[3*classSize]) MyClass();
    MyClass *mc4 = new (&memory[4*classSize]) MyClass();
    MyClass *mc5 = new (&memory[5*classSize]) MyClass();
    
    mc1 -> ~MyClass();
    mc2 -> ~MyClass();
    mc3 -> ~MyClass();
    mc4 -> ~MyClass();
    mc5 -> ~MyClass();
    return 0;
}
