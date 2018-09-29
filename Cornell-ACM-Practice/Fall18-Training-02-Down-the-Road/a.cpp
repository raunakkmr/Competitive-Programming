#include <iostream>
#include <cassert>

using namespace std;

const int N = 1e3+5;

int n, m, deg[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) deg[i] = n-1;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b; deg[a]--; deg[b]--;
  }
  int centre = 0, maxdeg = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] > maxdeg) {
      maxdeg = deg[i];
      centre = i;
    }
  }

  cout << n-1 << endl;
  if (n == 1) return 0;
  for (int i = 1; i <= n; i++) {
    if (i == centre) continue;
    cout << i << " " << centre << endl;
  }

}
