#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int n_max = 1e5;

int n;
int a[n_max];
int64_t dp[n_max];

int64_t max_sum(int i = 0) {
    if (i >= n) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int64_t result = max(max_sum(i + 1),
                         max_sum(i + 2) + a[i]);

    dp[i] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & init **

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int64_t ans = max_sum();

    // ** Output **

    cout << ans << '\n';

    return 0;
}
