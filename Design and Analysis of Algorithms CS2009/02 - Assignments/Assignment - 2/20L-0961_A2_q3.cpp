#define _USE_MATH_DEFINES // Must be before #include <cmath>
#include <cmath> // M_PI
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

// Recursive FFT
void fft(vector<complex<double>> &a, bool invert) {
    int n = a.size();
    if (n == 1) return; // always check base case: if `n==1` return

    // --- 1. Divide ---
    // Split the array 'a' into two smaller arrays:
    // a0: contains all elements from even indices
    // a1: contains all elements from odd indices
    // Example: [a0, a1, a2, a3] -> Evens = [a0, a2], Odds = [a1, a3].
    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; ++i) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    // --- 2. CONQUER ---
    // Recursively compute the FFT on the two smaller subproblems.
    // After these calls, a0 will hold the FFT of the evens (E)
    // and a1 will hold the FFT of the odds (O).
    fft(a0, invert); // "Conquer" the even subproblem
    fft(a1, invert); // "Conquer" the odd subproblem

    // --- 3. COMBINE ---
    // Combine the results from the smaller problems to get the final FFT.
    // This uses the formula:
    // A[k]       = E[k] + w^k * O[k]
    // A[k + n/2] = E[k] - w^k * O[k]
    // where 'w' is the n-th root of unity.

    // Calculate the principal n-th root of unity, 'wn'.
    // The angle depends on whether it's a forward (invert=false) or inverse (invert=true) transform.
    // Hence the ternary operator.
    double ang = 2 * M_PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(ang), sin(ang));

    for (int i = 0; 2 * i < n; ++i) {
        // E[k] is a0[i]
        // O[k] is a1[i]
        // w^k is the current value of 'w'
        complex<double> u = a0[i];
        complex<double> v = w * a1[i];
        // A[k] = E[k] + w^k * O[k]
        a[i] = u + v;
        // A[k+n/2] = E[k] - w^k * O[k]
        a[i + n / 2] = u - v;
        // Increment the power of w for the next iteration (w^(k+1))
        w *= wn;
    }

    // Use w^-1 Conjugates of Roots of unity
    // Since we divide by 2 at each level of recursion, the total scaling factor becomes n.
    if (invert) {
        for (int i = 0; i < n; ++i)
            a[i] /= 2.0; // perform log(n) divisions
    }
}

// Polynomial convolution using FFT
// This function multiplies two polynomials represented by their coefficient vectors A and B.
vector<long long> convolution(const vector<int> &A, const vector<int> &B) {
    // Copy integer coefficients to complex vectors for FFT processing.
    vector<complex<double>> fa(A.begin(), A.end()), fb(B.begin(), B.end());
    
    // --- 1. Pad A and B to a size that is a power of 2 ---
    // The result of convolving two polynomials of size m and n is a polynomial of size m+n-1.
    // FFT is most efficient with sizes that are a power of 2.
    // We find the smallest power of 2 that is >= m+n-1.

    int n = 1;
    while (n < (int)A.size() + (int)B.size()) n <<= 1;

    // Resize the vectors. This pads them with extra zeros to reach the power-of-2 size.
    fa.resize(n);
    fb.resize(n);

    // --- 2. FFT both sequences ---
    // This is the core of the Convolution Theorem. Instead of a slow O(n^2) polynomial multiplication,
    // we transform the polynomials into a "point-value" representation where multiplication is fast.
    // The FFT does this transformation in O(n log n) time.
    fft(fa, false);
    fft(fb, false);

    // --- 3. Multiply results element-wise ---
    // In the point-value domain, polynomial convolution becomes a simple O(n) element-wise multiplication.
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];

    // --- 4. Inverse FFT the product ---
    // We now have the result, but it's still in the point-value domain.
    // We use the Inverse FFT to transform it back into the familiar coefficient representation.
    fft(fa, true); // set `invert = true` and multiply

    // --- 5. Round real parts to nearest integers ---
    // The IFFT gives us complex numbers, but because our original inputs were integers,
    // the imaginary parts are just floating-point noise and should be close to zero.
    // We take the real part of each complex number and round it to the nearest integer.
    vector<long long> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = (long long)llround(fa[i].real());
        // round the result to the nearest integer

    // The final result of the convolution should have a size of |A| + |B| - 1.
    // We resize the vector to trim off any extra padding zeros.
    result.resize(A.size() + B.size() - 1);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < m; ++i) cin >> B[i];

    vector<long long> C = convolution(A, B);
    for (int i = 0; i < (int)C.size(); ++i) {
        if (i) cout << " ";
        cout << C[i];
    }
    cout << "\n";
    return 0;
}
