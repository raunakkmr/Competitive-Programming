# include <iostream>
# include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n; cin >> n;
        string p; cin >> p;
        cout << "Case #" << tc << ": ";
        for (const char &ch : p) {
            if (ch == 'S') cout << 'E';
            else cout << 'S';
        }
        cout << '\n';
    }
}