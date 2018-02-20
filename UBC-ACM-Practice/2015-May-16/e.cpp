#include<bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

ll n, m, k;
ll a[505];
ll arr[505][505];

ll noise(ll x, ll k) {
  ll a=x/(k+1);
  ll b = x%(k+1);
  return (k+1 - b)*(a*(a+1))/2 + b*((1+a)*(1+a+1))/2;
}

int main() {
  cin >> n >> m >> k;

  for (int i=0; i<n; i++) {
    int x; cin >> x; a[x]++;
  }
  for (int i=1; i<=m; i++) {
    for (int j=0; j<=k; j++) {
      arr[i][j] = arr[i-1][j] + noise(a[i], 0);
      for (int y=1; y<=j; y++)
	arr[i][j] = min(arr[i][j], arr[i-1][j-y] + noise(a[i],y));
    }
  }
  cout << arr[m][k] << endl;;
  return 0;
}
