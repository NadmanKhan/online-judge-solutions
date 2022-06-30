#include <bits/stdc++.h>
using namespace std;

constexpr int n_max = 1e6;
constexpr int mod = 1e9 + 7;

int n;
int dp[n_max];

int count_ways(int x = 0) {
    if (x >= n) {
        return x == n;
    }

    if (dp[x] != -1) {
        return dp[x];
    }

    int result = 0;
    for (int i = 1; i <= 6; ++i) {
        result = (result + count_ways(x + i)) % mod;
    }

    dp[x] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << count_ways();

    return 0;
}