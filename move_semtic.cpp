#include<iostream>
using std::cout;
using std::endl;

// make a simple class
//- Constructor 
//- Copy constructor 
// make a Assignment Operator 
//- make a Destructor 
// Make a move Constructor 
// make a modve assign operator. 


class MyClass
{
	private:
		int v;
		int *ptr;
	
	public:
		MyClass()
		{
			cout << " Constructor"  << endl;
			v = 0;
			ptr = new int();
		}
		
		~MyClass ()
		{
			if(ptr != nullptr)
				delete ptr;
		}
		
		MyClass(const MyClass& o): v(o.v)
		{
			cout << "Copy Construcxtor "  << endl;
			if(o.ptr != nullptr)
			{
				ptr = new int(*o.ptr);
			}
			else
			{
				ptr = nullptr;
			}
		}
		MyClass& operator= (const MyClass & o)
		{
			cout << "Assignment opetaore"  << endl;
			v = o.v; 
			delete ptr ;
			
			if(o.ptr != nullptr)
			{
				ptr = new int(*o.ptr);
			}
			else
			{
				ptr = nullptr;
			}
			return *this;
		}
		
		MyClass( MyClass&& o):v(o.v), ptr(o.ptr)
		{
			cout << "Move copy Constructor" << endl;
			o.v = 0;			
			o.ptr = nullptr;			
		}
		
		MyClass& operator = ( MyClass&& o)
		{
		
			cout << "Move Assignment Operator" << endl;
			if (this == &o)
				return *this;
			
			delete ptr;
			
			v = o.v;
			ptr = o.ptr;
			
			o.v = 0;
			o.ptr = nullptr;
			
			return *this; 
		}
};  


int main()
{

	MyClass mc; // 
	MyClass mc1(mc) ; // copy Constructor
	MyClass mmcc = mc; // copy Constructor

	mc1 = mc;
	MyClass mmmccc = std::move(mc); // move 
	mmmccc = std::move(mc);// move assignment operator
	
	return 0; 
}
 