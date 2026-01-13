#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using int64 = long long; // handle large integers (10e8)

vector<int> digits;
int K;
vector<vector<int64>> memo; // memo[pos][sumMod], used when tight == 0
vector<vector<char>> seen;  // to indicate memo filled

int64 dfs(int pos, int sumMod, bool tight) {
    int n = (int)digits.size();
    if (pos == n) {
        return (sumMod % K == 0) ? 1 : 0;
    }
    if (!tight && seen[pos][sumMod]) return memo[pos][sumMod];

    int limit = tight ? digits[pos] : 9;
    int64 total = 0;
    for (int d = 0; d <= limit; ++d) {
        bool nextTight = tight && (d == limit);
        int nextSum = (sumMod + d) % K;
        total += dfs(pos + 1, nextSum, nextTight);
    }

    if (!tight) {
        seen[pos][sumMod] = 1;
        memo[pos][sumMod] = total;
    }
    return total;
}

// countUpTo(X) counts all integers 0..X whose digit-sum % K == 0
int64 countUpTo(unsigned long long X) {
    // construct digit list for X (most-significant first)
    digits.clear();
    if (X == 0) {
        digits.push_back(0);
    } else {
        unsigned long long t = X;
        // uses long long to avoid overflow. The counts can be large but fit in 64-bit: 
        // at most 10^19 possibilities but we never reach that in practice; 
        // using long long is standard for these counts.

        while (t > 0) {
            digits.push_back((int)(t % 10));
            t /= 10;
        }
        reverse(digits.begin(), digits.end());
    }
    int n = (int)digits.size();
    memo.assign(n, vector<int64>(K, 0));
    seen.assign(n, vector<char>(K, 0));
    return dfs(0, 0, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned long long L, R;
    if (!(cin >> L >> R >> K)) return 0;

    // store K globally used by dfs
    // K guaranteed >=1
    // but we need it for functions above
    ::K = K;

    int64 ans;
    if (L == 0) {
        ans = countUpTo(R);
    } else {
        ans = countUpTo(R) - countUpTo(L - 1);
    }
    // final answer for [L..R] is countUpTo(R) - countUpTo(L-1). 
    // given constraints L >= 1 this works directly
    cout << ans << "\n";
    return 0;
}
