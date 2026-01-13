#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int D;
    cin >> D;
        // --- Input Reading ---
    // 'h' stores the happiness points for each activity on each day.
    // h[i][0] = happiness of activity A on day i
    // h[i][1] = happiness of activity B on day i
    // h[i][2] = happiness of activity C on day i
    vector<vector<int>> h(D, vector<int>(3)); // store happiness values for each of the three activities on each day
    for (int i = 0; i < D; ++i)
        cin >> h[i][0] >> h[i][1] >> h[i][2];

    // --- Dynamic Programming Table Initialization ---
    // dp[day][activity] = The maximum happiness achievable from 'day' to the end,
    //                     given we choose 'activity' on 'day'.
    // We use D+1 rows. The last row (dp[D]) acts as our base case, representing
    // the day after the vacation ends, where achievable happiness is 0.
    vector<vector<int>> dp(D + 1, vector<int>(3, 0)); // 2D matrix which is initialized by zeroes `D+1` row is treated as base case for last day, which will have happiness 0 as no further activites are possible

    // --- Bottom-Up DP Calculation ---
    // We start from the end and work our way backward to the beginning.
    // To decide the best choice for a given day, we need to know the best outcomes of the next day.
    for (int day = D - 1; day >= 0; --day) {    // bottom up from 2nd to last day to first day
        // Iterate through each possible activity for the current 'day'.
        for (int act = 0; act < 3; ++act) {     // three possible activites for the day
            int best = 0; // store max happiness we get on `day + 1`
            // Check all possible activities for the *next* day.
            for (int next = 0; next < 3; ++next) {
                // The core constraint: we cannot do the same activity on consecutive days.
                if (next == act) continue;
                // Find the best possible happiness from the next day onwards,
                // using the values we've already computed.
                best = max(best, dp[day + 1][next]);
            }
            // The max happiness for choosing 'act' on 'day' is the sum of today's happiness
            // and the best possible happiness we can get from the next day.
            dp[day][act] = h[day][act] + best;
        }
    }

    // --- Final Answer ---
    // The final answer is the maximum possible happiness starting from day 0.
    // We simply check the best outcome among the three choices for the first day.
    cout << max({dp[0][0], dp[0][1], dp[0][2]}) << "\n";
    return 0;
}
