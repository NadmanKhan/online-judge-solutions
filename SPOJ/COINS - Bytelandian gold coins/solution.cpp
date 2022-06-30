#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int n_max = 1e9; // Max string length in any test

int n;
map<int, int64_t> dp;

int64_t max_change(int amt = n) {
    if (amt <= 2) {
        return amt;
    }

    if (dp.find(amt) != dp.end()) {
        return dp[amt];
    }

    int half = amt / 2;
    int third = amt / 3;
    int quarter = amt / 4;


    int64_t result = max((int64_t)half, max_change(half)) +
                     max((int64_t)third, max_change(third)) +
                     max((int64_t)quarter, max_change(quarter));

    dp[amt] = result;

    return result;
}

void runcase() {
    // ** Solve **

    int64_t ans = max_change();

    // ** Output **

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & test-case handling **

    while (cin >> n) {
        runcase();
    }

    return 0;
}
