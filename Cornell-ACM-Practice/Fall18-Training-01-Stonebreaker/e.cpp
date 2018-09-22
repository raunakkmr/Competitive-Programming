#include <iostream>

using namespace std;

const int N = 55;

int n, x[N], y[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> y[i];

  int xs = 0, ys = 0;
  for (int i = 0; i < n; i++) xs += x[i];
  for (int i = 0; i < n; i++) ys += y[i];

  if (xs < ys)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;

}
