// ascii -  "1546" -> 1546 

#include <iostream>
using std::cout;
using std::endl;

int myatoi(char * s)
{
	int res = 0; // initialilation result 
	int sign = 1 // initialize sign as +ve; 
	int i = 0; 
	
	if(s[0] == '-')
	{
		sign = -1; 
		i++;
	}
	
	for(; str[i] != '\0' ; ++i)
	{
		res = res * 10 + str[i] - '0';
	}
	return sign*res; 
}

int main()
{
	char str[] = "-1234";
	int val = myAtoi(str);
	cout << "converted  : " << val << endl; 
	
}