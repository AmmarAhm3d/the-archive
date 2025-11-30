#include <iostream>
using namespace std;

template<class T>
void performOperation(T a, T b, char op){
    if (op == '*')
        cout << a * b << endl;
    else {
        if (op == '+')
            cout << a + b << endl;
        else if (op == '-')
            cout << a - b << endl;
        else if (op == '/')
            cout << a / b << endl;
    }
}

int main()
{
    int a, b; // this can be float, int or double too
    char op;
    cout << "Enter first operand ";
    cin >> a;
    cout << "Enter second operand ";
    cin >> b;
    cout << "Enter operation ";
    cin >> op; // op can be +, -, * or /
    if (op == '*' || op == '+' || op == '-' || op == '/')
    {
        performOperation(a, b, op);
    }
    else
    {
        cout << "Wrong operation";
    }

    return 0;
}