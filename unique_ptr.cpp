#include <iostream> 

using std::cout ; 
using std::endl ; 


class Integer
{
    int *m_ptr;

    public:
    Integer() 
    {
        cout << "Integer :  Constructor" << endl;
        m_ptr =  new int(0);
    }
    Integer(int value) 
    {
        cout << "Integer :  Constructor(one Arguments)" << endl;
        m_ptr =  new int(value);
    }

    void Display() noexcept 
    { 
        if(m_ptr)
        {
            cout << "Value :" << m_ptr << endl; 
        }
    }
    ~Integer()
    {
        // cout << "~Integer() - Destructor called" << endl;
        
        delete m_ptr ;
        m_ptr =  nullptr; 
    }
    // Copy Constructor
    // Allocate & Initialize: नई मेमोरी बुक करें और उसमें other की वैल्यू डाल दें।
    Integer(const Integer& other)
    {
        cout << "Integer copy constructor"  << endl ;
        m_ptr = new int(*other.m_ptr);
    }

    
    // Overloaded Assignment operaotr 
    /*
    Sequence (4 Steps - याद रखें: C-D-A-R):
    C - Check (Self-Assignment): क्या मैं खुद को ही कॉपी कर रहा हूँ? if (this == &other)
    D - Delete (Cleanup): पुराने पॉइंटर की मेमोरी खाली करें। delete m_ptr;
    A - Allocate (Deep Copy): नई मेमोरी बुक करें और वैल्यू डालें। m_ptr = new int(*other.m_ptr);
    R - Return: खुद को वापस करें। return *this;
*/
    Integer& operator= (const Integer& other)
    {
        cout << "Integer : Copy Assignment Operaotr " << endl;
        if(this == &other )
            return *this ;
        delete m_ptr;
        m_ptr = new int(*other.m_ptr);
        return *this; 
    }

// Move Constrructor; 
/*
याद रखने का तरीका (Visualizing the Logic)
इसे ऐसे सोचें:
Move Constructor: आप एक नया घर (this) बना रहे हैं।
Transfer: आपने पुराने घर (other) की चाबियाँ ले लीं (m_ptr = other.m_ptr).
Safety: अब आप पुराने मालिक के हाथ से चाबी छीनकर (यानी उसे nullptr करके) उसे बाहर कर रहे हैं, ताकि वह गलती से भी उस घर का दरवाज़ा न खोल सके (या घर गिरा न सके)।
लाइन,आपका कोड,सही कोड,परिणाम

*/
    Integer(Integer&& other) noexcept
    {
        cout << "Integer : Copy  Mmove Constructor;" << endl;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

// Step to create move assignment operator. 
//  Check	    if (this == &other) 	खुद को मूव करने से बचने के लिए।
//  Delete	    delete m_ptr;	        Memory leak रोकने के लिए।
//  Transfer	m_ptr = other.m_ptr;	Ownership लेने के लिए।
//  Nullify	    other.m_ptr = nullptr;	"Dangling Pointer" और डबल डिलीट से बचने के लिए।

    Integer& operator= (Integer&& other) noexcept
    {
        cout << "Move assignment operator is called." << endl;
        if(this == &other)
            return *this;
        delete m_ptr ;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this; 
    }

};
int main()
{
    Integer a(10);  // Constructor 
    Integer b(a);  // constructor
    Integer c(std::move(a));  // Move Copy Constructor 
    Integer d; // Constructor ;
    Integer ii = b; // Copy COnstructor;
    d = b;  // Copy Assignment Operator 
    d = std::move(c); // Move ssignment opetratr


    std::unique_ptr<Integer> i = std::make_unique<Integer> ();
    
    cout << i.get() << endl; //  return the pointer addrss
    i.reset();
    cout << i.get() << endl; //  return the pointer addrss
    std::unique_ptr<Integer> iii ;
    iii.reset();
    iii = std::make_unique<Integer>(100);


    return 0;
}
