#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        string n; cin >> n;
        string a = n;
        string b = "";
        for (int i = 0; i < n.size(); i++) b+= '0';
        for (int i = 0; i < n.size(); i++) {
            const char &ch = n[i];
            if (ch == '4') {
                a[i] = '3';
                b[i] = '1';
            }
        }
        cout << stoll(a) << " " << stoll(b);
        cout << '\n';
    }
}