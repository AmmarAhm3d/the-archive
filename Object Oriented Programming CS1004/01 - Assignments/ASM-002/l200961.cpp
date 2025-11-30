#include <iostream>
#include <cmath>
using namespace std;

// GIVEN
class ComplexNumber
{
private:
    int real;
    int imaginary;
public:
    ComplexNumber(int, int); //with default arguments
    ~ComplexNumber(); //Does Nothing.
    void Input();
    void Output();
    bool IsEqual(ComplexNumber);
    ComplexNumber Conjugate();
    ComplexNumber Add(ComplexNumber);
    ComplexNumber Subtract(ComplexNumber);
    ComplexNumber Multiplication(ComplexNumber);
    float Magnitude();
};

ComplexNumber::ComplexNumber(int r = 0, int i = 0) {
    real = r;
    imaginary = i;
}

ComplexNumber::~ComplexNumber(){}

void ComplexNumber::Input() {
    cout << "Enter Real:\t";    cin >> real;
    cout << "Enter Imaginary:\t";   cin >> imaginary;
}

void ComplexNumber::Output() {
    if (imaginary < 0)
        if (imaginary == -1)
            cout << real << "-i" << endl;
        else
            cout << real << imaginary << "i" << endl;
    else if (imaginary == 1)
        cout << real << "+i" << endl;
    else
        cout << real << "+" << imaginary << "i" << endl;

}

bool ComplexNumber::IsEqual(const ComplexNumber in) {
    if (in.real == real && in.imaginary == imaginary)
        return true;

    return false;
}

ComplexNumber ComplexNumber::Conjugate() {
    ComplexNumber conj;
    conj.real = real;
    conj.imaginary = -imaginary;
    return conj;
}

ComplexNumber ComplexNumber::Add(const ComplexNumber in) {
    ComplexNumber add;
    add.real = real + in.real;
    add.imaginary = imaginary + in.imaginary;
    return add;
}

ComplexNumber ComplexNumber::Subtract(const ComplexNumber in) {
    ComplexNumber Sub;
    Sub.real = real - in.real;
    Sub.imaginary = imaginary - in.imaginary;
    return Sub;
}

ComplexNumber ComplexNumber::Multiplication(const ComplexNumber in) {
    ComplexNumber Mult;
    Mult.real = real * in.real - imaginary * in.imaginary;
    Mult.imaginary = real * in.imaginary - in.real * imaginary;
    return Mult;
}

float ComplexNumber::Magnitude() {
    return abs(sqrt(real * real) + sqrt(imaginary * imaginary));
}

int main()
{
    ComplexNumber c1, c2;
    cout << "Enter c1:\n";  c1.Input();

    cout << "Enter c2:\n"; c2.Input();
    cout << "c1 = "; c1.Output(); cout << endl;
    cout << "c2 = "; c2.Output(); cout << endl;

    cout << "c1 is ";

    switch (c1.IsEqual(c2)) {
    case true:
        cout << "Equal to c2.\n";
        break;
    case false:
        cout << "NOT Equal to c2.\n";
        break;
    
    }
    cout << endl;

    cout << "Conjugate of c1: \t";  ComplexNumber conjc1 = c1.Conjugate(); conjc1.Output(); cout << endl;
    cout << "Conjugate of c2: \t";  ComplexNumber conjc2 = c2.Conjugate(); conjc2.Output(); cout << endl;
    cout << "c1 + c2: \t"; ComplexNumber sum = c1.Add(c2); sum.Output(); cout << endl;
    cout << "c1 - c2: \t"; ComplexNumber sub = c1.Subtract(c2); sub.Output(); cout << endl;
    cout << "c1 x c2: \t"; ComplexNumber mult = c1.Multiplication(c2); mult.Output();
    cout << "Magnitude of c1 = " << c1.Magnitude() << endl; cout << endl;
    cout << "Magnitude of c2 = " << c2.Magnitude() << endl; cout << endl;

    return 0;
}