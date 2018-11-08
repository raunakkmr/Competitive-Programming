#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    int tmp = n, ans = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (tmp == 0) break;
        if (s1[i] == s2[i]) {
            tmp--;
            ans++;
        }
    }

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            ans++;
        }
    }

    ans -= tmp;

    cout << ans << '\n';

}
