#include<bits/stdtr1c++.h>

using namespace std;

typedef long long ll;
int n;
vector<ll> v;
vector<ll> ans;

void solve() {
  ans.push_back(v[0]);
  for (int i=1; i<n; i++) {
    ans.push_back(v[i]*(i+1) - (v[i-1]*(i)));
  }
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    ll x; cin >> x;
    v.push_back(x);
  }
  solve ();
  for (int a=0; a<n; a++)
    cout << ans[a] << " ";
  return 0;
}
