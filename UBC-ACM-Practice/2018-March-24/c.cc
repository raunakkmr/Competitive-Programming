#include<bits/stdtr1c++.h>
using namespace std;

string S;
int cnt;
int mem[1 << 16][17];

bool dp(int bm, int at) {
  if (at < 0) return false;
  if (mem[bm][at] != -1) {
    return mem[bm][at];
  }
  bool res = dp(bm, at-1);
  for (int i = 0; i < S.size(); ++i) {
    int bm2 = bm;
    bm2 ^= (1 << (at + i)) - 1;
    bm2 ^= (1 << i) - 1;
    bm2 &= (1 << S.size()) - 1;
    res = res || dp(bm2, at-1);
  }
  return mem[bm][at] = res;
}
int main() {
  cin >> S;
  for (char c : S) {
    cnt += (c - '0');
  }
  if (cnt == S.size()) {
    cout << 0 << endl;
    return 0;
  }
  memset(mem, -1, sizeof mem);
  int res = 1 << 20;
  int bm = 0;
  for (int i = 0; i < S.size(); ++i) {
    bm |= (1 << i) * (S[i] == '0');
  }
  for (int i = 0; i <= 16; ++i)
    mem[0][i] = true;
  for (int i = 1; i <= 16; ++i) {
    if (dp(bm, i)) {
      res = min(res, i);
    }
  }
  cout << res << endl;
  return 0;
}
