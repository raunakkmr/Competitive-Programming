#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, k;
map<int, vector<int>> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x; m[x].push_back(i);
  }
  if (m.size() < k) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    int cnt = 0;
    for (const auto &p : m) {
      cout << p.second[0]+1 << " ";
      cnt++;
      if (cnt == k) {
        cout << endl; return 0;
      }
    }
  }
}
