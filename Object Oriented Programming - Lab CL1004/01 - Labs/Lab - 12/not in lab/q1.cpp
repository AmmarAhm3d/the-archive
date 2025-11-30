#include <iostream>
using namespace std;

template <class T, int N>
class Sequence {
    T memblock [N];
public:
    void setmember (int x, T value){
       this->memblock[x] = value;
    }
    T getmember (int x){
        return (this->memblock[x]);
    }
};

int main ()
{
    Sequence <int,5> myints;
    Sequence <double,5> myfloats;
    myints.setmember (0,100);
    myfloats.setmember (3,3.1416);
    cout << myints.getmember(0) << '\n';
    cout << myfloats.getmember(3) << '\n';
    return 0;
}