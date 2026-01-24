/*
	locking object to get the address for more security - 
	- ro avoid user should not use the offset of pointer 
	- user should always use smart_pointer to not raw pointer. 
	- user always  use proxy function to access the object. 
	- TIP: std addressof() is the hack you can still get the object address. . .
	
*/

#include<iostream>
using std::cout;
using std::endl;


class MyClass
{
private:
//    MyClass* operator& ()
//    {
//        return this;
//    }
     MyClass* operator&() = delete;
};

int main()
{
    MyClass mc;
    //auto p = &mc;
    // Still we have a way to get the addres s... 

    cout << std::addressof(mc) << endl;
    return 0;
}
