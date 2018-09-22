#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int N = 1e5+5;
int a1[N], a2[N], pre[N], pre2[N];

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a1[i];
    a2[i] = a1[i];
    pre[i] = pre[i-1] + a1[i];
  }
  sort(a2, a2+n+1);
  for (int i = 1; i <= n; i++) {
    pre2[i] = pre2[i-1] + a2[i];
  }
  int m; cin >> m;
  for (int q = 0; q < m; q++) {
    int type, l, r; cin >> type >> l >> r;
    if (type == 1) {
      cout << pre[r] - pre[l] + a1[l] << endl;
    } else if (type == 2) {
      cout << pre2[r] - pre2[l] + a2[l] << endl;
    }
  }
}
