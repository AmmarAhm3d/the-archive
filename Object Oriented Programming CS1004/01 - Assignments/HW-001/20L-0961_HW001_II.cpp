// 20L-0961      Ammar Ahmed     HW-001 //
// WITH CONST KEYWORD //

#include <iostream>
using namespace std;

void func(const int*& p) {
    *p = 20;    // In this line we cannot modify the value of p anyhow, 
                // because of "constant" type qualifier
    
    //p = 20;   // We cannot do this command anyways 
                // as pointers only work with addresses  
 
    // As a result of const overall function is unusable and doesn't build
}

void main()
{
    int a = 10;
    cout << a << endl;
    int* p1 = &a;
    func(p1);
    cout << *p1 << endl;
}