#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

struct suff_array {
  const int L; string s; int i, skip, lvl;
  vector<vi> P; vector<pair<pii,int>> M;
  suff_array(const string &s) : L(s.size()), s(s), P(1, vi(L, 0)), M(L) {
      for (i = 0; i < L-(L==1); i++) P[0][i] = int(s[i]);
      for (skip = 1, lvl = 1; skip < L; skip *= 2, lvl++) {
            P.push_back(vi(L, 0));
            for (int i = 0; i < L; i++)
              M[i] = {{P[lvl-1][i], i+skip<L ? P[lvl-1][i + skip] : -1000}, i};
            sort(M.begin(), M.end());
            for (int i = 0; i < L; i++)
              P[lvl][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ?
                  P[lvl][M[i-1].second] : i; } }
  const vi& get_sarray() { return P.back(); }
  //returns len of longest common prefix of s[i...L-1] and s[j...L-1], O(lg L)
  int lcp(int i, int j) {
      int len = 0; if (i == j) return L - i;
          for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--)
                if (P[k][i] == P[k][j]) { i += 1 << k; j += 1 << k; len += 1
                << k; }
                    return len; } };

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  suff_array sf = suff_array(s);
  int q;
  cin >> q;
  for (int qq = 0; qq < q; qq++) {
    int i, j; cin >> i >> j;
    cout << sf.lcp(i,j) << endl;
  }
}
