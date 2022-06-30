#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int n_max = 1000; // Max number of words in a line in any test

string line1;          // Input line #1
string line2;          // Input line #2
vector<string> words1; // Words in input line #1
vector<string> words2; // Words in input line #2
int dp[n_max][n_max];

int lcs_len(int i = 0, int j = 0) {
    if (i == words1.size() || j == words2.size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int result = 0;
    if (words1[i] == words2[j]) {
        result = 1 + lcs_len(i + 1, j + 1);
    } else {
        result = max(lcs_len(i + 1, j), lcs_len(i, j + 1));
    }

    dp[i][j] = result;

    return result;
}

vector<string> words_in_line(string line) {
    vector<string> result;
    string word_buf;
    for (char c : line) {
        if (isalnum(c)) {
            word_buf += c;
        } else if (!word_buf.empty()) {
            result.push_back(word_buf);
            word_buf.clear();
        }
    }
    if (!word_buf.empty()) {
        result.push_back(word_buf);
    }
    return result;
}

void runcase(int casen) {
    // ** Init **

    words1 = words_in_line(line1);
    words2 = words_in_line(line2);
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    string ans = "Blank!";
    if (words1.size() && words2.size()) {
        ans = "Length of longest match: " + to_string(lcs_len());
    }

    // ** Output **

    cout << setw(2) << casen << ". " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ** Input & test-case handling **

    for (int casen = 1; getline(cin, line1) && getline(cin, line2); ++casen) {
        runcase(casen);
    }

    return 0;
}
