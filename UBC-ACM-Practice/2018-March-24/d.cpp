#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vector<int> nums, ans;
  set<int> remaining;
  for (int i = 1; i <= n; i++) remaining.insert(i);
  for (int i = 0; i < m; i++) {
    int x; cin >> x; nums.push_back(x); remaining.erase(x);
  }

  list<int> rem(remaining.begin(), remaining.end());
  list<int> cur(nums.begin(), nums.end());
  auto it = cur.begin();
  for (const auto &x : rem) {
    while (it != cur.end() && *it < x) ++it;
    cur.insert(it, x);
  }

  for (const auto &x : cur) cout << x << endl;

}
