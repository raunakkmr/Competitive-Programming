#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> pii;

const int N = 3e5+5;

int n, m, dists[N][2];
vector<int> positions;
vector<pii> adj[N];
vector<pii> diffs;
set<pii> s;

void dfs(int u, int p, int w, int mode) {
  if (p == -1) {
    dists[u][mode] = 0;
  } else {
    dists[u][mode] = dists[p][mode] + w;
  }
  for (const pii &e : adj[u]) {
    if (e.first == p) continue;
    dfs(e.first, u, e.second, mode);
  }
}

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n-1; i++) {
    int v, u, w; cin >> v >> u >> w;
    v--; u--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs(0,-1, 0, 0);
  dfs(n-1,-1, 0, 1);

  for (int i = 0; i < n; i++) diffs.push_back({dists[i][0] - dists[i][1], i});
  sort(diffs.begin(), diffs.end());
  for (int i = 0; i < n; i++) s.insert({dists[i][1], i});
  positions.resize(n);
  for (int i = 0; i < n; i++) positions[diffs[i].second] = i;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int cur = diffs[i].second;
    s.erase({dists[cur][1], cur});
    for (const pii &e : adj[cur])
      if (positions[e.first] > positions[cur])
        s.erase({dists[e.first][1], e.first});
    if (!s.empty())
      ans = max(ans, dists[cur][0] + s.rbegin()->first);
    for (const pii &e : adj[cur])
      if (positions[e.first] > positions[cur])
        s.insert({dists[e.first][1], e.first});
  }

  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    cout << min(dists[n-1][0], ans+x) << '\n';
  }

}
