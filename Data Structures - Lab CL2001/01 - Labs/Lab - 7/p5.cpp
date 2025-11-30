#include <iostream>
using namespace std;

int nCr(int n, int r) {
    // (5,5) returns 1
    /*nCr(4, 2)
        = nCr(4 - 1, 2 - 1) + nCr(4 - 1, 2)
        = nCr(3, 1) + nCr(3, 2)
        = nCr(3 - 1, 1) + nCr(3 - 1, 0) + nCr(3 - 1, 2 - 1) + nCr(3 - 1, 2)
        = nCr(2, 1) + nCr(2, 0) + nCr(2, 1) + nCr(2, 2)
        = nCr(1, 0) + nCr(1, 1) + 1 + nCr(1, 0) + nCr(1, 1) + 1
        = 1 + 1 + 1 + 1 + 1 + 1
        = 6*/
    if (r == 0 || r == n) return 1;  // stop recursion, we know the answer.
    return nCr(n - 1, r - 1) + nCr(n - 1, r); // the answer is made of the sum of two "easier" ones
}

void main() {
    cout << nCr(5, 3) << endl;
    cout << nCr(9, 4) << endl;
}