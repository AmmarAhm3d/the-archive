// 20L-0961      Ammar Ahmed     HW-001 //
// WITHOUT CONST KEYWORD //

#include <iostream>
using namespace std;

void func(int*& p) {
    *p = 20;    // In this line  we change value of p, which has been assigned p1 by main
                // which is pointing to the integer value 'a' in main, as a result this solution works
    
    //p = 20;   // We cannot do this command anyways 
                // as pointers only work with addresses  
 
    // As a result this function changes value of a, which is also pointed to 'p1' in main
}

void main()
{
    int a = 10;
    cout << a << endl;
    int* p1 = &a;
    func(p1);
    cout << *p1 << endl;
}