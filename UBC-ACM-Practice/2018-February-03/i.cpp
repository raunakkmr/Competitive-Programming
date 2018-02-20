#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define int long long

typedef tree<
int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 5e6+5;
int n, b[N];
ordered_set nums;

// #undef int
int main() {
// #define int long long
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> ans;
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) nums.insert(i);
  for (int i = n-1; i >= 0; i--) {
    int cur = b[i];
    auto it = nums.find_by_order(nums.size() - 1 - cur);
    ans.push_back(*it);
    nums.erase(it);
  }
  reverse(ans.begin(), ans.end());
  for (const int &x : ans) {
    cout << x << " ";
  }
  cout << endl;
}
