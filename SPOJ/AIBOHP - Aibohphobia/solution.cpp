#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int len_max = 6100; // Max possible length of the string in any test

string s;                 // Input string
int dp[len_max][len_max]; // `dp[l][r]` == the cached/memoized value for the state `(l, r)`. A value of -1 indicates no/null value.

/**
 * @brief Computes and returns the "palindrome distance" --- the number of
 * character insertions required to make a palindrome --- of the substring in the 
 * range `[l, r]` of the input string `s` (declared globally). This is a recursive
 * function, with caching/memoization (dynamic programming) using the global array
 * `dp` for optimization.
 *
 * @param l [state variable] The left pointer of the substring being considered
 * @param r [state variable] The right pointer of the substring being considered
 * @return int
 */
int palin_dist(int l = 0, int r = (int)s.size() - 1) {
    // ** Base case **

    if (l >= r) {
        return 0;
    }

    // ** General case **

    /**
     * Check if the current state has a cached value. If yes, then return the
     * value immediately without any further computation.
     */
    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int result = 0;

    if (s[l] == s[r]) {
        /**
         * For `s[l] == s[r]`, we don't need an insert operation at this state.
         * Therefore, the result (operational cost) of the current state is
         * just the result of the following call's state (where BOTH the pointers
         * `l` and `r` are moved one place inwards).
         */
        result = palin_dist(l + 1, r - 1);
    } else {
        /**
         * For `s[l] != s[r]`, we need to insert one character at either
         * `l` (matching `s[r]`) or at `r` (matching `s[l]`). Hence, add
         * 1 to the result (for the single insert operation) and then add
         * to it the smaller of the results between the two following states
         * achieved by moving either `l` or `r` one place inwards.
         */
        result = 1 + min(palin_dist(l + 1, r),
                         palin_dist(l, r - 1));
    }

    // Cache the result.
    dp[l][r] = result;

    return result;
}

void runcase() {
    // ** Input & init **

    cin >> s;
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int ans = palin_dist();

    // ** Output **

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ncases = 0;
    cin >> ncases;
    while (ncases--) {
        runcase();
    }

    return 0;
}