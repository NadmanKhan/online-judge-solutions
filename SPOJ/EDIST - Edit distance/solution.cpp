#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int len_max = 2000; // Max string length in any test

string a;
string b;
int64_t dp[len_max][len_max];

int edit_dist(int i = 0, int j = 0) {
    if (i == a.size()) {
        return (int)b.size() - j;
    }
    if (j == b.size()) {
        return (int)a.size() - i;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int result = edit_dist(i + 1, j + 1);
    if (a[i] != b[j]) {
        int edit_a = edit_dist(i + 1, j);
        int edit_b = edit_dist(i, j + 1);
        result = 1 + min({result, edit_a, edit_b});
    }

    dp[i][j] = result;

    return result;
}

void runcase() {
    // ** Input & init **

    cin >> a >> b;
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int ans = edit_dist();

    // ** Output **

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Test-case handling **

    int ncases;
    cin >> ncases;
    while (ncases--) {
        runcase();
    }

    return 0;
}
