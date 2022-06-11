#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int len_max = 6100; // Max possible length of the string in any test

string s;                 // Input string
int dp[len_max][len_max]; // `dp[l][r]` == the catched/memoized value for the state `(l, r)`. A value of -1 indicates no/null value.

/**
 * @brief Recursively computes and returns the answer.
 *
 * @param l [state variable] The left pointer of the substring being considered
 * @param r [state variable] The right pointer of the substring being considered
 * @return int
 */
int compute_ans(int l = 0, int r = (int)s.size() - 1) {
    // ** Base case **

    if (l >= r) {
        return 0;
    }

    // ** General case **

    // Check if the current state has a catched value. If yes, then return the
    // value immediately without any computation.
    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int result = 0;

    if (s[l] == s[r]) {
        // If `s[l] == s[r]`, we don't need an insert operation at this state.
        // Therefore, the result of the current state is just the result of
        // the next recursive call's state (where BOTH the pointers are
        // moved one place).
        result = compute_ans(l + 1, r - 1);
    } else {
        // If `s[l] != s[r]`, we need to insert one character at either
        // `l` (matching `s[r]`), or at `r` (matching `s[l]`). Hence, add
        // 1 to result (for the single insert operation) and then add
        // to it the smaller of the results between the state when `l` is
        // moved one place and the state when `r` is moved one place.
        result = 1 + min(compute_ans(l + 1, r),
                         compute_ans(l, r - 1));
    }

    // Catche the result.
    dp[l][r] = result;

    return result;
}

void runcase() {
    // ** Input & init **

    cin >> s;
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int ans = compute_ans();

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
