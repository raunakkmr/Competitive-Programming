#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define int long long

const int N = 5e5+5;

int n, a[N];

#undef int
int main() {
#define int long long
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }

    int ans = 0, mn = 1e9+5;
    bool pos = true, neg = true;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i]);
        mn = min(mn, abs(a[i]));
        neg &= (a[i] <= 0);
        pos &= (a[i] >= 0);
    }

    if (neg || pos) cout << ans-2*mn << '\n';
    else cout << ans << '\n';
}