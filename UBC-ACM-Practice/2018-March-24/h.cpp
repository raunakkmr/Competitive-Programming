#include <bits/stdc++.h>

using namespace std;

int arr[55][55];
int n, m, rc, cc, r[55], c[55];
string rrr, ccc;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> rrr >> ccc;
  n = rrr.size(); m = ccc.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = 1;
    }
  }

  for (int i = 0; i < rrr.size(); ++i) {
    r[i] = !!int(rrr[i] - '0') ^ (m % 2);
    rc += r[i];
  }
  for (int i = 0; i < ccc.size(); ++i) {
    c[i] = !!int(ccc[i] - '0') ^ (n % 2);
    cc += c[i];
  }
  if (abs(rc - cc) % 2) {
    cout << -1 << endl;
    return 0;
  }

  if (rc > cc) {
    int extra = rc - cc;
    int j = 0;
    for (int i = 0; i < rrr.size(); ++i) {
      if (!r[i]) continue;
      if (extra > 0) {arr[i][0] = 0; --extra;}
      else {
        for (; j < ccc.size(); ++j) {
          if (!c[j]) continue;
          arr[i][j] = 0;
          ++j;
          break;
        }
      }
    }
  } else {
    int extra = cc - rc;
    int j = 0;
    for (int i = 0; i < ccc.size(); ++i) {
      if (!c[i]) continue;
      if (extra > 0) {arr[0][i] = 0; --extra;}
      else {
        for (; j < rrr.size(); ++j) {
          if (!r[j]) continue;
          arr[j][i] = 0;
          ++j;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  return 0;
}
