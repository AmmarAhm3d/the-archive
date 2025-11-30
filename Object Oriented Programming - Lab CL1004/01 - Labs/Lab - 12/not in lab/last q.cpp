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

template<class T>
class Pair{
    T values[2];
public:
    Pair(){
        this->values[0]=0, this->values[1]=0;
    }
    Pair(T in1, T in2){
        this->values[0]=in1;
        this->values[1]=in2;
    }
    T GetMax();
    T GetMin();

    template <class identifier> friend ostream & operator << (ostream& out,const
    Pair<identifier>& p);

};

template<class identifier>
identifier Pair<identifier>::GetMax() {
    int i=0, n=2;

    // Initialize maximum element
    identifier max = this->values[0];

    // Traverse array elements
    // from second and compare
    // every element with current max
    for (i = 1; i < n; i++)
        if (this->values[i] > max)
            max = this->values[i];
    return max;
}

template<class identifier>
identifier Pair<identifier>::GetMin() {
    int i=0, n=2;

    // Initialize maximum element
    identifier min = this->values[0];

    // Traverse array elements
    // from second and compare
    // every element with current max
    for (i = 1; i < n; i++)
        if (this->values[i] < min)
            min = this->values[i];
    return min;
}

template<class identifier>
ostream &operator<<(ostream &out, const Pair<identifier> &p) {
    out << p.values[0] << ", " << p.values[1];
    return out;
}


int main ()
{
    Pair <double> y (2.23,3.45);
    Sequence <Pair<double>,5> myPairs;
    myPairs.setmember (0,y);
    cout << myPairs.getmember(0) << '\n';
}