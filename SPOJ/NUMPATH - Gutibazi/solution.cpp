#include <bits/stdc++.h>
using namespace std;

// ** Declare global variables **

constexpr int dim_max = 7;

int nrows;
int ncols;
int dp[dim_max][dim_max];

int count_paths(int row = 0, int col = 0) {
    if (!(0 <= row && row < nrows) || !(0 <= col && col < ncols)) {
        return 0;
    }
    if (row == nrows - 1 && col == ncols - 1) {
        return 1;
    }

    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    int result = count_paths(row + 1, col) +
                 count_paths(row, col + 1);

    dp[row][col] = result;

    return result;
}

void runcase() {
    // ** Input & init **

    cin >> nrows >> ncols;
    memset(dp, -1, sizeof(dp));

    // ** Solve **

    int ans = count_paths();

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
