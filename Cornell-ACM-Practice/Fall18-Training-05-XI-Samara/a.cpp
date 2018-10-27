#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, s, g;
    cin >> s >> g;
    if (s%g != 0 || s == g) {
        cout << -1 << '\n';
    } else {
        a = g;
        b = s - g;
        cout << a << " " << b << '\n';
    }
}