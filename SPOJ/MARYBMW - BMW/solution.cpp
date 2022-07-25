#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;

constexpr long long inf = 1e18;

ll dijkstra(const vector<vector<pil>>& adj, int from, int to) {
    vector<ll> dist(adj.size(), -1);
    priority_queue<pli> pq;

    dist[from] = inf;
    pq.emplace(dist[from], from);

    while (!pq.empty()) {
        const int u = pq.top().second;
        const ll min_w = pq.top().first;
        pq.pop();

        for (const auto& e : adj[u]) {
            const int v = e.first;
            const ll new_min_w = min(min_w, e.second);
            if (dist[v] == -1 || dist[v] < new_min_w) {
                dist[v] = new_min_w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist[to];
}

void runcase(int casen) {
    int n, m;
    cin >> n >> m;
    vector<vector<pil>> adj(n);
    while (m--) {
        int a, b;
        ll speed;
        cin >> a >> b >> speed;
        --a, --b;
        adj[a].emplace_back(b, speed);
        adj[b].emplace_back(a, speed);
    }
    ll ans = dijkstra(adj, 0, n - 1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ncases = 1;
    cin >> ncases;
    for (int casen = 1; casen <= ncases; ++casen) {
        runcase(casen);
    }

    return 0;
}