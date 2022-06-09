#include <bits/stdc++.h>
using namespace std;

constexpr int cap_max = 2000;
constexpr int n_max = 2000;

int cap;           // Capacity of the bag
int n;             // Number of items to store in the bag
int sizes[n_max];  // `sizes[i]` = size of the i-th item
int values[n_max]; // `values[i]` = value of the i-th item

/**
 * @brief
 * `dp[i][cap_rem]` = catched/memoized value at the state `(i, cap_rem)`.
 * -1 marks uncatched state.
 */
int dp[n_max + 10][cap_max + 10];

/**
 * @brief Recursively finds and returns the answer.
 *
 * @param i [state variable] Index of the current item
 * @param cap_rem [state variable] Currently remaining capacity
 * @return int
 */
int find_ans(int i = 0, int cap_rem = cap) {
    // ** Base case **

    if (i == n) {
        return 0;
    }

    // ** General case **

    // Check memoized value at the current current state
    if (dp[i][cap_rem] != -1) {
        return dp[i][cap_rem];
    }

    // Value when the i-th item is skipped
    int skip = find_ans(i + 1, cap_rem);

    // Value when the i-th item is taken
    int take = (cap_rem >= sizes[i])
                   ? values[i] + find_ans(i + 1, cap_rem - sizes[i])
                   : 0;

    // Get and memoize the result
    int result = max(skip, take);
    dp[i][cap_rem] = result;

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // input & init
    cin >> cap >> n;
    for (int i = 0; i < n; ++i) {
        cin >> sizes[i] >> values[i];
    }
    memset(dp, -1, sizeof(dp));

    // solve
    int ans = find_ans();

    // output
    cout << ans << '\n';

    return 0;
}