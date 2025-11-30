#include <iostream>
using namespace std;

template<class t>
t GetMax(t a, t b){
    if (a > b)  return a;
}
template<class t>
t GetMax(t a, t b, t c){
    if (a >= b && a >= c)
        return a;

    else if (b >= a && b >= c)
        return b;
    else
    return c;

}


template<class y>
y GetMin(y a, y b){
    if(a < b) return a;
}
template<class y>
y GetMin(y a, y b,y c){
    if(a <= b && a <= c)
    {
        return a;
    }
    else if(b <= c)
    {
        return b;
    }
    return c;
}

template<class t1,class t2, class t3>
int GetMax(t1 a, t2 b, t2 c){

}

template<class t1,class t2, class t3>
long GetMin(t1 a, t2 b, t2 c){

}

int main ()
{
    char i='Z';
    int j=6, k;
    long l=10, m=5, n;
    k=GetMax(i,m, 10);
    n=GetMin(j,l, 10);
    cout << k << endl;
    cout << n << endl;
    return 0;
