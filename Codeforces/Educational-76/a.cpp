#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if (a > b) swap(a,b);
        cout << (b-a) + min(a-1+n-b, x) << endl;
    }
}