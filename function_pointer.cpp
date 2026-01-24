/*
syntax -
Declaration- 
return_type  (*funciton_pointer_variable) (argument1, arguments2)  = function_name;
return_type  (*funciton_pointer_variable) (argument1, arguments2)  = &function_name;

calling- 
auto return_variable = funciton_pointer_variable(argument1, argument2);
auto return_variable = *funciton_pointer_variable(argument1, argument2);
*/

// example

#include <iostream> 
void print_hello()
{
	std::cout << "Hello world" << std::endl; 
}

void end_program()
{
	std::cout << "ending of program" << std::endl;
}
int main()
{
	// At exit will be always called right before exit the function
	// also a function pointer is required. 
	
	atexit(end_program); // use of funciton_pointer;

	void (*funciton_pointer) () = print_hello; // function pointer declaration and assign 
	
	funciton_pointer(); // function pointer calling. 	
	
	return 0;
}

