#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int n_max = 1000; // Max number of words in a line in any test

string line1; // First of the two input lines
string line2; // Second of the two input lines
int dp[n_max][n_max];

int lcs(int i = 0, int j = 0) {
    if (i == line1.size() || j == line2.size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int result = 0;
    if (line1[i] == line2[j]) {
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
    
    while (getline(cin, line1) && getline(cin, line2)) {
        runcase();
    }

    return 0;
}
