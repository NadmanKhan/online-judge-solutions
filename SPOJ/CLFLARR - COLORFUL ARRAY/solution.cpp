#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<set<pii>> colors_from(n + 1);
    vector<set<pii>> colors_upto(n + 1);
    for (int i = 1; i <= q; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        colors_from[l].emplace(i, c);
        colors_upto[r].emplace(i, c);
    }

    list<int> ans;

    set<pii, greater<pii>> colors_curr;
    for (int i = 1; i <= n; ++i) {
        for (const pii& x : colors_from[i]) {
            colors_curr.insert(x);
        }

        ans.push_back(colors_curr.begin()->second);

        for (const pii& x : colors_upto[i]) {
            colors_curr.erase(x);
        }
    }

    for (auto x : ans) {
        cout << x << "\n";
    }

    return 0;
}