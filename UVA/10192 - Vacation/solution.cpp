#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int len_max = 100; // Max string length in any test

string a; // First of the input string pairs
string b; // Second of the input string pairs
int dp[len_max][len_max];

int lcs_len(int i = 0, int j = 0) {
    if (i == a.size() || j == b.size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int result = 0;
    if (a[i] == b[j]) {
        result = 1 + lcs_len(i + 1, j + 1);
    } else {
        result = max(lcs_len(i + 1, j), lcs_len(i, j + 1));
    }

    dp[i][j] = result;

    return result;
}

void runcase(int casen) {
    // ** Init **

    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int ans = lcs_len();

    // ** Output **

    cout << "Case #" << casen << ": you can visit at most " << ans << " cities.\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & test-case handling **

    for (int casen = 1; getline(cin, a); ++casen) {
        if (a == "#") break;
        getline(cin, b);
        runcase(casen);
    }

    return 0;
}
