#include <bits/stdtr1c++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1 << 17;

const int INF = 0x7F7F7F7F;
const int NINF = 0x80808080;

struct MinTree { int a[2*MAXN], b[2*MAXN], ai[2*MAXN], bi[2*MAXN]; MinTree() {
  memset(a, INF, sizeof a); memset(b, INF, sizeof b);
  for (int i = 0; i < MAXN; ++i) ai[MAXN+i] = bi[MAXN+i] = i; }
  // use after manually changing entries in [x..y], costs O(log(MAXN) + y-x)
  void update(int x, int y, int i=1, int l=0, int r=MAXN-1) {
    if (y<l || r<x || l==r) return; int m = (l+r)/2;
    update(x,y,2*i,l,m); update(x,y,2*i+1,m+1,r);
    if (b[2*i] < b[2*i+1]) {
      b[i] = b[2*i];
      bi[i] = bi[2*i];
    } else {
      b[i] = b[2*i+1];
      bi[i] = bi[2*i+1];
    }
    if (a[2*i] < a[2*i+1]) {
      a[i] = a[2*i];
      ai[i] = ai[2*i];
      if (a[2*i+1] < b[i]) {
        b[i] = a[2*i+1];
        bi[i] = ai[2*i+1];
      }
    } else {
      a[i] = a[2*i+1];
      ai[i] = ai[2*i+1];
      if (a[2*i] < b[i]) {
        b[i] = a[2*i];
        bi[i] = ai[2*i];
      }
    }}
  void insert(int x, ll v) { a[MAXN+x] = v; update(x,x); }
  pair<pair<ll, ll>, pair<ll, ll>> query(int x, int y, int i=1, int l=0, int r=MAXN-1) {
    if (y<l || r<x) return make_pair(pair<ll, ll>(INF, -1), pair<ll, ll>(INF, -1));
    if (x<=l && r<=y) return make_pair(make_pair(a[i], ai[i]), make_pair(b[i], bi[i])); int m = (l+r)/2;
    return comb(query(x,y,2*i,l,m), query(x,y,2*i+1,m+1,r)); }
  pair<pair<ll, ll>, pair<ll, ll>> comb(const pair<pair<ll, ll>, pair<ll, ll>>& a, const pair<pair<ll, ll>, pair<ll, ll>>& b) {
    ll x, y, xi, yi;
    ll a1 = a.first.first;
    ll a1i = a.first.second;
    ll a2 = a.second.first;
    ll a2i = a.second.second;
    ll b1 = b.first.first;
    ll b1i = b.first.second;
    ll b2 = b.second.first;
    ll b2i = b.second.second;
    if (a2 < b2) {
      y = a2;
      yi = a2i;
    } else {
      y = b2;
      yi = b2i;
    }
    if (a1 < b1) {
      x = a1;
      xi = a1i;
      if (b1 < y) {
        y = b1;
        yi = b1i;
      }
    } else {
      x = b1;
      xi = b1i;
      if (a1 < y) {
        y = a1;
        yi = a1i;
      }
    }
    return make_pair(make_pair(x, xi), make_pair(y, yi));
  }} minX, minY;

struct MaxTree { int a[2*MAXN], b[2*MAXN], ai[2*MAXN], bi[2*MAXN]; MaxTree() {
  memset(a, NINF, sizeof a); memset(b, NINF, sizeof b);
  for (int i = 0; i < MAXN; ++i) ai[MAXN+i] = bi[MAXN+i] = i; }
  // use after manually changing entries in [x..y], costs O(log(MAXN) + y-x)
  void update(int x, int y, int i=1, int l=0, int r=MAXN-1) {
    if (y<l || r<x || l==r) return; int m = (l+r)/2;
    update(x,y,2*i,l,m); update(x,y,2*i+1,m+1,r);
    if (b[2*i] > b[2*i+1]) {
      b[i] = b[2*i];
      bi[i] = bi[2*i];
    } else {
      b[i] = b[2*i+1];
      bi[i] = bi[2*i+1];
    }
    if (a[2*i] > a[2*i+1]) {
      a[i] = a[2*i];
      ai[i] = ai[2*i];
      if (a[2*i+1] > b[i]) {
        b[i] = a[2*i+1];
        bi[i] = ai[2*i+1];
      }
    } else {
      a[i] = a[2*i+1];
      ai[i] = ai[2*i+1];
      if (a[2*i] > b[i]) {
        b[i] = a[2*i];
        bi[i] = ai[2*i];
      }
    }}
  void insert(int x, ll v) { a[MAXN+x] = v; update(x,x); }
  pair<pair<ll, ll>, pair<ll, ll>> query(int x, int y, int i=1, int l=0, int r=MAXN-1) {
    if (y<l || r<x) return make_pair(make_pair(NINF, -1), make_pair(NINF, -1));
    if (x<=l && r<=y) return make_pair(make_pair(a[i], ai[i]), make_pair(b[i], bi[i])); int m = (l+r)/2;
    return comb(query(x,y,2*i,l,m), query(x,y,2*i+1,m+1,r)); }
  pair<pair<ll, ll>, pair<ll, ll>> comb(const pair<pair<ll, ll>, pair<ll, ll>>& a, const pair<pair<ll, ll>, pair<ll, ll>>& b) {
    ll x, y, xi, yi;
    ll a1 = a.first.first;
    ll a1i = a.first.second;
    ll a2 = a.second.first;
    ll a2i = a.second.second;
    ll b1 = b.first.first;
    ll b1i = b.first.second;
    ll b2 = b.second.first;
    ll b2i = b.second.second;
    if (a2 > b2) {
      y = a2;
      yi = a2i;
    } else {
      y = b2;
      yi = b2i;
    }
    if (a1 > b1) {
      x = a1;
      xi = a1i;
      if (b1 > y) {
        y = b1;
        yi = b1i;
      }
    } else {
      x = b1;
      xi = b1i;
      if (a1 > y) {
        y = a1;
        yi = a1i;
      }
    }
    return make_pair(make_pair(x, xi), make_pair(y, yi));
  }} maxX, maxY;

int N, Q;
int X[100005], Y[100005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
    minX.insert(i, X[i]);
    maxX.insert(i, X[i]);
    minY.insert(i, Y[i]);
    maxY.insert(i, Y[i]);
  }
  for (int i = 0; i < Q; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    pair<ll, ll> MINX[2], MAXX[2], MINY[2], MAXY[2];
    auto tmp = minX.query(a, b);
    MINX[0] = tmp.first;
    MINX[1] = tmp.second;
    tmp = maxX.query(a, b);
    MAXX[0] = tmp.first;
    MAXX[1] = tmp.second;
    tmp = minY.query(a, b);
    MINY[0] = tmp.first;
    MINY[1] = tmp.second;
    tmp = maxY.query(a, b);
    MAXY[0] = tmp.first;
    MAXY[1] = tmp.second;
    set<int> pts;
    pts.insert(MINX[0].second);
    pts.insert(MAXX[0].second);
    pts.insert(MINY[0].second);
    pts.insert(MAXY[0].second);
    ll res = INF;
    for (int i : pts) {
      res = min(res, max(
              MAXX[(MAXX[0].second == i)].first - MINX[(MINX[0].second == i)].first,
              MAXY[(MAXY[0].second == i)].first - MINY[(MINY[0].second == i)].first
            ));
    }
    cout << res << endl;
  }

  return 0;
}
