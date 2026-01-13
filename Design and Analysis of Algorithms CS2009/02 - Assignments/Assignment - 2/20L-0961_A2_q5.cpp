#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, W;
    cin >> N >> W;
    // array stores the w and v
    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> w[i] >> v[i];

    // dp[i][cap] stores the maximum value considering items from i to N with a knapsack capacity of cap
    vector<vector<int>> dp(N + 2, vector<int>(W + 1, 0));

    // classic 0/1 Knapsack problem
    // bottom-up fill
    for (int i = N; i >= 1; --i) {
        for (int cap = 0; cap <= W; ++cap) {
            dp[i][cap] = dp[i + 1][cap]; // skip
            if (cap >= w[i]) 
                dp[i][cap] = max(dp[i][cap], v[i] + dp[i + 1][cap - w[i]]);
        }
    }

    cout << dp[1][W] << "\n";
    return 0;
}
