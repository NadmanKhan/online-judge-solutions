#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int cap_max = 2000; // Max possible capacity in any test
constexpr int n_max = 2000;   // Max possible number of items in any test

int cap;                    // Capacity of the bag
int n;                      // Number of items to store in the bag
int sizes[n_max];           // `sizes[i]` = size of the i-th item
int values[n_max];          // `values[i]` = value of the i-th item
int dp[n_max][cap_max + 1]; // `dp[i][cap_rem]` = cached/memoized value for the state `(i, cap_rem)`. A value of -1 indicates no/null value.

/**
 * @brief Computes and returns the max possible total value from items, starting
 * from the `i`-th item and going up to the `(n - 1)`-th item, that can be
 * stored in the bag without exceeding its remaining capacity `cap_rem`. This is a
 * recursive function, with caching/memoization (dynamic programming) using the
 * global array `dp` for optimization. It solves the classic Knapsack Problem.
 *
 * @param i [state variable] Index of the item being considered
 * @param cap_rem [state variable] Remaining capacity
 * @return int
 */
int knapsack(int i = 0, int cap_rem = cap) {
    // ** Base case **

    if (i == n) {
        return 0;
    }

    // ** General case **

    // Check if cache value exists at the current state.
    // If yes, then return that value.
    if (dp[i][cap_rem] != -1) {
        return dp[i][cap_rem];
    }

    // Result when the item is skipped
    int skip = knapsack(i + 1, cap_rem);

    // Result when the item is taken
    int take = (cap_rem >= sizes[i])
                   ? values[i] + knapsack(i + 1, cap_rem - sizes[i])
                   : 0;

    // Get and cache the result
    int result = max(skip, take);
    dp[i][cap_rem] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & init **

    cin >> cap >> n;
    for (int i = 0; i < n; ++i) {
        cin >> sizes[i] >> values[i];
    }
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int ans = knapsack();

    // ** Output **

    cout << ans << '\n';

    return 0;
}