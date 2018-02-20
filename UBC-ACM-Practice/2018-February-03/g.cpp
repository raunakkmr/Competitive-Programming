#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5+5;
const int INF = numeric_limits<int>::max()/10000;

int n, m, k;
vector<int> adj[N];
int dist[N];

void bfs(int s) {
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (const int &v : adj[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m ; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    int no; cin >> no;
    adj[n+1].push_back(no);
  }

  fill(dist, dist+N, INF);
  bfs(n+1);

  for (int i = 1; i <= n; i++) {
    if (dist[i] >= INF) cout << -1 << " ";
    else cout << dist[i]-1 << " ";
  }
  cout << endl;

}
