#include <iostream>
#include <string>
#include <list>

using namespace std;

string s;
list<int> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  ans.push_back(1);
  auto it = ans.end();
  it--;
  for (int i = 0; i+1 < s.size(); i++) {
    char ch = s[i];
    if (ch == 'l') {
      it = ans.insert(it, i+2);
    }
    else if (ch == 'r') {
      it++;
      it = ans.insert(it, i+2);
    }
  }

  for (const int &x : ans)
    cout << x << '\n';

}
