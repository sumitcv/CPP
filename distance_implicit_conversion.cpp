// Implicit Conversion (Multiple Arguments)
// Member Initializer List
// Friend Function for Encapsulation
// Passing by Reference (const Distance &d):


#include <iostream>

class Distance {
private:
    int distance;
    int speed;

public:
    // Constructor with two arguments
    Distance(int dd, int ss) : distance(dd), speed(ss) {}

    // Friend function to access private members
    // Using 'const &' is good practice to avoid unnecessary copying
    friend void print(const Distance &d) {
        std::cout << "Distance: " << d.distance << ", Speed: " << d.speed << std::endl;
    }
};

int main() {
    // Implicit conversion using curly braces (List Initialization)
    // This calls Distance(10, 20)
    Distance d = {10, 20}; 

    print(d); // Calling the friend function
    
    return 0;
}
