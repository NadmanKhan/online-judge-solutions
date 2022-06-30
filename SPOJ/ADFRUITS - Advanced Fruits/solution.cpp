#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int len_max = 100; // Max length of a name in any test

string name1; // Input name #1
string name2; // Input name #2
string dp[len_max][len_max];

string combine(int i = 0, int j = 0) {
    if (i == name1.size()) {
        return name2.substr(j);
    }
    if (j == name2.size()) {
        return name1.substr(i);
    }

    if (dp[i][j] != "#") {
        return dp[i][j];
    }

    string tmp1 = name1[i] + combine(i + 1, j);
    string tmp2 = name2[j] + combine(i, j + 1);
    string result = (tmp2.size() < tmp1.size()) ? tmp2 : tmp1;
    if (name1[i] == name2[j]) {
        string tmp3 = name1[i] + combine(i + 1, j + 1);
        if (tmp3.size() < result.size()) {
            result = tmp3;
        }
    }

    dp[i][j] = result;

    return result;
}

void runcase() {
    // ** Init **

    for (int i = 0; i < len_max; ++i) {
        for (int j = 0; j < len_max; ++j) {
            dp[i][j] = "#";
        }
    }

    // ** Solve **

    string ans = combine();

    // ** Output **

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & test-case handling **

    while (cin >> name1 >> name2) {
        runcase();
    }

    return 0;
}
