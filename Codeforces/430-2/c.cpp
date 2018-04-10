#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

bool seen[N];
int n, a[N], ans[N], cnt[N];
vector<int> t[N], divisors;

void dfs1(int u, int p) {
  seen[u] = true;
  if (u == p) {
    ans[u] = 0;
  } else {
    ans[u] = __gcd(a[u], ans[p]);
  }
  for (const int &v : t[u]) {
    if (!seen[v]) dfs1(v, u);
  }
}

void dfs2(int u, int lvl) {
  seen[u] = true;
  for (const int &d : divisors) {
    if (a[u] % d == 0) {
      cnt[d]++;
    }
    if (cnt[d] >= lvl) {
      ans[u] = max(ans[u], d);
    }
  }
  for (const int &v : t[u]) {
    if (!seen[v]) dfs2(v, lvl+1);
  }
  for (const int &d : divisors) {
    if (a[u] % d == 0) {
      cnt[d]--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n-1; i++) {
    int x, y; cin >> x >> y; x--; y--;
    t[x].push_back(y); t[y].push_back(x);
  }

  dfs1(0, 0);
  for (int i = 0; i < N; i++) seen[i] = false;
  for (int i = 1; i*i <= a[0]; i++) {
    if (a[0] % i == 0) {
      divisors.push_back(i);
      if (i*i != a[0]) {
        divisors.push_back(a[0] / i);
      }
    }
  }
  sort(divisors.begin(), divisors.end());
  dfs2(0, 0);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
