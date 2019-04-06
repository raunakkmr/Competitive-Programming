#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

bool ok(ll x) {
    string s = to_string(x);
    for (const char &ch : s) {
        if (ch == '4') return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        ll n; cin >> n;
        for (ll x = 1; x < n; x++) {
            if (ok(x) && ok(n-x)) {
                cout << x << " " << n-x;
                break;
            }
        }
        cout << '\n';
    }
}