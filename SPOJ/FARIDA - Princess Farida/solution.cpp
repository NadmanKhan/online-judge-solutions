#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int n_max = 1e4; // Max number of monsters in any test

int n;
int a[n_max];
int64_t dp[n_max];

int64_t max_coins(int i = 0) {
    if (i >= n) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int64_t result = max(a[i] + max_coins(i + 2),
                         max_coins(i + 1));

    dp[i] = result;

    return result;
}

void runcase(int casen) {
    // ** Input & init **

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int64_t ans = max_coins();

    // ** Output **

    cout << "Case " << casen << ": " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Test-case handling **

    int ncases;
    cin >> ncases;
    for (int casen = 1; casen <= ncases; ++casen) {
        runcase(casen);
    }

    return 0;
}
