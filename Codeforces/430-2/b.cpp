#include <iostream>
#include <cmath>

using namespace std;

typedef long double ld;

const ld EPS = 1e-7;

ld d, r, n, x, y, s, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> d >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> s;
    ld dist = sqrt(x*x + y*y);
    // if (abs(dist-s-r+d) < EPS && abs(dist+s-r) < EPS) ans++;
    if (dist-s >= r-d-EPS && dist+s <= r+EPS) {
      ans++;
    }
  }
  cout << ans << endl;
}
