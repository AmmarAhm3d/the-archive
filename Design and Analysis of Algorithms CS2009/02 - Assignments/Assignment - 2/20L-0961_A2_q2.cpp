#include <iostream>
#include <vector>
#include <utility> // pair
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// helper function to convert a character into balance delta
pair<int,int> delta(char c) {
    if (c == 'A') return {+1, 0};
    if (c == 'T') return {-1, 0};
    if (c == 'C') return {0, +1};
    return {0, -1}; // 'G'
}

// divide & conquer function on range [l, r]
int solve(const string &s, int l, int r) {
    if (l == r) return 0;
    int m = (l + r) / 2;

    int leftAns = solve(s, l, m);
    int rightAns = solve(s, m + 1, r);
    int best = max(leftAns, rightAns);

    // compute suffix balances on left side (from mid -> l)
    vector<pair<int,int>> leftBalances;
    int b1 = 0, b2 = 0;
    for (int i = m; i >= l; --i) {
        auto d = delta(s[i]);
        b1 += d.first;
        b2 += d.second;
        leftBalances.push_back({b1, b2});
    }

    // compute prefix balances on right side (from mid+1 -> r)
    vector<pair<int,int>> rightBalances;
    b1 = 0; b2 = 0;
    for (int i = m + 1; i <= r; ++i) {
        auto d = delta(s[i]);
        b1 += d.first;
        b2 += d.second;
        rightBalances.push_back({b1, b2});
    }

    // hash map: balance pair -> farthest index distance (prefix length)
    unordered_map<long long, int> rightBest;
    rightBest.reserve(rightBalances.size() * 2);
    const long long BASE = 200005; // combine (b1,b2) safely into one key

    // store maximum prefix length where this balance occurs
    for (int i = 0; i < (int)rightBalances.size(); ++i) {
        long long key = (long long)(rightBalances[i].first + BASE) * 400011 + (rightBalances[i].second + BASE);
        // prefix length from mid+1 to mid+1+i
        rightBest[key] = max(rightBest[key], i + 1);
    }

    // for each left suffix, check if there’s a matching right prefix
    b1 = 0; b2 = 0;
    int lenLeft = leftBalances.size();
    for (int i = 0; i < lenLeft; ++i) {
        auto [x, y] = leftBalances[i];
        // we want right balance = (-x, -y)
        long long key = (long long)(-x + BASE) * 400011 + (-y + BASE);
        if (rightBest.count(key)) {
            int totalLen = (i + 1) + rightBest[key];
            best = max(best, totalLen);
        }
    }

    return best;
}

int longestBalanced(const string &s) {
    if (s.empty()) return 0;
    return solve(s, 0, (int)s.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << longestBalanced(s) << "\n";
    return 0;
}
