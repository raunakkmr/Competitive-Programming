#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5+5;
int n, m;

vector<int> adj[N];
bool seen[N];
int num[N];
int degrees[N];
struct cmp {
  bool operator()(const int &a, const int &b) {
    if (degrees[a] == degrees[b]) return a < b;
    else return degrees[a] < degrees[b];
  }
};
set<int, cmp> vertices;

bool cycle(int u) {
  seen[u] = true;
  num[u] = 1;
  for (const int &v : adj[u]) {
    if (num[v] == 2) continue;
    else if (num[v] == 1) return true;
    else if (num[v] == 0) {
      bool tmp = cycle(v);
      if (tmp) return true;
    }
  }
  num[u] = 2;
  return false;
}

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    degrees[b]++;
  }

  fill(seen, seen+N, false);
  for (int i = 0; i < n; i++) {
    if (seen[i]) continue;
    if (cycle(i)) {
      cout << "*" << endl;
      return 0;
    }
  }

  for (int i = 0; i < n; i++) vertices.insert(i);
  while (!vertices.empty()) {
    int cur = *vertices.begin();
    vertices.erase(vertices.begin());
    for (const auto &ne : adj[cur]) {
      vertices.erase(ne);
      degrees[ne]--;
      vertices.insert(ne);
    }
    cout << cur << endl;
  }

}
