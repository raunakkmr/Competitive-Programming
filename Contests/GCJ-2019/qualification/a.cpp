#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll p(int b, int e) {
    ll res = 1;
    while (e--) {
        res *= b;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        ll n; cin >> n;
        ll tmp = n;
        ll sub = 0;
        int idx = 0;
        while (tmp) {
            int dig = tmp % 10;
            tmp /= 10;
            if (dig == 4) {
                sub += 1 * p(10, idx);
            }
            idx ++;
        }
        ll x = n - sub;
        cout << x << " " << n-x;
        cout << '\n';
    }
}