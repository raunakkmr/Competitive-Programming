#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    for (int tc = 1; tc <= k; tc++) {
        int ans = 0;
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            ans = max(ans, min(n-i, v[i]));
        }
        cout << ans << endl;
    }
}