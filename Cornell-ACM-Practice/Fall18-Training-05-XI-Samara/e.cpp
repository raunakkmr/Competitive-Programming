#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "YES" << '\n';
    } else {
        int n = a.size(), i = 0;
        int lo = -1, hi = -1;
        while (1) {
            if (a[i] != b[i]) {
                lo = i; break;
            }
            i++;
        }
        i = n-1;
        while (1) {
            if (a[i] != b[i]) {
                hi = i; break;
            }
            i--;
        }
        int loo = lo, hii = hi;
        while (lo <= hii && hi >= loo) {
            if (a[lo] != b[hi]) {
                cout << "NO" << '\n'; return 0;
            }
            lo++; hi--;
        }
        cout << "YES\n";
    }

}