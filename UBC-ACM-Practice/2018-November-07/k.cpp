#include <iostream>

using namespace std;

const int N = 1005;
int n, a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = n; i >=0; i--) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += a[j] <= i && i <= b[j];
        }
        if (cnt == i) {
            cout << cnt << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

}