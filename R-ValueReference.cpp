// new type of reference in modern c++ is R-Value Reference. 
// rvalue cannot be bind with lvalue 
// rvalue can be bind with rvalue only
 
#include <iostream>

using std::cout;
using std::endl; 

  int& squire(int& s)
 {
	s = s*s;
	return s; 

 }
 
 void Print(int && x)
 {
 	cout << "print(int &&)" << endl; 
 }
 
 int main()
 {
 	int x = 20;
 	cout << squire(x) << endl ;
// 	Print(x);  // rvalue cannot be bind with lvalue. 
 	Print(22); // rvalue can always be bind with rvalue. 
 	
 	return 0;
 }
 
 