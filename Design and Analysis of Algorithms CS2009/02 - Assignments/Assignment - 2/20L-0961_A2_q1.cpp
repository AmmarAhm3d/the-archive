#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> pref; // prefix sum array

// check if submatrix (r1..r2, c1..c2) is all ones
bool allOnes(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return false;
    int sum = pref[r2][c2];
    if (r1 > 0) sum -= pref[r1 - 1][c2];
    if (c1 > 0) sum -= pref[r2][c1 - 1];
    if (r1 > 0 && c1 > 0) sum += pref[r1 - 1][c1 - 1];
    int area = (r2 - r1 + 1) * (c2 - c1 + 1);
    return sum == area;
}

// divide & conquer over region [r1..r2][c1..c2]
int solve(const vector<vector<int>>& a, int r1, int r2, int c1, int c2) {
    if (r1 > r2 || c1 > c2) return 0;
    if (r1 == r2 && c1 == c2) return a[r1][c1];

    // divide
    int rm = (r1 + r2) / 2;
    int cm = (c1 + c2) / 2;

    // recurse on 4 quadrants
    int q1 = solve(a, r1, rm, c1, cm);
    int q2 = solve(a, r1, rm, cm + 1, c2);
    int q3 = solve(a, rm + 1, r2, c1, cm);
    int q4 = solve(a, rm + 1, r2, cm + 1, c2);
    int best = max({q1, q2, q3, q4});

    int maxPossible = min(r2 - r1 + 1, c2 - c1 + 1);

    // test all possible mid-crossing squares using binary search
    // --- horizontal crossing (across rm)
    {
        int low = best + 1, high = maxPossible;
        while (low <= high) {
            int k = (low + high) / 2;
            int half = k / 2;
            int top = rm - half + 1;
            int bottom = top + k - 1;
            if (top < r1) { top = r1; bottom = top + k - 1; }
            if (bottom > r2) { bottom = r2; top = bottom - k + 1; }
            bool found = false;
            for (int colStart = c1; colStart + k - 1 <= c2 && !found; ++colStart) {
                int colEnd = colStart + k - 1;
                if (allOnes(top, colStart, bottom, colEnd))
                    found = true;
            }
            if (found) { best = k; low = k + 1; }
            else high = k - 1;
        }
    }

    // --- vertical crossing (across cm)
    {
        int low = best + 1, high = maxPossible;
        while (low <= high) {
            int k = (low + high) / 2;
            int half = k / 2;
            int left = cm - half + 1;
            int right = left + k - 1;
            if (left < c1) { left = c1; right = left + k - 1; }
            if (right > c2) { right = c2; left = right - k + 1; }
            bool found = false;
            for (int rowStart = r1; rowStart + k - 1 <= r2 && !found; ++rowStart) {
                int rowEnd = rowStart + k - 1;
                if (allOnes(rowStart, left, rowEnd, right))
                    found = true;
            }
            if (found) { best = k; low = k + 1; }
            else high = k - 1;
        }
    }

    // --- both horizontal + vertical crossing (center cross)
    {
        int low = best + 1, high = maxPossible;
        while (low <= high) {
            int k = (low + high) / 2;
            int half = k / 2;
            int top = rm - half + 1;
            int left = cm - half + 1;
            int bottom = top + k - 1;
            int right = left + k - 1;
            if (top < r1) { top = r1; bottom = top + k - 1; }
            if (left < c1) { left = c1; right = left + k - 1; }
            if (bottom > r2) { bottom = r2; top = bottom - k + 1; }
            if (right > c2) { right = c2; left = right - k + 1; }
            bool ok = allOnes(top, left, bottom, right);
            if (ok) { best = k; low = k + 1; }
            else high = k - 1;
        }
    }

    return best;
}

int largestSquare(const vector<vector<int>>& a) {
    int n = a.size();
    pref.assign(n, vector<int>(n, 0));
    // construct prefix sums
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            pref[i][j] = a[i][j];
            if (i > 0) pref[i][j] += pref[i - 1][j];
            if (j > 0) pref[i][j] += pref[i][j - 1];
            if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
        }
    return solve(a, 0, n - 1, 0, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    cout << largestSquare(a) << "\n";
    return 0;
}
