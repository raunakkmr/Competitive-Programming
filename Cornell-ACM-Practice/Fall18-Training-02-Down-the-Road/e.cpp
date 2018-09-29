#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5+5;

int n, m, a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i];

  ll ans = a[0] - 1;

  for (int i = 1; i < m; i++) {
    if (a[i] > a[i-1]) ans += (a[i] - a[i-1]);
    else if (a[i] < a[i-1]) ans += (n - a[i-1] + a[i]);
  }

  cout << ans << endl;

}
