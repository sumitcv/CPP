#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/* Template to make it free from dependancy  of any datatype */
template <typename T>

/* convert from any data type to string */ 
string itos(T i)
{
    stringstream ss;
    ss << i;
    return  ss.str();
}
int main()
{
    float i = 155.4;
    string s = itos(i); 
    cout << s << endl; 
    return 0;
}
