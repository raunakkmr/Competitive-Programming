#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string ans = "NO";
  int l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  for (int i = l; i <= r; i++) {
    if ((i % k == 0) && (x <= i/k) && (i/k <= y)) {
      ans = "YES";
      break;
    }
  }
  cout << ans << endl;
}
