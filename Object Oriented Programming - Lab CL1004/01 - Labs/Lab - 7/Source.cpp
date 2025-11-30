#include <iostream>
#include <cmath>
using namespace std;

// NOT CHANGING
class Complex
{
private:
    int real;
    int imaginary;
public:
    Complex(int, int); //with default arguments
    ~Complex(); //Does Nothing.
    void Input();
    void Output();
    bool IsEqual(Complex);
    Complex Conjugate();
    Complex Add(Complex);
    Complex Subtract(Complex);
    Complex Multiplication(Complex);
    float Magnitude();

    friend istream& operator>>(istream& in, Complex& obj) {
        // Prompt the user for the real.
        cout << "Enter the real part: ";
        in >> obj.real;
        // Prompt the user for the imaginary.
        cout << "Enter the imaginary part: ";
        in >> obj.imaginary;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& obj) {
        if (obj.imaginary <= 0)
            if (obj.imaginary == -1)
                out << obj.real << "-i\n";
            else {
                if (obj.real == 0 && obj.imaginary == 0)
                    out << obj.real << "\n";
                else
                    out << obj.real << obj.imaginary << "i\n";
            }
        else if (obj.imaginary == 1)
            out << obj.real << "+i\n";
        else
            out << obj.real << "+" << obj.imaginary << "i\n";
        return out;
    }

    Complex operator+(const Complex& in) {
        Complex A(0,0);
        A.real = real + in.real;
        A.imaginary = imaginary + in.imaginary;
        return A;
    }

    Complex operator-(const Complex& in) {
        Complex S(0,0);
        S.real = real - in.real;
        S.imaginary = imaginary - in.imaginary;
        return S;
    }

    Complex& operator=(const Complex& rhs) {
        real = rhs.real;
        imaginary = rhs.imaginary;
        return *this;
    }

    bool operator==(const Complex& rhs) const {
        if ((real == rhs.real) && (imaginary == rhs.imaginary))
            return true;
        else
            return false;
    }

    bool operator!=(const Complex& rhs) const{
        if ((real != rhs.real) && (imaginary != rhs.imaginary))
            return true;
        else
            return false;
    }
};

Complex::Complex(int r = 0, int i = 0) {
    real = r;
    imaginary = i;
}

Complex::~Complex(){

}

void Complex::Input() {
    cout << "Enter Real:\t";    cin >> real;
    cout << "Enter Imaginary:\t";   cin >> imaginary;
}

void Complex::Output() {
    if (imaginary <= 0)
        if (imaginary == -1)
            cout << real << "-i\n\n";
        else
            cout << real << imaginary << "i\n\n";
    else if (imaginary == 1)
        cout << real << "+i\n\n";
    else
        cout << real << "+" << imaginary << "i\n\n";

}

bool Complex::IsEqual(const Complex in) {
    if (in.real == real && in.imaginary == imaginary)
        return true;
    else
    return false;
}

Complex Complex::Conjugate() {
    Complex C;
    C.real = real;
    C.imaginary = -imaginary;
    return C;
}

Complex Complex::Add(const Complex in) {
    Complex A;
    A.real = real + in.real;
    A.imaginary = imaginary + in.imaginary;
    return A;
}

Complex Complex::Subtract(const Complex in) {
    Complex S;
    S.real = real - in.real;
    S.imaginary = imaginary - in.imaginary;
    return S;
}

Complex Complex::Multiplication(const Complex in) {
    Complex M;
    M.real = real * in.real - imaginary * in.imaginary;
    M.imaginary = real * in.imaginary - in.real * imaginary;
    return M;
}

float Complex::Magnitude() {
    return sqrt(real * real) + sqrt(imaginary * imaginary);
}

int main()
{
    Complex C1;
    Complex C2(5,6);
    Complex C3;
    cout<<"Input a complex number"<<endl;
    cin>>C3;
    cout<<C1<<C2<<C3;
    if(C1==C2)
        cout<<"C1 == C2"<<endl;
    else
        cout<<"C1 != C2"<<endl;
    if(C1!=C3)
        cout<<"C1 != C3"<<endl;
    else
        cout<<"C1==C3"<<endl;
    Complex C4= C2 - C3;
    cout<<C4;

    return 0;
}