#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<long long, string>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
  sort(v.rbegin(), v.rend());
  cout << v[0].second << endl;
}
