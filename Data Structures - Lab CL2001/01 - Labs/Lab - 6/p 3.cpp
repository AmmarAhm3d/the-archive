#include <iostream>
using namespace std;

template <class T> const T& _max(const T& a, const T& b) {
    return (a < b) ? b : a;     
}

template <class T> const T& _min(const T& a, const T& b) {
    return !(b < a) ? a : b;     
}


long long _drop(long long eggs, long long floors)
{
    if (floors == 0 || floors == 1) return floors;
    if (eggs == 1)                  return floors;
    if (eggs == 0)                  return 0;

    long long res = LONG_MAX;
    
    for (auto i = 1; i <= floors; i++) {
        long long  sres = max(_drop(eggs - 1, i - 1), _drop(eggs, floors - i));
        res = min(res, sres + 1);
    }

    return res;
}

int main()
{
    long long  t;

    cout << "T -> ";
    cin >> t;

    if (t) {
        do {
            cout << "N,K -> ";
            long long n, k;
            cin >> n >> k;
            if (n > 0 || k > 0) {
                cout << "Minimum number of attempts -> ";
                cout << _drop(n, k) << endl;
            }
            else
                cout << "Invalid input\n";
        } while (--t);
    }
    else
        cout << "Invalid input\n";
    

    return 0;
}