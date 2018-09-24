#include <iostream>
#include <string>

using namespace std;

const int N = 105;

int n, a[N];
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) a[i] = s[i]-'0';

  string ans = "";

  for (int val = 0; val <= 900; val++) {
    int cur = 0;
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cur += a[i];
      if (cur == val) {
        cnt++;
        cur = 0;
      } else if (cur > val) {
        break;
      }
      if (i == n-1 && cur == 0 && cnt > 1) {
        flag = true;
        break;
      }
    }
    if (!flag) continue;
    else {
      ans = "YES";
      break;
    }
  }

  if (ans != "YES") ans = "NO";
  cout << ans << endl;
}
