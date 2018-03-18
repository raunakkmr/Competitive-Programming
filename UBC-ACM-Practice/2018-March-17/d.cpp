#include <bits/stdc++.h>

using namespace std;

int n;

int memo[100][100][100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n <= 3) cout << n << endl;
  else {
    cout << int(ceil(log2(n))) + 1 << endl;
  }
}
