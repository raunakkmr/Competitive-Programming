#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int N = 50005;

int n, m, k;
vector<pipii> edges;

struct UnionFind {
  int num, id[N], sz[N];

  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      id[i] = i;
      sz[i] = 1;
      num = n;
    }
  }

  int getRoot(int i) {
    while (i != id[i]) {
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }

  int find(int p, int q) {
    return getRoot(p) == getRoot(q);
  }

  void join(int p, int q) {
    int i = getRoot(p);
    int j = getRoot(q);
    if (sz[i] <= sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
    } else {
      id[j] = i;
      sz[i] += sz[j];
    }
    num--;
  }
};

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  int a, b, w;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    edges.push_back({w, {a,b}});
  }

  sort(edges.begin(), edges.end());

  int res = 0;
  UnionFind uf(n);
  for (const auto &edge : edges) {
    if (uf.num <= k) break;
    int a = edge.second.first, b = edge.second.second;
    if (uf.find(a, b)) {
      continue;
    }
    uf.join(a,b);
    res += edge.first;
  }

  cout << res << endl;

}
