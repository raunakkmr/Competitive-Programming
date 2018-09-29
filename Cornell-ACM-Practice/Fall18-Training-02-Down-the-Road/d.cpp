#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int N = 2e5+5;
const int K = 2e5+5;

int n, k, s, t, g[K];
pii cars[N];

bool ok(int mid) {
  int cur = 0;
  int ti = 0;
  int dist = 0;
  for (int i = 1; i <= k; i++) {
    dist = g[i] - cur;
    if (dist > mid) return false;
    ti += min(dist, mid-dist) + (dist - min(dist, mid-dist))*2;
    cur = g[i];
  }
  dist = s - g[k];
  ti += min(dist, mid-dist) + (dist - min(dist, mid-dist))*2;
  if (dist > mid) return false;
  return ti <= t;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> s >> t;
  for (int i = 1; i <= n; i++) cin >> cars[i].first >> cars[i].second;
  for (int i = 1; i <= k; i++) cin >> g[i];
  sort(g+1, g+k+1);

  int lo = 1, hi = 1e9;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (ok(mid)) {
      hi = mid;
    } else {
      lo = mid+1;
    }
  }
  int ans = 1e9+5;
  for (int i = 1; i <= n; i++) {
    if (cars[i].second < lo) continue;
    ans = min(ans, cars[i].first);
  }
  if (!ok(lo) || ans == 1e9+5) cout << -1 << endl;
  else cout << ans << endl;
}
