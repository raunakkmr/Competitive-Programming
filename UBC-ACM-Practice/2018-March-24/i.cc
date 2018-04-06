#include<bits/stdtr1c++.h>
using namespace std;

typedef long long ll;

int N, M;
struct node {
  bool red = false;
  int par;
  vector<int> ch;
} A[200002];

#define DASIZE (M+1) * sizeof(ll)
const ll MOD = 1e9+7;

ll* dp(int n) {
  ll* acc = NULL;
  for (int c : A[n].ch) {
    ll* da = dp(c);
    if (!acc) { acc = (ll*)malloc(DASIZE); memset(acc, 0, DASIZE); acc[0] = 1; }
    for (int i = M; i >= 0; --i) {
      acc[i] = (acc[i] * da[0]) % MOD;
      for (int j = i-1; j >= 0; --j) {
        acc[i] += acc[j] * da[i-j];
        acc[i] %= MOD;
        if (!da[i-j]) break;
      }
    }
    free(da);
  }
  if (!acc) { acc = (ll*)malloc(DASIZE); memset(acc, 0, DASIZE); acc[0] = 1; }
  acc[A[n].red]++;
  return acc;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  cin >> N >> M;
  for (int i = 1; i < N; ++i) {
    int p; cin >> p; --p;
    A[i].par = p;
    A[p].ch.push_back(i);
  }
  for (int i = 0; i < M; ++i) {
    int p; cin >> p; --p;
    A[p].red = true;
  }

  ll* res = dp(0);

  for (int i = 0; i <= M; ++i) {
    cout << res[i] << "\n";
  }

  free(res);

  return 0;
}
