// 20L-0961      Ammar Ahmed     HW-004 //
#include <iostream>
using namespace std;

class A {
    int n1, n2, n3;
public:
    /*A() {
        n1 = 5;
        n2 = 6;
        n3 = 7;
        cout << "Non parameterized programmer-defined Constructor\n";
    }
    */
    void setn1(int in) {
        n1 = in;
    }

    void setnn2(int in) {
        n2 = in;
    }

    void setn3(int in) {
        n3 = in;
    }

    int getn1() {
        return n1;
    }

    int getn2() {
        return n2;
    }

    int getn3() {
        return n3;
    }

    A(int val1, int val2, int val3) {
        n1 = val1;
        n2 = val2;
        n3 = val3;
        cout << "Parameterized constructor\n";
    }
};

int main() {
    int v1, v2, v3;
    cout << "Enter three values: ";
    cin >> v1 >> v2 >> v3;
    A obj1(v1, v2, v3);
    // Goal of the homework, when parameterized constructor is invoked, default also needs to exist, thus the error
    // in other words, problem can be solved by removing the parameterized constructor
    A obj2;
    /*
     * obj3 will not be made here as default is always called with non-parenthesis
    A obj3();Cc
     */
    return 0;
}