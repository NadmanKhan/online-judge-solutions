#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int amt_max = 7489; // Max amount of cents to change for in any test
constexpr int ncoins = 5;     // Number of coin types
constexpr int coins[ncoins] =
    {50, 25, 10, 5, 1}; // Coins types

int amount;                      // [Input] amount of cents to change for
int64_t dp[amt_max + 1][ncoins]; // `dp[amt][min_coin_idx]` = cached/memoized value for the state `(amt, min_coin_idx)`. A value of -1 indicates no/null value.

int64_t count_possible_changes(int amt = amount, int min_coin_idx = 0) {
    // ** Base case **

    if (!amt) {
        return 1;
    }

    // ** General case **

    if (dp[amt][min_coin_idx] != -1) {
        return dp[amt][min_coin_idx];
    }

    int64_t result = 0;
    for (int i = min_coin_idx; i < ncoins; ++i) {
        if (coins[i] > amt) continue;
        result += count_possible_changes(amt - coins[i], i);
    }

    dp[amt][min_coin_idx] = result;

    return result;
}

void runcase() {
    // ** Init **

    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int64_t ans = count_possible_changes();

    // ** Output **

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & test-case handling **

    while (cin >> amount) {
        runcase();
    }

    return 0;
}
