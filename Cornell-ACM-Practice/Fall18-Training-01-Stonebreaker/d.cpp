#include <iostream>
#include <limits>

using namespace std;

#define int long long

const int W = 1e5+5;

int w, l;
int a[W];

#undef int
int main() {
#define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> w >> l;
  for (int i = 0; i+1 < w; i++) cin >> a[i+1];

  int ans = numeric_limits<int>::max()/100;
  int li = 1, ri= l;
  int tmp = 0;
  for (int i = li; i <= min(ri, w-1); i++) tmp += a[i];
  while (li < w) {
    ans = min(ans, tmp);
    // cout << li << " "<< ri << " " << tmp << endl;
    tmp -= a[li];
    li++, ri++;
    if (ri < w) tmp += a[ri];
    ri = min(ri, w-1);
    if (ri - li + 1 < l) break;
  }

  cout << ans << endl;

}
