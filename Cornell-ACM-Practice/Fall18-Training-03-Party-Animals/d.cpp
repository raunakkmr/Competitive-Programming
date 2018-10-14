#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long double ld;

const int N = 18;

int n;
ld a[N][N];
ld memo[(1<<N)];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)  {
            cin >> a[i][j];
        }
    }

    memset(memo, 0, sizeof memo);
    memo[(1<<n)-1] = 1;
    for (int mask = (1<<n)-1; mask > 0; mask--) {
        int ones = __builtin_popcount(mask);
        for (int i = 0; i < n; i++) {
            if ((mask & (1<<i)) == 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j || (mask & (1<<j)) == 0) continue;
                memo[mask-(1<<j)] += memo[mask]*a[i][j] / (0.5*ones*(ones-1));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6) << memo[(1<<i)] << " ";
    }

}