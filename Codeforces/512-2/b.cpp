#include <iostream>

using namespace std;

int n, d, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d >> m;

  int xi, yi;
  for (int i = 0; i < m; i++) {
    cin >> xi >> yi;
    if (d <= xi+yi && xi+yi <= 2*n-d && -d <= xi-yi && xi-yi <=d)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
