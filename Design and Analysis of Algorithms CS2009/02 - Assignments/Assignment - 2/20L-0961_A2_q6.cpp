#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using int64 = long long; // handle large integers (10e8)

vector<int> digits;
vector<int64> memo; // memo[pos] when tight == 0, -1 if unknown

// handle positions
int64 dfs(int pos, bool tight) {
    int n = (int)digits.size();
    // leading zeros are allowed in the construction and correspond 
    // to shorter actual numbers 
    // (that's standard digit-DP behavior
    if (pos == n) return 1; // one completed number (leading zeros allowed)
    if (!tight && memo[pos] != -1) return memo[pos];

    int limit = tight ? digits[pos] : 9; // the limit for the current digit, or 9 if tight
    int64 total = 0; // handle large integers (10e8)
    for (int d = 0; d <= limit; ++d) {
        // we skip digits 4 and 9 in the digit loop, 
        // so we never form numbers containing those digits
        if (d == 4 || d == 9) continue; // skip forbidden digits
        bool nextTight = tight && (d == limit);
        total += dfs(pos + 1, nextTight);
    }

    if (!tight) memo[pos] = total;
    return total;
}

// countUpTo(X) returns the count of numbers in [0..X] 
// that do not contain digit 4 or 9.
int64 countUpTo(unsigned long long X) {
    // construct digits vector from most significant to least
    if (X == (unsigned long long)0) {
        // only number 0: it's valid (doesn't contain 4 or 9)
        return 1;
    }
    digits.clear();
    unsigned long long t = X;
    while (t > 0) {
        digits.push_back((int)(t % 10));
        t /= 10;
    }
    reverse(digits.begin(), digits.end());
    memo.assign(digits.size(), -1);
    return dfs(0, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned long long L, R;
    if (!(cin >> L >> R)) return 0;

    // for the final answer we subtract countUpTo(L-1) from countUpTo(R) (taking care L=0)
    int64 ans;
    if (L == 0) {
        ans = countUpTo(R);
    } else {
        ans = countUpTo(R) - countUpTo(L - 1);
    }
    cout << ans << "\n";
    return 0;
}
