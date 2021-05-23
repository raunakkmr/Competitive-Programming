#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;
map<pair<char,char>, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        m.clear();

        cin >> n;
        cin >> s >> t;

        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            else {
                m[{s[i],t[i]}]++;
            }
        }

        if ((m.size() != 1) || (m.begin()->second != 2)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}