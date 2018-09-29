#include <iostream>
#include <string>

using namespace std;

int arr[4][4];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      cin >> arr[i][j];

  string ans = "NO";

  for (int i = 0; i < 4; i++) {
    if (!arr[i][3]) continue;
    if (arr[i][0] + arr[i][1] + arr[i][2] > 0) {
      ans = "YES";
      break;
    }
    if (arr[(i+1)%4][0]) {
      ans = "YES";
      break;
    }
    if (arr[(i+2)%4][1]) {
      ans = "YES";
      break;
    }
    if (arr[(i+3)%4][2]) {
      ans = "YES";
      break;
    }
  }

  cout << ans << endl;
}
