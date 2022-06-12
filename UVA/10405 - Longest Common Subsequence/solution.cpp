#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int len_max = 1000; // Max string length in any test

string a; // First of the input string pairs
string b; // Second of the input string pairs
int dp[len_max][len_max];

int lcs(int i = 0, int j = 0) {
    if (i == a.size() || j == b.size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int result = 0;
    if (a[i] == b[j]) {
        result = 1 + lcs(i + 1, j + 1);
    } else {
        result = max(lcs(i + 1, j), lcs(i, j + 1));
    }

    dp[i][j] = result;

    return result;
}

void runcase() {
    // ** Init **

    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int ans = lcs();

    // ** Output **

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & test-case handling **
    
    while (getline(cin, a) && getline(cin, b)) {
        runcase();
    }

    return 0;
}
