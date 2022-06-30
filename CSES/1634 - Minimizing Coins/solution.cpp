#include <bits/stdc++.h>
using namespace std;

constexpr int n_max = 100;
constexpr int x_max = 1e6;
constexpr int inf = 1 << 30;

int n;
int x;
int c[n_max];
int dp[x_max + 1];

int min_coins_change(int amt = x) {
    if (amt <= 0) {
        return amt == 0 ? 0 : inf;
    }

    if (dp[amt] != -1) {
        return dp[amt];
    }

    int result = inf;
    for (int i = 0; i < n; ++i) {
        result = min(result, min_coins_change(amt - c[i]));
    }
    if (result != inf) {
        ++result;
    }

    dp[amt] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = min_coins_change();
    if (ans == inf) {
        ans = -1;
    }

    cout << ans << '\n';

    return 0;
}