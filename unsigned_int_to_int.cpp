// Code to convert unsigned int to integer  value

#include <limits>   
#include <stdexcept>

int SizeToInt(unsigned int u);
int main()
{
    unsigned int uu = 4294967295;
    int  i = SizeToInt(uu);
    return 0;
}
int SizeToInt(unsigned int u)
{
    if (u > std::numeric_limits<int>::max())
    {
        throw std::overflow_error(
            "size_t value cannot be stored in a variable of type int.");
    }
    return static_cast<int>(u);
}
