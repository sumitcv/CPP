#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    vector <string> path { "/Users/sumit/Documents/projects/misc_c_cpp/RevisionCpp/RevisionCpp/grepprs_interrupt_1.log",
        "/Users/sumit/Documents/projects/misc_c_cpp/RevisionCpp/RevisionCpp/grepprs_interrupt_2.log",
        "/Users/sumit/Documents/projects/misc_c_cpp/RevisionCpp/RevisionCpp/grepprs_interrupt_3.log",
        "/Users/sumit/Documents/projects/misc_c_cpp/RevisionCpp/RevisionCpp/grepprs_interrupt_4.log",};
    string rline;
    
    for( string ps : path )
    {
        ifstream file(ps);
        if(file.is_open())
        {
            cout << "file is open" << endl;
            while( getline(file , rline))
                cout << "readline: " << rline << endl;
            file.close();
        }
        else
        {
            cout << "error: fail to open file or file not found => path => " << ps << endl;
        }
    }
}
