#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int x = 0, y = 0;
    int a, b;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == x && b == y) continue;
        if (x < y) {
            if (a < b) {
                ans += max(0LL, a-y+1);
            } else if (a == b) {
                ans += b-y+1;
            } else {
                ans += b-y+1;
            }
        } else if (x == y) {
            if (a < b) {
                ans += (a-x);
            } else if (a == b) {
                ans += (a-x);
            } else {
                ans += (b-y);
            }
        } else {
            if (a < b) {
                ans += a-x+1;
            } else if (a == b) {
                ans += a-x+1;
            } else {
                ans += max(0LL, b-x+1);
            }
        }
        cerr << ans << endl;
        x = a, y = b;
    }
    cout << ans << '\n';
}
