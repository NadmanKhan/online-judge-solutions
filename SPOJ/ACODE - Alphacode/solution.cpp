#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int len_max = 5000;

string code;
int64_t dp[len_max];

int64_t count_decodings(int i = 0) {
    if (i == code.size()) {
        return 1;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int64_t result = 0;
    int x = code[i] - '0';
    if (x) {
        result = count_decodings(i + 1);
        if (i + 1 < code.size()) {
            int y = (x * 10) + code[i + 1] - '0';
            if (y <= 26) {
                result += count_decodings(i + 2);
            }
        }
    }

    dp[i] = result;

    return result;
}

void runcase() {
    // ** Init **

    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int64_t ans = count_decodings();

    // ** Output **

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & test-case handling **

    while (cin >> code && code != "0") {
        runcase();
    }

    return 0;
}
