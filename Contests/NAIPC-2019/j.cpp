#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define endl '\n'

string s, t;
// positions of each character a-z in string s
vector<int> pos[26];

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        pos[s[i]-'a'].push_back(i);
    }

    int c = t[0] - 'a';
    if (pos[c].size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0, cur = -1;
    int prev = -1;
    for (const int &idx : pos[c]) {
        bool not_found = false;
        cur = idx;
        for (int i = 1; i < t.size(); i++) {
            int nx = t[i] - 'a';
            auto it = upper_bound(pos[nx].begin(), pos[nx].end(), cur);
            if (it == pos[nx].end()) {
                not_found = true;
                break;
            }
            cur = *it;
        }
        if (not_found) {
            break;
        }
        if (prev == -1) {
            ans += ((s.size() - cur)*(idx+1));
        } else {
            ans += ((s.size() - cur)*(idx-prev));
        }
        prev = idx;
    }

    cout << ans << endl;
}