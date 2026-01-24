/*

============== L-Value and R-Value ============== 

	L-Value 
		- Has a name
		- Can be assign 
		- Variables are l value. 
		- return by reference . 
	
	R-Value
		- no name
		- cannot be assign int 10 = 11 ; X
		- return by value. 		

int x = 10;
where- 
	x - L value
	10 - R valie;

(x+y) -z = return R-value
++x = return Lvalue

============== return by reference and value. ============== 	
return by value- R value;
return by Reference - L value;
ex - 
int calculation()
{
	return 10; // R-Value return
}

int& calculaiton()
{
	return 10; // L-Value return
}
*/

// example-  

#include <iostream>
double  getPI()
{
	return 3.14; //R- value is returned 
}

int& incrementByTwo(int& x)
{
	x = x +2;
	return x; // L-Value is return 
}


int main()
{
	int i = 12;
	int x  = incrementByTwo(i);
	std::cout << x << std::endl;
	return 0;
}



